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
 *   This Module defines the functionality of Code and Data cache.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/********************************************************************************************
 * README
 * Test platform after revision
 * [1] NOR Flash boot without remap , MT6229_EVB
 * [2] NAND Flash boot , MT6228_EVB
 * [3] NOR Flash boot with remap , MT6225 + Single Bank NOR Flash , for example CRYSTAL25 V3 SB
 ********************************************************************************************/

/*******************************************************************************
 * DRIVER Note
 *
 * [2012/01/16] Cache driver type major compile options: __ARM9_MMU__/__ARM11_MMU__/__MTK_MMU__/__CR4__ (Only one will be enabled at a time)
 *     [1] ARM9 MMU: for ARM9 platforms
 *     [2] ARM11 MMU: for ARM11 platforms
 *     [3] MTK_MMU: form ARM7 platforms, driving MTK designed cache hardware (cahce/TCM/remapping/MPU)
 *     [4] CR4: for CR4 platforms, driving ARM caches and MTK address remapping mechanism
 *******************************************************************************/

/*******************************************************************************
 * Include header files.
 *******************************************************************************/
#include "cache_drv_region.h"
#include "cache_hw_int.h"
#include "cache_sw_int.h"
#include "cache_sw.h"
#include "init.h"
#include "cp15.h"
#include "mmu.h"
#include "mmu_int.h"
#include "custom_scatstruct.h"
#include "system_trc.h"
#include "init_trc_api.h"
#include "kal_trace.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "drv_comm.h"
#include "config_hw.h"
#include "mpu.h"
#include "cache_dbg.h"

#ifdef __CACHE_DEBUG_EN__
SEC_INTSRAM_DATA_ZI CACHE_LOG_T g_cache_inv_log[CACHE_DBG_LOG_MAX];
SEC_INTSRAM_DATA_ZI CACHE_LOG_T g_cache_cln_log[CACHE_DBG_LOG_MAX];
SEC_INTSRAM_DATA_ZI CACHE_LOG_T g_cache_cln_inv_log[CACHE_DBG_LOG_MAX];
SEC_INTSRAM_DATA_ZI kal_uint32 g_cache_inv_log_idx = 0;
SEC_INTSRAM_DATA_ZI kal_uint32 g_cache_cln_log_idx = 0;
SEC_INTSRAM_DATA_ZI kal_uint32 g_cache_cln_inv_log_idx = 0;
#endif /*__CACHE_DEBUG_EN__*/

#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__) || (__CR4__)
extern unsigned int cache_line_nr;
extern unsigned int cache_line_nr_per_way;
#endif /* __ARM9_MMU__ || __ARM11_MMU__ || __CR4__ */

extern kal_uint32 query_opposite_switchable_cacheaddr_ram(kal_uint32 addr);

/*******************************************************************************
 * Define import functions.
 *******************************************************************************/

extern void RestoreIRQMask(kal_uint32 ret);
extern kal_uint32 SaveAndSetIRQMask(void);
extern kal_uint32 custom_get_NORFLASH_ROMSpace(void);
extern kal_int32 query_is_l1cache_cacheable(kal_uint32 addr, kal_uint32 len, kal_uint32 query_ram);

