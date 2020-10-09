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
 *   ex_memory_manager.h
 *
 * Project:
 * --------
 *   Moly
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __EX_MEM_MANAGER_H__
#define __EX_MEM_MANAGER_H__

#include "ex_mem_manager_public.h"

#if defined (__HIF_CCCI_SUPPORT__)
#include "ccci_if.h"
#endif

/*******************************************************************************
 * Define data structure.
 *******************************************************************************/
typedef enum {
    EMM_QUERY_FAIL = 0x1,
    EMM_CHECK_FAIL = 0x2,
    EMM_NO_CCCI_FAIL = 0x4,
    EMM_PERMISSION_FAIL = 0x8,
} EMM_QUERY_RESULT;

typedef enum {
    EMM_BUF_INMD_FROM_AP = 0x1,
    EMM_BUF_EXMD_STATIC,
    EMM_BUF_MAX,
} EMM_BUF_SOURCE;

typedef struct _Inner_Shared_EMM_INFO {
    EMM_BUF_SOURCE  bufSourceType;
    kal_uint32      u32Mainbuf_Addr;
    kal_uint32      bufLen;
    kal_uint8       resultFail;
} INNER_EMM_INFO;

typedef struct _EMM_INFO {
    EMM_BUF_SOURCE  bufSourceType;
    kal_uint32      u32Mainbuf_Addr;
    kal_uint32      bufLen;

    kal_uint32      *pexRecord;
    kal_uint32      exRecordWordLen;
    
    kal_uint32      *pdbgInfo;
    kal_uint32      dbgInfoWordLen;

    kal_uint32      *pUserDirInfo;
    kal_uint32      userDirInfoWordLen;
    
    kal_uint8       bootTraceFinish;
    kal_uint8       resultFail;
} EMM_INFO;

#define EMM_EXRECORD_LEN        (1024*6)
#define EMM_DBGINFO_LEN         768
#define EMM_USERDIRINFO_LEN     256
#define EMM_INFO_TOTAL_LEN   (EMM_DBGINFO_LEN+EMM_USERDIRINFO_LEN)

#define EMM_DORMANT_SIZE         4
#define EMM_SWLA_SIZE            40



#define EMM_EXRECORD_WORDLEN    (EMM_EXRECORD_LEN)
#define EMM_DBGINFO_WORDLEN     (EMM_DBGINFO_LEN >> 2)
#define EMM_USERDIRINFO_WORDLEN (EMM_USERDIRINFO_LEN >> 2)


#define EMM_INDICATOR_L 0x12345678    /* magic num */
#define EMM_INDICATOR_H 0x47424445    /* "EDBG" */

#define EMM_DIRINFO_GUARD_PATTERN_START(_index) ((0xEDEC << 16) | _index)
#define EMM_DIRINFO_GUARD_PATTERN_END(_index)   ((0xCEDE << 16) | _index)



typedef struct {
    kal_uint32 magic_number_l;
    kal_uint32 magic_number_h;
    kal_uint32 last_write_index;
    kal_uint32 reserved;
    kal_uint32 log[EMM_INDEX_MAX];
} EMM_DBGINFO_STRUC;

typedef struct _EMM_BUF_CONTENT {
    kal_uint32  exRecord[EMM_EXRECORD_WORDLEN];
    kal_uint32  dbgInfo[EMM_DBGINFO_WORDLEN];
} EMM_BUF_CONTENT;

typedef struct _EMM_SWLA_PAIR {
	kal_char name[4];
	kal_uint32 timestamp;
} EMM_SWLA_PAIR;

typedef struct _EMM_BUF_SYSINFO {
	kal_uint32 pattern[2];
	kal_uint32 laststep;
	kal_uint32 reserved;
	kal_uint32 sysinfo[(EMM_DBGINFO_LEN/sizeof(kal_uint32))- 4];
	kal_uint32 EDE_DOR_HEAD;
	kal_uint32 EDE_DOR_STEP;
	kal_uint32 EDE_DOR_RESERVED[EMM_DORMANT_SIZE-1];
	kal_uint32 EDE_DOR_TAIL;
	kal_uint32 EDE_SWLA_HEAD;
	EMM_SWLA_PAIR EDE_SWLA[EMM_SWLA_SIZE*sizeof(kal_uint32)/sizeof(EMM_SWLA_PAIR)];
	kal_uint32 EDE_SWLA_TAIL;
} EMM_SYSINFO_STRUC;


#endif

