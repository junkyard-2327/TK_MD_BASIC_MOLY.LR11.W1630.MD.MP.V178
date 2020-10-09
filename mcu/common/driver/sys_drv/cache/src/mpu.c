/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   cache.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the functional of ARM MPU
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/*******************************************************************************
 * Whole file is wrapped in following macros 
 *******************************************************************************/
#if defined(__CR4__)

/*******************************************************************************
 * Include header files.
 *******************************************************************************/
#include "kal_public_api.h"
#include "cp15.h"
#include "mpu.h"
#include "custom_scatstruct.h"
//#include "custom_EMI_release.h"     //For EMI_EXTSRAM_SIZE
#include "cache_sw_int.h"
#include "drv_pfb.h"
#if !defined(__FUE__) && !defined(__UBL__)
#include "mcu_pmu_montr.h"          // For ARM performance monitor
#include "bus_drv.h"
#include "intrCtrl.h"
#endif /* !__FUE__ && !__UBL__ */

#if defined(__HIF_CCCI_SUPPORT__)
#include "ccci_if.h"
#endif 
/*******************************************************************************
 * Define import functions and variables
 *******************************************************************************/

 /*******************************************************************************
 * Define global data.
 *******************************************************************************/
#if !defined(__FUE__) && !defined(__UBL__)
/* mpu_region_record: Record MPU region usage, 
 * mpu_region_record[x]==1 indicates region #x is in use */
static kal_uint32 mpu_region_record = 0;
#ifdef __PCORE__
static kal_uint32 TCMRO_REGNUM = 0;
#endif
#ifdef __L1CORE__
static kal_uint32 TCMRW_REGNUM = 0;
static kal_uint32 L2SRAM_RO_REGNUM = 0;
#endif
#if defined(__PCORE__)
static kal_uint32 CCCI_DEVICE_REGNUM = 0;
#endif

#ifdef __MTK_TARGET__
__attribute__ ((section("NONCACHEDZI"), zero_init))
#endif /* __MTK_TARGET__ */
MPU_DUMP ARM_MPU_SETTING;
#endif /* !__FUE__ && !__UBL__ */

DEFINE_NC_SHARED_VAR(volatile kal_uint32, CCIF_SHARE_MEM_BASE)
DEFINE_NC_SHARED_VAR(volatile kal_uint32, CCIF_SHARE_MEM_SIZE)

/* debug symbol to check share memory setting */
SHM_REGION share_memory_region[4];
SHM_REGION share_memory_region_for_memory_dump[4];

kal_uint32 shareRegionBase;
kal_uint32 shareRegionMaxAddress;

/*************************************************************************
* FUNCTION
*  mpu_set_region_primitive
*
* DESCRIPTION
*  This function setup one region to CP15 using primitive CP15 APIs
*
* NOTE
*  This function is designed for bootloader use
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  kal_uint32 index                     Region index
*  kal_uint32 addr                      Region base address
*  RGN_SIZE_TYPE region_size            Region size
*  REGION_ATTRIBUTE_TYPE attribute      Region attribute setting
*  kal_uint32 enable                    Enable this region: 0=>disable / Others=>enable
*
* RETURNS
*  None
*
*************************************************************************/
void mpu_set_region_primitive(kal_uint32 index, kal_uint32 addr, RGN_SIZE_TYPE region_size, REGION_ATTRIBUTE_TYPE attribute, kal_uint32 enable)
{
    kal_uint32 en;
    /* 
     * NOTE: Input Constraint
     * 1. index < MPU_REGION_NUM (for MT6280, TK6280 MAX region = 12 )
     * 2. addr aligned with size (ex: a 4KB region must start at 4KB aligned address)
     *
     */
    ASSERT(index < MPU_REGION_NUM);
    ASSERT((addr&((1<<(region_size+1))-1))==0);
    
    en = (enable==0)?0:1;
    
    /* Start configure MPU regions */
    cp15_mpu_set_rgn_index(index);
    cp15_mpu_set_rgn_addr(addr);
    cp15_mpu_set_rgn_size(region_size);    
    cp15_mpu_set_subregion_disable(DISABLE_SUB_NONE); //All sub regions enabled
    cp15_mpu_set_rgn_accctrl(attribute);
    cp15_mpu_set_rgn_enable(en); 
}

/*************************************************************************
* FUNCTION
*  mpu_clear_all_regions
*  -- Public
*
* DESCRIPTION
*  This function reset all region settings to zero
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
* RETURNS
*  None
*
*************************************************************************/
void mpu_clear_all_regions(void)
{
    kal_uint32 i;
    cp15_disable_mpu();
    
    for(i=0;i<MPU_REGION_NUM;i++)
    {
        mpu_set_region_primitive(i, 0, 0, 0, 0);
    }
    
    return;
}