#if defined(__MTK_TARGET__) 
/*******************************************************************************
 * Define global data.
 *******************************************************************************/

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
kal_int32 invalidate_icache(kal_uint32 addr, kal_uint32 len)
{
    /*
     * NoteXXX: Each cache line in ARM9/ARM11 ICache is 32B. Every invalidate operation
     *          must aligned in a 32B address.
     *
     */

    if (addr & CPU_CACHE_LINE_SIZE_MASK)
    {
        ASSERT(0);
    }
    else if (len & CPU_CACHE_LINE_SIZE_MASK)
    {
        ASSERT(0);
    }
    else
    {
        cp15_invalidate_icache_region(addr, len / CPU_CACHE_LINE_SIZE);
    }

    return 0;
}
#endif /* __DYNAMIC_SWITCH_CACHEABILITY__ */

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
INVALIDATE_DCACHE_PLACEMENT
kal_int32 invalidate_dcache(kal_uint32 addr, kal_uint32 len)
{ 
    /*
     * NoteXXX: Each cache line in ARM9 DCache is 32B. Every invalidate operation
     *          must aligned in a 32B address.
     *
     */
    CACHE_DBG_LOG_ENQUEUE(CACHE_INV_LOG, CACHE_INV_LOG_IDX, addr, len);

    if ((addr & CPU_CACHE_LINE_SIZE_MASK) ||
        (len & CPU_CACHE_LINE_SIZE_MASK))
    {
        EXT_ASSERT(0, addr, len, 0);
    }
    else
    {
        /* ARM Cache Operation */
        kal_uint32 operate_line_nr;
        operate_line_nr=len / CPU_CACHE_LINE_SIZE;
        
        /* 
         * If operating length larger than cache size,
         * We will do a full cache clean+invalidate to improve the responsiveness
         * Note that we will do this no matter it is a MMv2 buffer or not
         */
        if(operate_line_nr>cache_line_nr)
        {
            cp15_clean_and_invalidate_all_dcache_by_setway();
            return 0;
        }
        cp15_invalidate_dcache_region(addr, len / CPU_CACHE_LINE_SIZE);
    }

    return 0;
}
#endif /* __DYNAMIC_SWITCH_CACHEABILITY__ */

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
CLEAN_DCACHE_PLACEMENT
kal_int32 clean_dcache(kal_uint32 addr, kal_uint32 len)
{
    /*
     * NoteXXX: Each cache line in ARM9 DCache is 32B. Every invalidate operation
     *          must aligned in a 32B address.
     *
     */
    CACHE_DBG_LOG_ENQUEUE(CACHE_CLN_LOG, CACHE_CLN_LOG_IDX, addr, len);

    if ((addr & CPU_CACHE_LINE_SIZE_MASK) ||
        (len & CPU_CACHE_LINE_SIZE_MASK))
    {
        EXT_ASSERT(0, addr, len, 0);
    }
    else
    {
        kal_uint32 operate_line_nr;
        operate_line_nr=len / CPU_CACHE_LINE_SIZE;
        /* 
         * If operating length larger than cache size,
         * We will do a full cache clean to improve the responsiveness
         * Note that we will do this no matter it is a MMv2 buffer or not
         */
        if(operate_line_nr>cache_line_nr)
        {
            cp15_clean_all_dcache_by_setway();
            cp15_drain_write_buffer();
            return 0;
        }
        cp15_clean_dcache_region(addr, len / CPU_CACHE_LINE_SIZE);
        cp15_drain_write_buffer();
    }
    return 0;
}
#endif  /* __DYNAMIC_SWITCH_CACHEABILITY__ */

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
CLEAN_AND_INVALIDATE_DCACHE_REGION_PLACEMENT
kal_int32 clean_and_invalidate_dcache(kal_uint32 addr, kal_uint32 len)
{
    /*
     * NoteXXX: Each cache line in ARM9 DCache is 32B. Every invalidate operation
     *          must aligned in a 32B address.
     *
     */
    CACHE_DBG_LOG_ENQUEUE(CACHE_CLN_INV_LOG, CACHE_CLN_INV_LOG_IDX, addr, len);

    if ((addr & CPU_CACHE_LINE_SIZE_MASK) ||
        (len & CPU_CACHE_LINE_SIZE_MASK))
    {
        EXT_ASSERT(0, addr, len, 0);
    }
    else
    {
        kal_uint32 operate_line_nr;
        operate_line_nr=len / CPU_CACHE_LINE_SIZE;
        /* 
         * If operating length larger than cache size,
         * We will do a full cache clean+invalidate to improve the responsiveness
         * Note that we will do this no matter it is a MMv2 buffer or not
         */
        if(operate_line_nr>cache_line_nr)
        {
            cp15_clean_and_invalidate_all_dcache_by_setway();
            cp15_drain_write_buffer();
            return 0;
        }
        cp15_clean_and_invalidate_dcache_region(addr, len / CPU_CACHE_LINE_SIZE);
        cp15_drain_write_buffer();
    }
    return 0;
}
#endif  /* __DYNAMIC_SWITCH_CACHEABILITY__ */

/*************************************************************************
* FUNCTION
*  is_predef_dyna_c_region
*
* DESCRIPTION
*  This is used to determine whether the input region is a predefined dynamic switchable buffer.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
*
* RETURNS
*  0
*
*************************************************************************/

#if !defined(__FUE__) && !defined(__UBL__)
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
IS_PREDEF_DYNA_C_REGION_PLACEMENT
kal_uint32 is_predef_dyna_c_region(kal_uint32 vaddr, kal_uint32 len)
{
    kal_uint32 ret = 0;

    EXTSRAM_REGION_INFO_T *regionp;
    kal_uint32 buf_addr;
    kal_int32 buf_len;
    kal_uint32 i;
    kal_uint32 buf_start;

    for (i = 0; i < 2; i++)
    {
        if (i % 2 == 0)
        {
            vaddr = MAP2CREGPA(vaddr);
        }
        else
        {
            vaddr = MAP2CREGVA(vaddr);
        }

        custom_query_dynamic_cached_extsram_default_nc_region(&regionp);

        while (regionp->addr != 0 || regionp->len != 0)
        {
            if (regionp->len == 0)
            {
                regionp++;
                continue;
            }
            buf_start = regionp->addr;
            buf_addr = buf_start + regionp->len;
            buf_len = buf_addr - buf_start;

            if ((vaddr >= buf_start) &&
                (vaddr <= buf_start + buf_len))
            {
                ret = 1;
                return ret;
            }

            regionp++;
        }

        custom_query_dynamic_cached_extsram_default_c_region(&regionp);

        while (regionp->addr != 0 || regionp->len != 0)
        {
            if (regionp->len == 0)
            {
                regionp++;
                continue;
            }
            buf_start = regionp->addr;
            buf_addr = buf_start + regionp->len;
            buf_len = buf_addr - buf_start;

            if ((vaddr >= buf_start) &&
                (vaddr <= buf_start + buf_len))
            {
                ret = 1;
                return ret;
            }

            regionp++;
        }
    }
    return ret;
}
#endif  /* __DYNAMIC_SWITCH_CACHEABILITY__ */
#endif /* !__FUE__ && !__UBL__ */

/*************************************************************************
* FUNCTION
*  dynamic_switch_cacheable_region
*
* DESCRIPTION
*  This is used to dynamically change a region's cacheable/noncacheable attribute.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  vaddr
*  len
*  cacheable
*
* RETURNS
*  0 for successfully switch.
*
*************************************************************************/

#if !defined(__FUE__) && !defined(__UBL__)
DYNAMIC_SWITCH_CACHEABLE_REGION_PLACEMENT
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
kal_uint32 dynamic_switch_cacheable_region(void *vaddr, kal_uint32 len, kal_uint32 cacheable)
{
    kal_uint32 op_addr;

    op_addr = (kal_uint32)(*(kal_uint32*)vaddr);
    
    if (!is_predef_dyna_c_region(op_addr, len) ||
        !IS_CACHE_LINE_SIZE_ALIGNED(*(kal_uint32*)vaddr) ||
        !IS_CACHE_LINE_SIZE_ALIGNED(len))
    {
        ASSERT(0);
    }

    if ((INT_QueryIsCachedRAM(op_addr, len)) == cacheable)
    {
        return 0;
    }

    if (PAGE_CACHEABLE == cacheable)
    {
        (*(kal_uint32*)vaddr = MAP2CREGVA(*(kal_uint32*)vaddr));
        (op_addr = MAP2CREGVA(op_addr));
        invalidate_dcache(op_addr, len);
        cp15_drain_write_buffer();
    }
    else if (PAGE_NO_CACHE == cacheable)
    {
        clean_dcache(op_addr, len);
        (*(kal_uint32*)vaddr = MAP2CREGPA(*(kal_uint32*)vaddr));
        cp15_drain_write_buffer();
    }
    else
    {
        ASSERT(0);
    }

    return 0;
}

#endif  /* __DYNAMIC_SWITCH_CACHEABILITY__ */

#endif /* !__FUE__ && !__UBL__ */

/*************************************************************************
* FUNCTION
*  CacheInit
*
* DESCRIPTION
*  This function used to configure the overall cache setting.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/

#if !defined(__FUE__) && !defined(__UBL__)
void CacheInit(void)
{
/*********************************
  *
  * CR4 MPU config
  *
  ********************************/
#if defined(__CR4__)
    {
        kal_uint32 cache_type;
        kal_uint32 way_count;
        
        cache_type = cp15_read_dcache_info();
        cache_line_nr_per_way = ((cache_type<<4)>>17) + 1;
        way_count = ((cache_type<<19)>>22) + 1;
        cache_line_nr = cache_line_nr_per_way*way_count;
    }
    print_bootup_trace_enter(SST_INIT_MPU);
    custom_mk_ram_info(); //mk-ram_info for dynamic cacheability switch
    MPU_Init();
    print_bootup_trace_exit(SST_INIT_MPU);
#endif /* __CR4__ */
}

#endif /* !__FUE__ && !__UBL__ */


/*************************************************************************
* FUNCTION
*  meut_init_cache
*
* DESCRIPTION
*  This function initializes cache for MEUT.
*
* PARAMETERS
*  None
*
* RETURNS
*  0 for success; -1 for failure
*************************************************************************/

#if defined(__MEUT__)

kal_int32 meut_init_cache(void)
{
    CacheInit();

    return 0;
}

#endif  /* __MEUT__ */

#endif /* __MTK_TARGET__ */