#if !defined(__FUE__) && !defined(__UBL__)
/*************************************************************************
* FUNCTION
*  mpu_dump
*  -- Public
*
* DESCRIPTION
*  This function dump current ARM mpu settings
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  MPU_DUMP * mpu_dump_output       The buffer for mpu settings dump
*
* RETURNS
*  KAL_TRUE:  for success
*  KAL_FALSE: for failure  
*
*************************************************************************/
kal_bool mpu_dump(MPU_DUMP * mpu_dump_output)
{
    kal_uint32 i;
    volatile MPU_DUMP * internal_dump_ptr;
    
    internal_dump_ptr = (volatile MPU_DUMP *)mpu_dump_output;
    for(i=0;i<MPU_REGION_NUM;i++)
    {
        cp15_mpu_set_rgn_index(i);
        internal_dump_ptr->region[i].Region_Base_Address = cp15_mpu_get_rbar();  
        internal_dump_ptr->region[i].Region_Size_Enable = cp15_mpu_get_rser(); 
        internal_dump_ptr->region[i].Region_Access_Control = cp15_mpu_get_racr(); 
    }
    internal_dump_ptr->magic_pattern = MPU_DUMP_MAGIC;
    cp15_data_synchronization_barrier();
    return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*  mpu_setup_region
*  -- Private
*
* DESCRIPTION
*  This function setup one region by MPU_SETTING to CP15
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  REGION_SETTING_TYPE * region_setting       The region setting values
*
* RETURNS
*  KAL_TRUE:  for success
*  KAL_FALSE: for failure  
*
*************************************************************************/
static kal_bool mpu_setup_region(const REGION_SETTING_TYPE * region_setting)
{
    kal_uint32 interruptMask;
    /* use cp15 APIs to set target mpu region with the attribute defines in region_setting */
    /* Parameter Checking */
    if(region_setting->rgn_no >= MPU_REGION_NUM)
    {
        /* Incorrect region number */
        ASSERT(0);
    }
    if(region_setting->size > MPU_REGION_MAX_SIZE || region_setting->size < MPU_REGION_MIN_SIZE)
    {
        /* Incorrect region size */
        ASSERT(0);
    } 
    
    interruptMask = SaveAndSetIRQMask();
    /* Set into CP15 */
    cp15_mpu_set_rgn_index(region_setting->rgn_no);
    cp15_mpu_set_rgn_addr(region_setting->addr);
    cp15_mpu_set_rgn_size(region_setting->size);    
    cp15_mpu_set_subregion_disable(region_setting->disable_subregion);
    cp15_mpu_set_rgn_accctrl(region_setting->attribute);
    cp15_mpu_set_rgn_enable(region_setting->enable);    
    RestoreIRQMask(interruptMask);
    
    return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*  mpu_get_region
*  -- Public
*
* DESCRIPTION
*  This function get one region setting by region number
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  kal_uint32 region_idx                                   The region index
*  REGION_SETTING_TYPE * region_setting       The region setting values
*
* RETURNS
*  KAL_TRUE:  for success
*  KAL_FALSE: for failure  
*
*************************************************************************/
kal_bool mpu_get_region(kal_uint32 index, REGION_SETTING_TYPE * region_setting)
{
    kal_uint32 regionSizeEnable;
    
    /* use cp15 APIs to set target mpu region with the attribute defines in region_setting */
    /* Parameter Checking */
    if(index >= MPU_REGION_NUM)
    {
        /* Incorrect region number */
        ASSERT(0);
    }

    /* Set into CP15 */
    cp15_mpu_set_rgn_index(index);

    region_setting->addr = cp15_mpu_get_rbar();  
    region_setting->attribute = cp15_mpu_get_racr(); 

    regionSizeEnable = cp15_mpu_get_rser(); 
    region_setting->size = (regionSizeEnable & 0x3E) >> 1;
    region_setting->disable_subregion = (regionSizeEnable & 0xFF00) >> 8;
    region_setting->enable = regionSizeEnable & 0x1;
    
    return KAL_TRUE;
}


/*************************************************************************
* FUNCTION
*  mpu_get_free_region
*  -- Private
*
* DESCRIPTION
*  This function registers one mpu region for using
*  If run out of mpu regions, returns fail
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  kal_uint32 * region       The registered region number
*
* RETURNS
*  KAL_TRUE:  for success
*  KAL_FALSE: for failure  
*
*************************************************************************/
kal_bool mpu_get_free_region(kal_uint32 * region)
{
    kal_uint32 region_record;
    kal_uint32 interrupt;
    kal_uint32 i;
    /* Check global region record, try to find one free region */
    /* We choose the available lowest priority channel */
    interrupt = SaveAndSetIRQMask();
    region_record = mpu_region_record;
    for(i=0;i<MPU_REGION_NUM;i++)
    {
        if(region_record & 0x1)
        {
            region_record >>=1;
        }
        else
        {
            break;
        }
    }
    /* if no free region is available, returns fail */
    if(i>=MPU_REGION_NUM)
    {
        RestoreIRQMask(interrupt);
        return KAL_FALSE;
    }
    
    *region = i;
    mpu_region_record |= (0x1<<i);
    RestoreIRQMask(interrupt);
    return KAL_TRUE;
    
    
}

/*************************************************************************
* FUNCTION
*  mpu_make_region
*  -- Private
*
* DESCRIPTION
*  This function setup one region by definining the address, size, acctribute etc..
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  kal_uint32 base_addr                   Region base address, must align with size
*  RGN_SIZE_TYPE region_size              Region size
*  REGION_ATTRIBUTE_TYPE attribute        Region attribute
*  kal_uint32 disable_subregion           Disable subregion settings, only effective on region size >= 256B
*
* RETURNS
*  KAL_TRUE:  for success
*  KAL_FALSE: for failure  
*
*************************************************************************/
static kal_bool mpu_make_region(kal_uint32 base_addr, RGN_SIZE_TYPE region_size, REGION_ATTRIBUTE_TYPE attribute, kal_uint32 disable_subregion)
{
    REGION_SETTING_TYPE region_setting={0};
    kal_uint32 addr_mask;
    /* 1. Get one free channel */
    if(mpu_get_free_region(&(region_setting.rgn_no))!=KAL_TRUE)
    {
        /* get free region fail */
        ASSERT(0);
    }
    /* 2. Check base address align with size */
    addr_mask = (1 << (region_size + 1)) - 1;
    if(base_addr & addr_mask)
    {
        /* Base address does not align with region size */
        ASSERT(0);
    }
    /* 3. Prepare REGION_SETTING_TYPE by input parameters */
    region_setting.addr = base_addr;
    region_setting.size = region_size;
    region_setting.attribute = attribute;
    region_setting.disable_subregion = disable_subregion;
    region_setting.enable = 1;
    
    /* 4. Call mpu_setup_region to set in CP15 */
    return mpu_setup_region(&region_setting);
}

/*************************************************************************
* FUNCTION
*  mpu_reset_last_region
*  -- Private
*
* DESCRIPTION
*  This function free and reset last allocated region
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  NONE
*
* RETURNS
*  NONE
*
*************************************************************************/
#ifndef DISABLE_MPU_RO_PROTECT
//static void mpu_reset_last_region(void)
void mpu_reset_last_region(void)
{
    kal_uint32 i;
    kal_uint32 region_record=mpu_region_record;
    
    if(region_record==0)
    {
        return;  
    }
    else
    {
        for(i=0;i<MPU_REGION_NUM;i++)
        {
            if(region_record & 0x1)
            {
                region_record >>=1;
            }
            else
            {
                mpu_region_record &= ~((kal_uint32)(1<<(i-1)));
                break;
            }
        }
    }
    return;
}
#endif

/*************************************************************************
* FUNCTION
*  mpu_make_region
*  -- Private
*
* DESCRIPTION
*  This function setup one region by definining the address, size, acctribute etc..
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  kal_uint32 base_addr                   Region base address, must align with size
*  kal_uint32 length                      Region size
*  REGION_ATTRIBUTE_TYPE attribute        Region attribute
*  kal_uint32 mode                        0: find a region smaller/equal than target
*                                         else: find a region larger/equal than target
*
* RETURNS
*  kal_uint32: Final region upper-bound
*
*************************************************************************/
kal_uint32 mpu_auto_make_region(kal_uint32 base_addr, kal_uint32 length, REGION_ATTRIBUTE_TYPE attribute, kal_uint32 mode)
{
    kal_uint32 final_addr, final_len, final_dissub;
    kal_uint32 tail_dissub=0;
    kal_uint32 i,j,k;
    kal_uint32 real_limit = base_addr + length;
    kal_uint32 region_limit,temp_addr,region_diff,abs_len,sub_region_len,last_region_limit;

    /********************** 
     * mode 0 : Fit smaller
     * mode!=0: Fit larger
     **********************/
    if(real_limit <= base_addr){
		
        //If the calculated end address is smaller than start address,
        //means that the end address is wrapped from 0xFFFFFFFF to 0x00000000
        //The real end address is bound by 4GB address space
        //That is, end address should be set as 0xFFFFFFFF here
        real_limit = (unsigned int)0-1;
    }	

    /* Restriction: Base address must be aligned on 2^n(>128) */
    /* find suitable region start and length */
    region_diff = (unsigned int)0-1;
    final_len = 0;
    final_addr = 0;
    final_dissub = 0;
    abs_len = 0;
    //Start from 128Byte region, since smaller regions don't have subregion feature
    //And smaller regions have very little chance to be used
    for(k=RGN_SIZE_128B;k<=RGN_SIZE_4GB;k++)
    {    
        //i == region size
        i = 1<<(k+1);
        //Calculate the region start address
        //NOTE: always round DOWN at the start address side
        temp_addr = base_addr & ~(i-1);
        //Start with length == original region size
        if(i == 0)
        {
            //Overflow handling, if i == 0, then we are using 4GB region size, 
            //so set sub_region_len as 0x20000000
            sub_region_len = 0x20000000;
        }
        else
        {
            //Otherwise, the sub_region_len should be region size / 8
            sub_region_len = i >> 3;
        }
        for(j=0;j<8;j++)
        {
            //Try to use subregion to optimize the region size
            //Here we only disables subregion from the end
            
            //Locate current region end address by:
            //1. Current Region Start Address (Region size aligned)
            //2. Subregion disabled at the end
            region_limit = temp_addr + i - j*sub_region_len;
            if(region_limit <= temp_addr)
            {
                //If the calculated end address is smaller than start address,
                //means that the end address is wrapped from 0xFFFFFFFF to 0x00000000
                //The real end address is bound by 4GB address space
                //That is, end address should be set as 0xFFFFFFFF here
                region_limit = (unsigned int)(0-1);
            }
            
            if(mode==0 && region_limit <= real_limit)
            {
                //Mode 0: Fit target region with a smaller region
                //if current region end address is smaller than target end address
                //we compare the region size differences between current and previous regions
                //Choose the region which has a smallest size differences for final setting
                if(region_diff > real_limit - region_limit)
                {
                    region_diff = real_limit - region_limit;
                    tail_dissub = j;
                    final_addr = temp_addr;
                    final_len = k;
                    abs_len = i;
                }
                break;
            }
            else if(mode!=0 && region_limit < real_limit)
            {
                //Mode != 0: Fit target region with a larger region
                //if current region end address is smaller than target end address
                //then current region setting is too small,
                
                //If no sub-region is disabled now, then this region size is too small, break and try larget region size
                if(j==0)
                {
                    break;
                }
                else
                {
                    last_region_limit = temp_addr + i - (j-1)*sub_region_len;
                    if(region_diff > last_region_limit - real_limit)
                    {
                        region_diff = last_region_limit - real_limit;
                        tail_dissub = j-1;
                        final_addr = temp_addr;
                        final_len = k;
                        abs_len = i;
                    }                     
                }
            }
            else
            {
                //Here should be Mode==0, current region end address larger than target region end address
                //Continue to try disabling more subregions
                continue;
            }
        }
    }
    
    if(final_len == 0)
    {
        //MPU auto make failed
        //find not suitable region
        //Need to improve for multi-region coverage
        ASSERT(0);
    }
    
    //Overflow handling
    //if final_len != 0 and abs_len == 0
    //means that we are using a 4GB region
    if(abs_len == 0)
    {
        sub_region_len = 0x20000000;
    }
    else
    {
        sub_region_len = abs_len >> 3;
    }
    
    //Set subregion disable bit
    //disable from the end by previous calculated results
    final_dissub |= ((1<<tail_dissub) - 1) << (8 - tail_dissub);
    //Calculate subregion disable at the start by base address differences
    final_dissub |= (1<<((base_addr - final_addr) / sub_region_len))-1;
    //leave only 8 bit for final_dissub, since we have only 8 subregions
    final_dissub &= 0x000000FF;
    
    // Setup region
    mpu_make_region(final_addr, final_len, attribute, final_dissub);
    
    return (final_addr+abs_len)-(sub_region_len*tail_dissub);
}

void SET_ADT_TCM_REGION(kal_uint32 base_addr, kal_uint32 length)               
{   
    kal_uint32 savedMask;
    savedMask = SaveAndSetIRQMask();

#ifdef __PCORE__
    mpu_region_record &= ~(0x1<<TCMRO_REGNUM);

    if(length<32){
        Data_Sync_Barrier();
        //disable this region
        mpu_set_region_primitive(TCMRO_REGNUM, base_addr, RGN_SIZE_4KB,  MPU_NORMAL_INNC_OUTNC | MPU_PR_UR, 0);
        Inst_Sync_Barrier();
    }else{
        Data_Sync_Barrier();
        mpu_auto_make_region(base_addr, length, MPU_NORMAL_INNC_OUTNC | MPU_PR_UR, 0);
        Inst_Sync_Barrier();
    }
#endif

#ifdef __L1CORE__    
    mpu_region_record &= ~(0x1<<TCMRW_REGNUM);
    Data_Sync_Barrier();
    mpu_auto_make_region(base_addr, length, MPU_NORMAL_INNC_OUTNC | MPU_PRW_URW, 1);
    Inst_Sync_Barrier();
#endif
      
    RestoreIRQMask(savedMask);
}


#ifdef __L1CORE__
void SET_ADT_L2SRAM_REGION(kal_uint32 base_addr, kal_uint32 length)
{
    kal_uint32 savedMask;
    if(L2SRAM_RO_REGNUM!=0){
        savedMask = SaveAndSetIRQMask();
        mpu_region_record &= ~(0x1<<L2SRAM_RO_REGNUM);

        if(length<32){
            Data_Sync_Barrier();
            //disable this region
            mpu_set_region_primitive(L2SRAM_RO_REGNUM, base_addr, RGN_SIZE_4KB,  MPU_NORMAL_INWBWA_OUTWBWA | MPU_PR_UR, 0);
            Inst_Sync_Barrier();
        }else{
            Data_Sync_Barrier();
            mpu_auto_make_region(base_addr, length, MPU_NORMAL_INWBWA_OUTWBWA | MPU_PR_UR, 0);
            Inst_Sync_Barrier();
        }
        RestoreIRQMask(savedMask);
    }
    return;
}
#endif

/*************************************************************************
* FUNCTION
*  MpuPreInit
*  -- Public
*
* DESCRIPTION
*  This function used to pre-configure the MPU settings and enable I-Cache
*  for speed-up region init process
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
* RETURNS
*  None
*
*************************************************************************/
void MpuPreInit(void)
{	
#if defined(__MTK_TARGET__) && (defined(TK6291)|| defined(MT6755)|| defined(MT6797) || defined(MT6757)|| defined(MT6750S))
     bus_domain_setting();
#endif
     //Disable MPU first
     //NOTE: this code should be put in default executable memory region!!
     cp15_disable_mpu();
    
     //mpu_set_region_primitive(INDEX, START_ADDRESS, REGION_SIZE, ATTRIBUTE, ENABLE)
     /* We cannot use MPU functions since SaveAndSetIRQMask() is not initialized (actually we don't need it now) */
     /* Set 4GB Read/Write Cacheable Normal */
     //mpu_set_region_primitive(0, 0, RGN_SIZE_4GB, MPU_NORMAL_INWBWA_OUTWBWA|MPU_PRW_URW, 1);
     /* Set ATCM+BTCM Read/Write Non-cacheable Normal (CR4 support max 8MB ATCM) */
     //mpu_set_region_primitive(1, custom_get_INTSRAMCODE_Base(), RGN_SIZE_8MB, MPU_NORMAL_INNC_OUTNC|MPU_PRW_URW, 1);
    
     mpu_set_region_primitive(0, 0,          RGN_SIZE_256MB, MPU_SHARE|MPU_NORMAL_INNC_OUTNC|MPU_PRW_URW, 1);
     mpu_set_region_primitive(1, 0xA0000000, RGN_SIZE_256MB, MPU_NORMAL_INWBWA_OUTWBWA|MPU_PRW_URW, 1);
     mpu_set_region_primitive(2, 0x70000000, RGN_SIZE_512KB, MPU_NORMAL_INNC_OUTNC|MPU_PRW_URW, 1);
#ifdef __L1CORE__
     mpu_set_region_primitive(3, 0x75000000, RGN_SIZE_1MB, MPU_NORMAL_INNC_OUTNC|MPU_PRW_URW, 1);
#endif 
    // mpu_make_region(kal_uint32 base_addr, RGN_SIZE_TYPE region_size, REGION_ATTRIBUTE_TYPE attribute, kal_uint32 disable_subregion)
    
    
     //mpu_set_region_primitive(1, 0x400000, RGN_SIZE_4MB, MPU_NORMAL_INNC_OUTNC|MPU_PRW_URW, 1);
    
     /* Custom Region Framework (APB region should be included in here)*/

#if defined(__MTK_TARGET__)
#ifdef __L1CORE__
    #define Y_MPU_START_REGION_IDX  (4)
#else
    #define Y_MPU_START_REGION_IDX  (3)
#endif
    #define Y_MPU_MAX_REGION_IDX    (MPU_REGION_NUM-1)
    {
        kal_uint32 curr_region=(Y_MPU_START_REGION_IDX);
        #define X_MPU_PREINIT_REGION(name, base, size, attr, en) 1+
        #define X_MPU_INIT_REGION(name, base, size, attr, fit)
        #define X_MPU_INIT_REGION_EX(name, base, size, attr, fit)
        // Compile time check max region number
        // If compile error at "dummy_var_for_check", review the custom region header setting!!
        kal_uint32 __attribute__((unused))dummy_var_for_check[Y_MPU_MAX_REGION_IDX-Y_MPU_START_REGION_IDX+1-(
        #include "mpu_custom_region.h"
        0)];
        #undef X_MPU_PREINIT_REGION
        #define X_MPU_PREINIT_REGION(name, base, size, attr, en) mpu_set_region_primitive(curr_region++, base, size, attr, en);
        #include "mpu_custom_region.h"
        #undef X_MPU_PREINIT_REGION
        #undef X_MPU_INIT_REGION
        #undef X_MPU_INIT_REGION_EX
    }
    #undef Y_MPU_START_REGION_IDX
    #undef Y_MPU_MAX_REGION_IDX
#endif //__MTK_TARGET__
    
    /* Enable MPU */
    //Disable I/D Cach first as TRM described
    if(cp15_is_dcache_enabled())
    {
        cp15_clean_dcache();
        cp15_invalidate_dcache();
        cp15_disable_dcache();
        
    }
    if(cp15_is_icache_enabled())
    {
        cp15_invalidate_icache();
        cp15_disable_icache();
    }
    
    //Enable MPU
    cp15_enable_mpu();

    /* Enable I-Cache */
    cp15_enable_icache();

    return;
}

/*************************************************************************
* FUNCTION
*  Mpu_Init
*  -- Public
*
* DESCRIPTION
*  This function sets the MPU to final version
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
* RETURNS
*  None
*
*************************************************************************/
void MPU_Init(void)
{

#if !defined(__TCM_ONLY_LOAD__)
#ifdef __PCORE__
        kal_uint32 INTSRAM_Code_Base = custom_get_INTSRAMCODE_Base();
        kal_uint32 RAM_Limit = custom_get_MD_RAMEnd() ;        //for R/W
        kal_uint32 ROM_Length =	custom_get_DNC_SharedMem_Base();    //for RO
        kal_uint32 INTSRAM_Code_Length = custom_get_INTSRAMCODE_End() - INTSRAM_Code_Base;
        kal_uint32 INTSRAM_Length = custom_get_INTSRAMDATA_End() - INTSRAM_Code_Base;
#endif
#ifdef __L1CORE__
        kal_uint32 INTSRAM_DATA_Base = custom_get_INTSRAMDATA_Base();
        kal_uint32 INTSRAM_DATA_Length= custom_get_INTSRAMDATA_End() - INTSRAM_DATA_Base;
        kal_uint32 RAM_Limit = custom_get_DSPTXRX_Base() + custom_get_DSPTXRX_MaxSize(); //for R/W
        kal_uint32 ROM_Length = MAP2CREGPA(custom_get_1st_ROM_RAMBase());       //for RO
        kal_uint32 L2SRAM_Base = custom_get_L2SRAMCODE_Base();
        kal_uint32 L2SRAM_Length = custom_get_L2SRAM_LENGTH();    
        kal_uint32 L2SRAM_CODE_Length = custom_get_L2SRAMDATA_Base() - L2SRAM_Base;        
#ifndef DISABLE_MPU_RO_PROTECT
        kal_uint32 RAM_Base = custom_get_1st_ROM_RAMBase();
        kal_uint32 region_limit;
        kal_uint32 ROM_Protect_Region_Mode;
#endif
#endif
#endif /* __TCM_ONLY_LOAD__ */
    //Disable MPU first
    //NOTE: this code should be put in default executable memory region!!
    cp15_disable_mpu();
    // clear all mpu regions (make them back to all zero)
    mpu_clear_all_regions();

#if defined(__MTK_TARGET__)
    #define Y_MPU_START_REGION_IDX  0
    #define Y_MPU_MAX_REGION_IDX    (MPU_REGION_NUM-1)
    {
        #define X_MPU_INIT_REGION(name, base, size, attr, fit) 1+
        #define X_MPU_INIT_REGION_EX(name, base, size, attr, sub) 1+
        #define X_MPU_PREINIT_REGION(name, base, size, attr, en)
        kal_uint32 __attribute__((unused))dummy_var_for_check[Y_MPU_MAX_REGION_IDX-Y_MPU_START_REGION_IDX+1-(
        #include "mpu_custom_region.h"
        0)];
        #undef X_MPU_INIT_REGION
        #undef X_MPU_INIT_REGION_EX
        #undef X_MPU_PREINIT_REGION
        #define X_MPU_PREINIT_REGION(name, base, size, attr, en)
        #define X_MPU_INIT_REGION_EX(name, base, size, attr, sub) mpu_make_region(base, size, attr, sub); 
        #define X_MPU_INIT_REGION(name, base, size, attr, fit) mpu_auto_make_region(base, size, attr, fit); 
        #include "mpu_custom_region.h"
        #undef X_MPU_PREINIT_REGION
        #undef X_MPU_INIT_REGION
    }
    #undef Y_MPU_START_REGION_IDX
    #undef Y_MPU_MAX_REGION_IDX
#endif //__MTK_TARGET__

#if !defined(__TCM_ONLY_LOAD__)
    /*64MB Normal NC RW XN*/
mpu_auto_make_region(0x0       , RAM_Limit , MPU_XN | MPU_NORMAL_INNC_OUTNC | MPU_SHARE | MPU_PRW_URW, 1);
    /*64MB Normal C RW XN*/
mpu_auto_make_region(0xA0000000, RAM_Limit , MPU_XN | MPU_NORMAL_INWBWA_OUTWBWA | MPU_PRW_URW, 1);

//////////////////////////////
#ifdef __PCORE__
    mpu_auto_make_region(0x0,ROM_Length, MPU_NORMAL_INWBWA_OUTWBWA | MPU_PR_UR, 0);
    mpu_auto_make_region(MAP2CREGVA(0x0), ROM_Length, MPU_XN | MPU_NORMAL_INWBWA_OUTWBWA | MPU_PR_UR, 0);
    /* TCM RW*/
    mpu_auto_make_region(INTSRAM_Code_Base, INTSRAM_Length, MPU_NORMAL_INNC_OUTNC | MPU_PRW_URW, 1);
    
    /* Set TCM region protect RO try fit smaller or equal**/
    mpu_auto_make_region(INTSRAM_Code_Base, INTSRAM_Code_Length, MPU_NORMAL_INNC_OUTNC | MPU_PR_UR, 0);
    TCMRO_REGNUM = 7;
#endif

#ifdef __L1CORE__
#ifndef DISABLE_MPU_RO_PROTECT
        /* Set ROM + RO Region */
        ROM_Protect_Region_Mode=1;
        region_limit = mpu_auto_make_region(0x0,ROM_Length, MPU_NORMAL_INWBWA_OUTWBWA | MPU_PR_UR, ROM_Protect_Region_Mode);
      if(region_limit > RAM_Base)
        {
           // ROM Protection over RW region, try fit smaller
           ROM_Protect_Region_Mode=0;
           mpu_reset_last_region();
           region_limit = mpu_auto_make_region(0x0, ROM_Length, MPU_NORMAL_INWBWA_OUTWBWA | MPU_PR_UR, ROM_Protect_Region_Mode);
           ASSERT(region_limit <= RAM_Base);
        }
         /* Set 0xF ROM region as RO */  
        mpu_auto_make_region(MAP2CREGVA(0x0), ROM_Length, MPU_XN | MPU_NORMAL_INWBWA_OUTWBWA | MPU_PR_UR, ROM_Protect_Region_Mode);
#endif /* ifndef DISABLE_MPU_RO_PROTECT */
    mpu_auto_make_region(INTSRAM_DATA_Base, INTSRAM_DATA_Length, MPU_NORMAL_INNC_OUTNC | MPU_PRW_URW, 1);
    TCMRW_REGNUM = 6;
    if(L2SRAM_Length)
        mpu_auto_make_region(L2SRAM_Base, L2SRAM_Length, MPU_NORMAL_INWBWA_OUTWBWA | MPU_PRW_URW, 1);
    if(L2SRAM_CODE_Length){
        mpu_auto_make_region(L2SRAM_Base, L2SRAM_CODE_Length, MPU_NORMAL_INWBWA_OUTWBWA | MPU_PR_UR, 0);
        L2SRAM_RO_REGNUM = 8;
    }
#endif
#else /*__TCM_ONLY_LOAD__ */
    /* TCM RW*/
    mpu_auto_make_region(0x0, custom_get_INTSRAM_End(), MPU_NORMAL_INNC_OUTNC | MPU_PRW_URW, 1);
    
    /* Set TCM region protect RO try fit smaller or equal**/
    mpu_auto_make_region(0x0, custom_get_INTSRAMCODE_End(), MPU_NORMAL_INNC_OUTNC | MPU_PR_UR, 0);
#endif

    /* enable background region setting */
    cp15_mpu_set_bg_region_enable();

    //Enable Cache, MPU
    if(cp15_is_dcache_enabled())
    {
        cp15_clean_dcache();
        cp15_invalidate_dcache();
        cp15_disable_dcache();
        
    }
    if(cp15_is_icache_enabled())
    {
        cp15_invalidate_icache();
        cp15_disable_icache();
    }
    cp15_enable_mpu();
    /* Enable I/D Cache */
    cp15_enable_icache();
    cp15_enable_dcache();
    
    /* Enable Instruction Prefetch Buffer */
    enablePrefetchBuffer();
    /* Enable Alignment fault */
    cp15_enable_alignment_fault();
    /* Disable Low interrupt latency on Load/Store Multiple */
    cp15_disable_LIL_STLDM();
    /* Enable undefine exception for Divide by Zero */
    cp15_enable_undef_div_by_zero();
    
    /* Strat ARM PMU Cycle Counter */
    MCU_PMU_Initialize();
    MCU_PMU_StartCounter(PMU_CYCLE_COUNTER);

#if defined(EMI_MPU_ENABLE)
    {
        EMI_MPU_Unlock();
        EMI_MPU_Clear_Status();
        //Use the last EMI MPU region to do code protect
        EMI_MPU_Set_Region_APC(EMI_MPU_REGION_CP, 0, EMI_MPU_SR_NSR);
        EMI_MPU_Set_Region_APC(EMI_MPU_REGION_CP, 1, EMI_MPU_SR_NSR);
        EMI_MPU_Set_Region_APC(EMI_MPU_REGION_CP, 2, EMI_MPU_SR_NSR);
        EMI_MPU_Set_Region_APC(EMI_MPU_REGION_CP, 3, EMI_MPU_SR_NSR);
        EMI_MPU_Set_Region_APC(EMI_MPU_REGION_CP, 4, EMI_MPU_SR_NSR);
        EMI_MPU_Set_Region_APC(EMI_MPU_REGION_CP, 5, EMI_MPU_SR_NSR);
        EMI_MPU_Set_Region_Address(EMI_MPU_REGION_CP, ROM_Base, ROM_Base+ROM_Length);
        EMI_MPU_Lock();
    }
#endif /* EMI_MPU_ENABLE */

    /* Dump final MPU settings for debug */
    mpu_dump(&ARM_MPU_SETTING);

#if defined(__PCORE__) && defined(__MTK_TARGET__)
    volatile kal_uint32 dummy_ref;
    volatile kal_uint32 dummy_ref1;
    dummy_ref = (kal_uint32) SHARED_pVAR(CCIF_SHARE_MEM_BASE);
    dummy_ref1 = (kal_uint32) SHARED_pVAR(CCIF_SHARE_MEM_SIZE);
    (void)dummy_ref;
    (void)dummy_ref1;
#endif
    
    return;
}

kal_bool share_memory_device_type_set = KAL_FALSE;
void ccif_set_share_mem_mpu(kal_uint32 base_addr, kal_uint32 size)
{
    /* This MPU setting API should only be called once. */
    if( share_memory_device_type_set == KAL_TRUE )
        return;
    else
        share_memory_device_type_set = KAL_TRUE;
#if defined(__PCORE__) 
    SHARED_VAR(CCIF_SHARE_MEM_BASE) = base_addr;                        
    SHARED_VAR(CCIF_SHARE_MEM_SIZE) = size;                             
#endif
    if( (kal_uint32*)base_addr != NULL && size != 0){
        mpu_auto_make_region( base_addr, size, (MPU_PRW_URW | MPU_XN | MPU_DEVICE_INS_OUTDEV), 1);
        share_memory_region_for_memory_dump[0].shm_base = base_addr;
        share_memory_region_for_memory_dump[0].shm_size = size;
    }
#if defined(__PCORE__)
    CCCI_DEVICE_REGNUM = 8;
#endif  
    return;
}

#if defined(__PCORE__) 
kal_bool share_memory_cacheable_set = KAL_FALSE;
void ccif_set_share_mem_mpu_cacheable_region(kal_uint32 base_addr, kal_uint32 size)
{
    /* This MPU setting API should only be called once. */
    if( share_memory_cacheable_set == KAL_TRUE )
        return;
    else
        share_memory_cacheable_set = KAL_TRUE;
    /* check if the parameter is valid */
    if( (kal_uint32*)base_addr != NULL && size != 0){
        /* If the cacheable region start address is the same as device type region, 
           it means the device type region is overlapped with cacheable region(smaller). 
           We need to reset MPU region. */
        if( base_addr == SHARED_VAR(CCIF_SHARE_MEM_BASE)){
            mpu_region_record &= ~(0x1 << CCCI_DEVICE_REGNUM);
            /* Becasue the larger region unmber has higher priority, we need to set cacheable first.
               Then, set device type next to make the overlap region use device type. */
            mpu_auto_make_region( base_addr, size, MPU_NORMAL_INWBWA_OUTWBWA | MPU_PRW_URW | MPU_XN, 0);
            mpu_auto_make_region( SHARED_VAR(CCIF_SHARE_MEM_BASE) + size, SHARED_VAR(CCIF_SHARE_MEM_SIZE) - size, (MPU_PRW_URW | MPU_XN | MPU_DEVICE_INS_OUTDEV), 1);
            share_memory_region_for_memory_dump[0].shm_base = SHARED_VAR(CCIF_SHARE_MEM_BASE) + size;
            share_memory_region_for_memory_dump[0].shm_size = SHARED_VAR(CCIF_SHARE_MEM_SIZE) - size;
            CCCI_DEVICE_REGNUM = 9;
        }
        else
            mpu_auto_make_region( base_addr, size, MPU_NORMAL_INWBWA_OUTWBWA | MPU_PRW_URW | MPU_XN, 0);
        share_memory_region_for_memory_dump[1].shm_base = base_addr;
        share_memory_region_for_memory_dump[1].shm_size = size;
    }
}
#endif

void system_set_share_mem(SHM_REGION shm_region[])
{
    /* Skip set CCCI device type region because they will set by themselves. */
#if defined(__PCORE__)
    kal_uint32 subRegionSize, subRegionCount;
    kal_uint32 regionSize = 0;
    kal_bool sizeCheckPass;
    kal_uint32 size,base_addr;
    base_addr = shm_region[0].shm_base;
    size      = shm_region[0].shm_size;
    share_memory_region[0].shm_base = shm_region[0].shm_base;
    share_memory_region[0].shm_size = shm_region[0].shm_size;
    if((shm_region[0].shm_base != 0) && (shm_region[0].shm_size!= 0))
    {    

      /* check size(should be 2^x / 8 *y) and alignment(start address align to size) */
      sizeCheckPass = KAL_FALSE;
      for( subRegionSize = 32; subRegionSize <= 512 * 1024 * 1024; subRegionSize = subRegionSize << 1){
          for( subRegionCount = 1; subRegionCount <= 8; subRegionCount++){
              if( size == subRegionSize * subRegionCount ){
                  sizeCheckPass = KAL_TRUE;
                  regionSize = subRegionSize * 8;
                  goto Check_Alignment;
              }
          }
      }
Check_Alignment:      
      EXT_ASSERT( sizeCheckPass == KAL_TRUE, 0, base_addr, size);
      EXT_ASSERT( (base_addr % regionSize) == 0, 0, base_addr, size);
      
      ccif_set_share_mem_mpu (shm_region[0].shm_base, shm_region[0].shm_size);
    }
    base_addr = shm_region[1].shm_base;
    size      = shm_region[1].shm_size;
    share_memory_region[1].shm_base = shm_region[1].shm_base;
    share_memory_region[1].shm_size = shm_region[1].shm_size;
    if((shm_region[1].shm_base != 0) && (shm_region[1].shm_size != 0))
    {    
      /* check size(should be 2^x / 8 *y) and alignment(start address align to size) */
      sizeCheckPass = KAL_FALSE;
      for( subRegionSize = 32; subRegionSize <= 512 * 1024 * 1024; subRegionSize = subRegionSize << 1){
          for( subRegionCount = 1; subRegionCount <= 8; subRegionCount++){
              if( size == subRegionSize * subRegionCount ){
                  sizeCheckPass = KAL_TRUE;
                  regionSize = subRegionSize * 8;
                  goto Check_Cacheable_Alignment;
              }
          }
      }
Check_Cacheable_Alignment:      
      EXT_ASSERT( sizeCheckPass == KAL_TRUE, 0, base_addr, size);
      EXT_ASSERT( (base_addr % regionSize) == 0, 0, base_addr, size);

      ccif_set_share_mem_mpu_cacheable_region(shm_region[1].shm_base, shm_region[1].shm_size);
    }
    /* Caculate the start address and size for L1core because CCCI doesn't bring this information to L1core */
    if((shm_region[0].shm_base != 0) && (shm_region[0].shm_size!= 0))
    {    

        if((shm_region[1].shm_base != 0) && (shm_region[1].shm_size != 0))
        {    
            /* If there are two share region, try to cover the maximum range */
			kal_uint32 shareRegion0MaxAddress = shm_region[0].shm_base + shm_region[0].shm_size;
			kal_uint32 shareRegion1MaxAddress = shm_region[1].shm_base + shm_region[1].shm_size;
			if( shareRegion0MaxAddress > shareRegion1MaxAddress){
				shareRegionMaxAddress = shareRegion0MaxAddress;
			}
			else{
				shareRegionMaxAddress = shareRegion1MaxAddress;
			}

			if( shm_region[0].shm_base < shm_region[1].shm_base){
				shareRegionBase = shm_region[0].shm_base;
			}
			else{
				shareRegionBase = shm_region[1].shm_base;
			}
		    //ccif_set_share_mem_mpu (shareRegionBase, shareRegionMaxAddress - shareRegionBase);
            /* Assign these value because L1core just use ccif_set_share_mem_mpu by these two variable */
            SHARED_VAR(CCIF_SHARE_MEM_BASE) = shareRegionBase;                        
            SHARED_VAR(CCIF_SHARE_MEM_SIZE) = shareRegionMaxAddress - shareRegionBase;                             
        }
        else{
            /* If there is only one share region, just cover it */
            //ccif_set_share_mem_mpu (shm_region[0].shm_base, shm_region[0].shm_size);
            /* Assign these value because L1core just use ccif_set_share_mem_mpu by these two variable */
            SHARED_VAR(CCIF_SHARE_MEM_BASE) = shm_region[0].shm_base;                        
            SHARED_VAR(CCIF_SHARE_MEM_SIZE) = shm_region[0].shm_size;                             
        }
    }
    else if((shm_region[1].shm_base != 0) && (shm_region[1].shm_size != 0))
    {    
        /* If there is only one share region, just cover it */
        //ccif_set_share_mem_mpu(shm_region[1].shm_base, shm_region[1].shm_size);
        /* Assign these value because L1core just use ccif_set_share_mem_mpu by these two variable */
        SHARED_VAR(CCIF_SHARE_MEM_BASE) = shm_region[1].shm_base;                        
        SHARED_VAR(CCIF_SHARE_MEM_SIZE) = shm_region[1].shm_size;                             
    }
#endif
}


//set TCM backdor and L2SRAM on Pcore
void exception_set_mpu(void)
{
#if 1
#if defined(__PCORE__)

    //kal_uint32 l2sram_length = custom_get_L1CORE_L2SRAMDATAZI_End() - custom_get_L1CORE_L2SRAMCODE_Base();
    kal_uint32 savedMask;
    savedMask = SaveAndSetIRQMask();
    
    Data_Sync_Barrier();
    SET_TCM_BACKDOR_REGION(MPU_REGION_SP_KERNEL, custom_get_INTSRAMCODE_Base());   
    Inst_Sync_Barrier();  
   
    //mpu_region_record &= ~(0x1<<MPU_REGION_SP_USER);
    Data_Sync_Barrier();
    mpu_set_region_primitive(MPU_REGION_SP_USER, 0x75000000,RGN_SIZE_1MB, (MPU_PR_UR|MPU_NORMAL_INWBWA_OUTWBWA),1);   
    Inst_Sync_Barrier();  

    RestoreIRQMask(savedMask);
#endif
#endif
    return;
}
/*************************************************************************
* FUNCTION
*  EMI_MPU_Vio_Get_Info
*  -- Public
*
* DESCRIPTION
*  This function sets the MPU to final version
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
* RETURNS
*  None
*
*************************************************************************/
void EMI_MPU_Vio_Get_Info(EMI_MPU_VIO_INFO* emi_mpu_vio_info)
{
#if defined(EMI_MPU_MD_Debug)
#if defined(__HIF_CCCI_SUPPORT__)
	CCCI_RUNTIME_SHARE_MEMORY_FORMAT_T md_boot_addr;
	CCCI_RUNTIME_FEATURE_SUPPORT_T  rtn;
	rtn = ccci_runtime_data_query(AP_CCCI_RUNTIME_MD_IMG_INFO, &md_boot_addr, sizeof(CCCI_RUNTIME_SHARE_MEMORY_FORMAT_T));
	if(rtn.support_mask == CCCI_RUNTIME_FEATURE_MUST_SUPPORT){
      	  if( *EMIMPU_VIO_ADDR > md_boot_addr.addr ){
#ifdef __PCORE__
 	      emi_mpu_vio_info->status = *EMIMPU_VIO_STATUS;
          emi_mpu_vio_info->address = *EMIMPU_VIO_ADDR - md_boot_addr.addr; //Pcore save MD view violation addr
#endif
	      }
#ifdef __L1CORE__
	  emi_mpu_vio_info->status =  md_boot_addr.addr;		   //L1core status: save MD boot addr
      emi_mpu_vio_info->address = *EMIMPU_VIO_ADDR;            //L1core addr: save AP view violation addr
#endif
	}else{
	  emi_mpu_vio_info->status = *EMIMPU_VIO_STATUS;
      emi_mpu_vio_info->address = *EMIMPU_VIO_ADDR;
    }
#else
	emi_mpu_vio_info->status = *EMIMPU_VIO_STATUS;
    emi_mpu_vio_info->address = *EMIMPU_VIO_ADDR;
#endif
#else
#if defined(__HIF_CCCI_SUPPORT__)
	CCCI_RUNTIME_SHARE_MEMORY_FORMAT_T md_boot_addr;
	CCCI_RUNTIME_FEATURE_SUPPORT_T  rtn;
	rtn = ccci_runtime_data_query(AP_CCCI_RUNTIME_MD_IMG_INFO, &md_boot_addr, sizeof(CCCI_RUNTIME_SHARE_MEMORY_FORMAT_T));
	if(rtn.support_mask == CCCI_RUNTIME_FEATURE_MUST_SUPPORT){	
        emi_mpu_vio_info->address = md_boot_addr.addr;
	}
#endif
#endif
 return;

}

void bus_domain_setting(void)
{
    
        (*(volatile kal_uint32 *)(MD_L1_BUS_AXIDOMAIN_CON1)) = (kal_uint32)(0xFFFFFFFF);
        (*(volatile kal_uint32 *)(MD_L1_BUS_AXIDOMAIN_CON2)) = (kal_uint32)(0xFFFFFFFF);
        (*(volatile kal_uint32 *)(MDL1MCU_GDMA_AXIDOMAIN))  = 0x1;
        (*(volatile kal_uint32 *)(MDL1MCU_GDMA_AXIDOMAIN))  = 0x81;

#ifdef __PCORE__
        (*(volatile kal_uint32 *)(P_BUS_AXIDOMAIN)) = (kal_uint32)(0x00777771);
#endif
        return;
}

void system_query_noncacheable_shm_info(kal_uint32 *start_addr, kal_uint32 *end_addr , kal_uint32 *size)
{
    *start_addr = share_memory_region_for_memory_dump[0].shm_base;
    *end_addr   = share_memory_region_for_memory_dump[0].shm_base + share_memory_region_for_memory_dump[0].shm_size;
    *size       = share_memory_region_for_memory_dump[0].shm_size;
}

void system_query_cacheable_shm_info(kal_uint32 *start_addr, kal_uint32 *end_addr , kal_uint32 *size)
{
    *start_addr = share_memory_region_for_memory_dump[1].shm_base;
    *end_addr   = share_memory_region_for_memory_dump[1].shm_base + share_memory_region_for_memory_dump[1].shm_size;
    *size       = share_memory_region_for_memory_dump[1].shm_size;
}


#endif /* !defined(__FUE__) && !defined(__UBL__) */

/*******************************************************************************
 * Whole file wrapper END
 *******************************************************************************/
#endif