/*************************************************************************
* FUNCTION
*  query_opposite_switchable_cacheaddr_ram
*
* DESCRIPTION
*  This function used to query the opposite cache-switchable address
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr - the address to be queried
*
* RETURNS
*
*************************************************************************/
#if !defined(__FUE__) && !defined(__UBL__)
kal_uint32 query_opposite_switchable_cacheaddr_ram(kal_uint32 addr)
{
#if (defined(__ARM9_MMU__) || defined(__DYNAMIC_SWITCH_CACHEABILITY__)) && defined(__MTK_TARGET__)
    EXTSRAM_REGION_INFO_T *regionp;
    kal_uint32 buf_start;
    kal_uint32 buf_addr;

    custom_query_dynamic_cached_extsram_default_nc_region(&regionp);
    while (regionp->addr != 0 || regionp->len != 0)
    {
        if (regionp->len == 0)
        {
            regionp++;
            continue;
        }
        buf_start = regionp->addr;
        buf_addr = regionp->addr + regionp->len;
        if ((addr >= buf_start) &&
            (addr <= buf_addr))
        {
            return MAP2CREGVA(addr);
        }
        if ((addr >= MAP2CREGVA(buf_start)) &&
            (addr <= MAP2CREGVA(buf_addr)))
        {
            return MAP2CREGPA(addr);
        }

        regionp++;
    }

    custom_query_dynamic_cached_extsram_default_c_region(&regionp);
    while (regionp->addr != 0 || regionp->len != 0)
    {
        if (regionp->len == 0)
        {
            regionp++;
            continue;
        }
        buf_start = regionp->addr;
        buf_addr = regionp->addr + regionp->len;
        if ((addr >= buf_start) &&
            (addr <= buf_addr))
        {
            return MAP2CREGPA(addr);
        }
        if ((addr >= MAP2CREGPA(buf_start)) &&
            (addr <= MAP2CREGPA(buf_addr)))
        {
            return MAP2CREGVA(addr);
        }

        regionp++;
    }

    /* assert if the input address is not cache-switchable */
    ASSERT(0);
#endif  /* (__ARM9_MMU__ || __DYNAMIC_SWITCH_CACHEABILITY__) && __MTK_TARGET__ */

    return addr;
}

#endif /* !__FUE__ && !__UBL__ */

/*************************************************************************
* FUNCTION
*  virt_to_phys
*
* DESCRIPTION
*  This function used to query the physical address of a virtual address
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr - the address to be queried
*
* RETURNS
*
*************************************************************************/

#if !defined(__FUE__) && !defined(__UBL__)

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
kal_uint32 virt_to_phys(void * address)
#if defined(__MTK_TARGET__)
{
#if !defined(__TCM_ONLY_LOAD__)
    kal_uint32 retval = 0;
    retval = MAP2CREGPA(address);

    return retval;
#else
    return (kal_uint32)address;
#endif
}
#else /* __MTK_TARGET__ */
{
    return 0;
}
#endif /* __MTK_TARGET__ */

#endif /* __DYNAMIC_SWITCH_CACHEABILITY__ */

#endif /* !__FUE__ && !__UBL__ */

/*************************************************************************
* FUNCTION
*  phys_to_virt
*
* DESCRIPTION
*  This function used to query the physical address of a virtual address
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr - the address to be queried
*
* RETURNS
*
*************************************************************************/

#if !defined(__FUE__) && !defined(__UBL__)

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
kal_uint32 phys_to_virt(void * address)
#if defined(__MTK_TARGET__)
{
    kal_uint32 retval = 0;
    retval = MAP2CREGVA(address);

    return retval;
}
#else /* __MTK_TARGET__ */
{
    return 0;
}
#endif /* __MTK_TARGET__ */

#endif /* __DYNAMIC_SWITCH_CACHEABILITY__ */

#endif /* !__FUE__ && !__UBL__ */

#if !defined(__FUE__) && !defined(__UBL__)
#if defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__)
void *map_back_memregion(void *ptr, void *region)
{
    return (void*)MAP2CREGNEWA(ptr, region);
}

#endif /* __MTK_TARGET__ && __DYNAMIC_SWITCH_CACHEABILITY__ */
#endif /* !__FUE__ && !__UBL__ */

/*************************************************************************
* FUNCTION
*  query_is_dram
*
* DESCRIPTION
*  This function used to query if the memory is DRAM or not. (not on CPU site, but AXIBUS site)
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr - the address to be queried
*  len - the length of the memory.
*
* RETURNS
*   true if the address is bank 0 or bank CREG_OFFSET.
*************************************************************************/
kal_int32 query_is_dram(kal_uint32 addr, kal_uint32 len)
{   
    return(((addr&0xF0000000) == 0x00000000) || ((addr&0xF0000000)==CREG_OFFSET)); 
}

extern kal_bool query_is_non_cached_ram(kal_uint32 addr, kal_uint32 len);

/*************************************************************************
* FUNCTION
*  query_is_noncached_ram
*
* DESCRIPTION
*  This function used to query if the memory is non-cacheable.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr - the address to be queried
*  len - the length of the memory.
*
* RETURNS
*
*************************************************************************/
kal_int32 query_is_noncached_ram(kal_uint32 addr, kal_uint32 len)
#if defined(__MTK_TARGET__)
{
    return ((((kal_uint32)(addr) & 0xF0000000) ^ CREG_OFFSET) != 0);
}
#else 
{
    return 1;
}
#endif /* !__MTK_TARGET__ || Others */

/*************************************************************************
* FUNCTION
*  query_is_cached_ram
*
* DESCRIPTION
*  This function used to query if the memory is cacheable.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr - the address to be queried
*  len - the length of the memory.
*
* RETURNS
*
*************************************************************************/
kal_int32 query_is_cached_ram(kal_uint32 addr, kal_uint32 len)
#if defined(__MTK_TARGET__) 
{
    return ((((kal_uint32)(addr) & 0xF0000000) ^ CREG_OFFSET) == 0);
}
#else
{
    return 0;
}
#endif /* !__MTK_TARGET__ || Others */

/*************************************************************************
* FUNCTION
*  Cache_Driver_Sanity_Test
*
* DESCRIPTION
*  This function test the correctness of each Cache Driver API for new chips
*  It is designed to be run after CacheInit()
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*  0: success
*  1: fail
*
*************************************************************************/
/*************************************************************************
 * !!!WARNING!!!
 * This function should NEVER be built in the official release 
 *************************************************************************/
//#define SS_CDST
#if defined(SS_CDST)
/* Test Options */
#define ASSERT_ON_ERROR   0

/* Sysram Option */
#if defined(MT6280) && defined(MT6290) && defined(MT6595)
#define CDST_SYSRAM_PLATFORM 0
#else
#define CDST_SYSRAM_PLATFORM 1
#endif

/* Helper macro */
#define CDST_INIT() \
    do { \
        CDST_ret = 0; \
    } while(0)
    
#define CDST_PASS(c) \
    do { \
        if(CDST_TEST_RESULT.c==WAIT) \
        { \
            CDST_TEST_RESULT.c=PASS; \
        } \
    } while(0)
    
#if ASSERT_ON_ERROR
#define CDST_FAIL(c) \
    do { \
        CDST_TEST_RESULT.c=FAIL; \
        CDST_ret = 1; \
        ASSERT(0);  \
    } while(0)

#else /* ASSERT_ON_ERROR */
#define CDST_FAIL(c) \
    do { \
        CDST_TEST_RESULT.c=FAIL; \
        CDST_ret = 1; \
    } while(0)
    
#endif /* ASSERT_ON_ERROR */

typedef enum
{
    WAIT=0,
    PASS,
    FAIL,
    BYPASS
} CDST_CASE;

struct {
    CDST_CASE Address_Remapping;          /* Check 0xF -> 0x0 remapping */
    
    CDST_CASE Invalidate_DCache_Small;    /* Invalidate D-Cache size <= cache size */
    CDST_CASE Invalidate_DCache_Large;    /* Invalidate D-Cache size > cache size */
    CDST_CASE Clean_DCache_Small;         /* Clean D-Cache size <= cache size */
    CDST_CASE Clean_DCache_Large;         /* Clean D-Cache size > cache size */
    CDST_CASE Clean_Inv_DCache_Small;     /* Clean and invalidate D-Cache size <= cache size */
    CDST_CASE Clean_Inv_DCache_Large;     /* Clean and invalidate D-Cache size > cache size */
    
    CDST_CASE Predef_Cache_Region;        /* is_predef_dyna_c_region */
    CDST_CASE Dynamic_Cache_Switch;       /* dynamic_switch_cacheable_region */    
    CDST_CASE Virt_to_Phys_to_Virt;       /* virt_to_phys, phys_to_virt */
    
    CDST_CASE Query_is_Non_Cached_Ram;    /* INT_QueryIsNonCachedRAM */
    CDST_CASE Query_is_Cached_Ram;        /* INT_QueryIsCachedRAM */
    CDST_CASE Query_is_Non_Cached_SysRAM; /* INT_QueryIsNonCachedSysRAM */
    CDST_CASE Query_is_Cached_SysRAM;     /* INT_QueryIsCachedSysRAM */
    CDST_CASE Query_is_SysRAM;            /* INT_QueryIsSysRAM */
} CDST_TEST_RESULT={0};


#ifdef __MTK_TARGET__
__attribute__ ((section("DYNAMICCACHEABLEZI_NC"), zero_init))
#endif /* __MTK_TARGET__ */
__attribute__ ((aligned(32*1024))) kal_uint32 CDST_DCDNC_array[64*1024];


#ifdef __MTK_TARGET__
__attribute__ ((section("NONCACHEDZI"), zero_init))
#endif /* __MTK_TARGET__ */
kal_uint32 CDST_NC_Var;

kal_uint32 CDST_C_Var;

kal_uint32 CDST_ret=0;

kal_uint32 Cache_Driver_Sanity_Test(void)
{
    kal_uint32 idx;
    kal_uint32 *ptr;
    
    CDST_INIT();
    
/**************************************************************************
*   ADDRESS REMAPPING TEST
***************************************************************************/
    if((kal_uint32)CDST_DCDNC_array==MAP2CREGVA((kal_uint32)CDST_DCDNC_array))
    {
        CDST_FAIL(Address_Remapping);   // PA == VA abnormal
    }
    clean_and_invalidate_dcache(MAP2CREGVA((kal_uint32)CDST_DCDNC_array), cache_line_nr);
    ptr=(kal_uint32*)MAP2CREGPA((kal_uint32)CDST_DCDNC_array);
    
    /* Fill PA region with test pattern */
    for(idx=0;idx<cache_line_nr*32/4;idx++)
    {
        ptr[idx]=(kal_uint32)(ptr+idx);
    }
    cp15_drain_write_buffer();    

    /* Check VA and PA region read the same and correct test pattern */
    for(idx=0;idx<cache_line_nr*32/4;idx++)
    {
        if(*(kal_uint32*)MAP2CREGVA((kal_uint32)(CDST_DCDNC_array+idx))!=*(CDST_DCDNC_array+idx))
        {
              CDST_FAIL(Address_Remapping);
        }
        if(*(kal_uint32*)MAP2CREGVA((kal_uint32)(CDST_DCDNC_array+idx))!=(kal_uint32)(CDST_DCDNC_array+idx))
        {
              CDST_FAIL(Address_Remapping);
        }
    }
    CDST_PASS(Address_Remapping);

/**************************************************************************
*   DCache Operation Tests
***************************************************************************/
/* Invalidate DCache Small */
    /* Write VA with test pattern A */
    ptr=(kal_uint32*)MAP2CREGVA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<1024;idx++)
    {
        //*(ptr+idx);
        *(ptr+idx)=0xDEADBEEF;
    }
    
    /* Invalidate VA DCache */
    invalidate_dcache((kal_uint32)ptr, 1024*4);
    
    ptr=(kal_uint32*)MAP2CREGPA((kal_uint32)CDST_DCDNC_array);
    /* Write PA with test pattern B */
    for(idx=0;idx<1024;idx++)
    {
        *(ptr+idx)=(kal_uint32)(ptr+idx);
    }

    ptr=(kal_uint32*)MAP2CREGVA((kal_uint32)CDST_DCDNC_array);
    /* Read VA and the value should be test pattern B */
    for(idx=0;idx<1024;idx++)
    {
        if(*(ptr+idx)!=MAP2CREGPA(CDST_DCDNC_array+idx))
        {
              CDST_FAIL(Invalidate_DCache_Small);
        }          
    }
    CDST_PASS(Invalidate_DCache_Small);

/* Invalidate DCache Large */
    /* Write VA with test pattern A */
    ptr=(kal_uint32*)MAP2CREGVA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<64*1024;idx++)
    {
        //*(ptr+idx);
        *(ptr+idx)=0xDEADBEEF;
    }
    
    /* Invalidate VA DCache */
    invalidate_dcache((kal_uint32)ptr, 64*1024*4);
    
    ptr=(kal_uint32*)MAP2CREGPA((kal_uint32)CDST_DCDNC_array);    
    /* Read PA, it should be test pattern A, since large invalidate will do clean and invalidate */
    /* Write PA with test pattern B */
    for(idx=0;idx<64*1024;idx++)
    {
        if(*(ptr+idx)!=0xDEADBEEF)
        {
            CDST_FAIL(Invalidate_DCache_Large);
        }  
        *(ptr+idx)=(kal_uint32)(ptr+idx);
    }
    
    ptr=(kal_uint32*)MAP2CREGVA((kal_uint32)CDST_DCDNC_array);
    /* Read VA and the value should be test pattern B */
    for(idx=0;idx<64*1024;idx++)
    {
        if(*(ptr+idx)!=MAP2CREGPA(CDST_DCDNC_array+idx))
        {
              CDST_FAIL(Invalidate_DCache_Large);
        }          
    }
    CDST_PASS(Invalidate_DCache_Large);
    
/* Clean DCache Small */
    /* Write PA with test pattern A */
    ptr=(kal_uint32*)MAP2CREGPA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<1024;idx++)
    {
        *(ptr+idx)=0xDEADBEEF;
    }
    
    /* Write VA with test pattern B */
    ptr=(kal_uint32*)MAP2CREGVA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<1024;idx++)
    {
        //*(ptr+idx);
        *(ptr+idx)=(kal_uint32)(ptr+idx);
    }
    
    /* Clean VA */
    clean_dcache((kal_uint32)ptr, 1024*4);
    
    /* Read PA and it should be test pattern B */
    ptr=(kal_uint32*)MAP2CREGPA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<1024;idx++)
    {
        if(*(ptr+idx)!=MAP2CREGVA(ptr+idx))
        {
            CDST_FAIL(Clean_DCache_Small);
        }
    }    
    CDST_PASS(Clean_DCache_Small);
    
/* Clean DCache Large */
    /* Write PA with test pattern A */
    ptr=(kal_uint32*)MAP2CREGPA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<64*1024;idx++)
    {
        *(ptr+idx)=0xDEADBEEF;
    }
    
    /* Write VA with test pattern B */
    ptr=(kal_uint32*)MAP2CREGVA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<64*1024;idx++)
    {
        //*(ptr+idx);
        *(ptr+idx)=(kal_uint32)(ptr+idx);
    }
    
    /* Clean VA */
    clean_dcache((kal_uint32)ptr, 64*1024*4);
    
    /* Read PA and it should be test pattern B */
    ptr=(kal_uint32*)MAP2CREGPA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<64*1024;idx++)
    {
        if(*(ptr+idx)!=MAP2CREGVA(ptr+idx))
        {
            CDST_FAIL(Clean_DCache_Large);
        }
    }  
    CDST_PASS(Clean_DCache_Large);
    
/* Clean and Invalidate DCache Small */
    /* Write PA with test pattern A */
    ptr=(kal_uint32*)MAP2CREGPA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<1024;idx++)
    {
        *(ptr+idx)=0xDEADBEEF;
    }

    /* Write VA with test pattern B */
    ptr=(kal_uint32*)MAP2CREGVA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<1024;idx++)
    {
        //*(ptr+idx);
        *(ptr+idx)=(kal_uint32)(ptr+idx);
    }
    
    /* Clean and invalidate VA */
    clean_and_invalidate_dcache((kal_uint32)ptr, 1024*4);    
    
    /* Read PA and it should be test pattern B */
    ptr=(kal_uint32*)MAP2CREGPA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<1024;idx++)
    {
        if(*(ptr+idx)!=MAP2CREGVA(ptr+idx))
        {
            CDST_FAIL(Clean_Inv_DCache_Small);
        }
    }    
    
    /* Write PA with test pattern A */
    ptr=(kal_uint32*)MAP2CREGPA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<1024;idx++)
    {
        *(ptr+idx)=0xDEADBEEF;
    }

    cp15_drain_write_buffer();

    /* Read VA and it should be test pattern A */
    ptr=(kal_uint32*)MAP2CREGVA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<1024;idx++)
    {
        if(*(ptr+idx)!=(kal_uint32)(0xDEADBEEF))
        {
            CDST_FAIL(Clean_Inv_DCache_Small);
        }
    }    
    CDST_PASS(Clean_Inv_DCache_Small);    

/* Clean and Invalidate DCache Large */
    /* Write PA with test pattern A */
    ptr=(kal_uint32*)MAP2CREGPA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<64*1024;idx++)
    {
        *(ptr+idx)=0xDEADBEEF;
    }
    
    /* Write VA with test pattern B */
    ptr=(kal_uint32*)MAP2CREGVA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<64*1024;idx++)
    {
        //*(ptr+idx);
        *(ptr+idx)=(kal_uint32)(ptr+idx);
    }
    
    /* Clean and invalidate VA */
    clean_and_invalidate_dcache((kal_uint32)ptr, 64*1024*4);
    
    /* Read PA and it should be test pattern B */
    ptr=(kal_uint32*)MAP2CREGPA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<64*1024;idx++)
    {
        if(*(ptr+idx)!=MAP2CREGVA(ptr+idx))
        {
            CDST_FAIL(Clean_Inv_DCache_Large);
        }
    }    
    
    /* Write PA with test pattern A */
    ptr=(kal_uint32*)MAP2CREGPA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<64*1024;idx++)
    {
        *(ptr+idx)=0xDEADBEEF;
    }

    cp15_drain_write_buffer();

    /* Read VA and it should be test pattern A */
    ptr=(kal_uint32*)MAP2CREGVA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<64*1024;idx++)
    {
        if(*(ptr+idx)!=(kal_uint32)(0xDEADBEEF))
        {
            CDST_FAIL(Clean_Inv_DCache_Large);
        }
    }    
    CDST_PASS(Clean_Inv_DCache_Large);
    
/**************************************************************************
*   Dynamic Cacheablility APIs Test
***************************************************************************/
/* Predef_Cache_Region */
    /* Check Cached Ram symbol, it should not return 1 */
    if(is_predef_dyna_c_region((kal_uint32)(&CDST_C_Var), 4)==1)
    {
        CDST_FAIL(Predef_Cache_Region);
    }
    
    /* Check DCDNC symbol, it should not return 0 */
    if(is_predef_dyna_c_region((kal_uint32)(CDST_DCDNC_array), 4)==0)
    {
        CDST_FAIL(Predef_Cache_Region);
    }
    CDST_PASS(Predef_Cache_Region);
    
/* Dynamic_Cache_Switch */
    ptr=CDST_DCDNC_array;
    /* Fill NC with test pattern A */
    for(idx=0;idx<64*1024;idx++)
    {
        ptr[idx]=MAP2CREGPA(ptr+idx);
    }
       
    /* Switch to cacheable */
    dynamic_switch_cacheable_region(&ptr, 64*1024*4, PAGE_CACHEABLE);
    
    /* Read C and it should be test pattern A */
    /* Fill C with test pattern B */
    for(idx=0;idx<64*1024;idx++)
    {
        if(ptr[idx]!=MAP2CREGPA(ptr+idx))
        {
            CDST_FAIL(Dynamic_Cache_Switch);
        }
        ptr[idx]=MAP2CREGVA(ptr+idx);
    }

    /* Switch to non-cacheable */
    dynamic_switch_cacheable_region(&ptr, 64*1024*4, PAGE_NO_CACHE);

    /* Read NC and it should be test pattern B */    
    for(idx=0;idx<64*1024;idx++)
    {
        if(ptr[idx]!=MAP2CREGVA(ptr+idx))
        {
            CDST_FAIL(Dynamic_Cache_Switch);
        }
    }
    CDST_PASS(Dynamic_Cache_Switch);

/* Virt_to_Phys_to_Virt */
    if(virt_to_phys(CDST_DCDNC_array)!=MAP2CREGPA(CDST_DCDNC_array))
    {
        CDST_FAIL(Virt_to_Phys_to_Virt);
    }
    if(virt_to_phys(&CDST_NC_Var)!=MAP2CREGPA(&CDST_NC_Var))
    {
        CDST_FAIL(Virt_to_Phys_to_Virt);
    }
    if(virt_to_phys(&CDST_C_Var)!=MAP2CREGPA(&CDST_C_Var))
    {
        CDST_FAIL(Virt_to_Phys_to_Virt);
    }
    
    if(phys_to_virt(CDST_DCDNC_array)!=MAP2CREGVA(CDST_DCDNC_array))
    {
        CDST_FAIL(Virt_to_Phys_to_Virt);
    }
    if(phys_to_virt(&CDST_NC_Var)!=MAP2CREGVA(&CDST_NC_Var))
    {
        CDST_FAIL(Virt_to_Phys_to_Virt);
    }
    if(phys_to_virt(&CDST_C_Var)!=MAP2CREGVA(&CDST_C_Var))
    {
        CDST_FAIL(Virt_to_Phys_to_Virt);
    }
    CDST_PASS(Virt_to_Phys_to_Virt);

/**************************************************************************
*   Query APIs Test
***************************************************************************/
/* Query_is_Non_Cached_Ram */
    if(INT_QueryIsNonCachedRAM(&CDST_NC_Var, 4)!=1)
    {
        CDST_FAIL(Query_is_Non_Cached_Ram);  
    }
    if(INT_QueryIsNonCachedRAM(&CDST_C_Var, 4)!=0)
    {
        CDST_FAIL(Query_is_Non_Cached_Ram);  
    }
    CDST_PASS(Query_is_Non_Cached_Ram);  

/* Query_is_Cached_Ram */    
    if(INT_QueryIsCachedRAM(&CDST_NC_Var, 4)!=0)
    {
        CDST_FAIL(Query_is_Cached_Ram);  
    }
    if(INT_QueryIsCachedRAM(&CDST_C_Var, 4)!=1)
    {
        CDST_FAIL(Query_is_Cached_Ram);  
    }      
    CDST_PASS(Query_is_Cached_Ram);  

/* Sysram Related */
#if CDST_SYSRAM_PLATFORM
    /* TBD */
#else /* CDST_SYSRAM_PLATFORM */
/* Query_is_Non_Cached_SysRAM */
    if(INT_QueryIsNonCachedSysRAM(&CDST_NC_Var,4)!=0)
    {
        CDST_FAIL(Query_is_Non_Cached_SysRAM);
    }
    if(INT_QueryIsNonCachedSysRAM(&CDST_C_Var,4)!=0)
    {
        CDST_FAIL(Query_is_Non_Cached_SysRAM);
    }
    if(INT_QueryIsNonCachedSysRAM(CDST_DCDNC_array,4)!=0)
    {
        CDST_FAIL(Query_is_Non_Cached_SysRAM);
    }
    CDST_PASS(Query_is_Non_Cached_SysRAM);
    
/* Query_is_Cached_SysRAM */
    if(INT_QueryIsCachedSysRAM(&CDST_NC_Var,4)!=0)
    {
        CDST_FAIL(Query_is_Cached_SysRAM);
    }
    if(INT_QueryIsCachedSysRAM(&CDST_C_Var,4)!=0)
    {
        CDST_FAIL(Query_is_Cached_SysRAM);
    }
    if(INT_QueryIsCachedSysRAM(CDST_DCDNC_array,4)!=0)
    {
        CDST_FAIL(Query_is_Cached_SysRAM);
    }
    CDST_PASS(Query_is_Cached_SysRAM);
    
/* Query_is_SysRAM */
    if(INT_QueryIsSysRAM(&CDST_NC_Var)!=0)
    {
        CDST_FAIL(Query_is_SysRAM);
    }
    if(INT_QueryIsSysRAM(&CDST_C_Var)!=0)
    {
        CDST_FAIL(Query_is_SysRAM);
    }
    if(INT_QueryIsSysRAM(CDST_DCDNC_array)!=0)
    {
        CDST_FAIL(Query_is_SysRAM);
    }
    CDST_PASS(Query_is_SysRAM);
#endif 

    return CDST_ret;
}
#endif /* SS_CDST */
