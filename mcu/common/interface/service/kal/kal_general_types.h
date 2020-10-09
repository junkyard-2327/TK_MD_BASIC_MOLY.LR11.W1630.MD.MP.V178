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
 *   kal_general_types.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides general fundemental types definations.
 *   Independent with underlaying RTOS.
 *
 *   User who include this file may not require KAL API at all.
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
 ****************************************************************************/

#ifndef _KAL_GENERAL_TYPES_H
#define _KAL_GENERAL_TYPES_H

#if defined(__ESL_COSIM_LTE__) || defined(__SYSTEMC__)
#include "inttypes.h"
#include "limits.h"
#endif 

#include "clib.h"

/*******************************************************************************
 * Type Definitions
 *******************************************************************************/
 
/* portable character for multichar character set */
typedef char                    kal_char;
/* portable wide character for unicode character set */
typedef unsigned short          kal_wchar;

/* portable 8-bit unsigned integer */
typedef unsigned char           kal_uint8;
/* portable 8-bit signed integer */
typedef signed char             kal_int8;
/* portable 16-bit unsigned integer */
typedef unsigned short int      kal_uint16;
/* portable 16-bit signed integer */
typedef signed short int        kal_int16;
/* portable 32-bit unsigned integer */
typedef unsigned int            kal_uint32;
/* portable 32-bit signed integer */
typedef signed int              kal_int32;

/* portable 64-bit unsigned integer */
#if defined(__ARMCC_VERSION) || defined(__GNUC__) || defined(__MINGW32__) || defined(GEN_FOR_PC)
   typedef unsigned long long   kal_uint64;
#elif defined(_MSC_VER)
   typedef unsigned __int64     kal_uint64;
#endif /* Cross RVCT/GCC/VC9 Compiler marco definition */

/* portable 64-bit signed integer */
#if defined(__ARMCC_VERSION) || defined(__GNUC__) || defined(__MINGW32__) || defined(GEN_FOR_PC)
   typedef signed long long     kal_int64;
#elif defined(_MSC_VER)
   typedef __int64              kal_int64;
#endif /* Cross RVCT/GCC/VC9 Compiler marco definition */


#if !defined(_WINNT_H) && !defined(_WINNT_)
typedef unsigned short WCHAR;
#endif


/* boolean representation */
typedef enum 
{
    /* FALSE value */
    KAL_FALSE,
    /* TRUE value */
    KAL_TRUE
} kal_bool;

/*******************************************************************************
 * Constant definition
 *******************************************************************************/
#ifndef NULL
#define NULL               0
#endif

/*******************************************************************************
 * ALIGN and PACK macro definition
 *******************************************************************************/

#if defined(__ARMCC_VERSION)
	#define DECLARE_ALIGN_BEGIN(n)      __align(n)
    #define DECLARE_ALIGN_END(n)
   #define DECLARE_ALIGN_MIDDLE(n)
#elif defined(__MINGW32__) 				/* end of __ARMCC_VERSION */
    #define DECLARE_ALIGN_BEGIN(n)
    #define DECLARE_ALIGN_END(n)        __attribute__ ((aligned (n)))
   #define DECLARE_ALIGN_MIDDLE(n)
#elif defined(__GNUC__) 				/* end of __MINGW32__ */
    #define DECLARE_ALIGN_BEGIN(n)
    #define DECLARE_ALIGN_END(n)        __attribute__ ((aligned (n)))
    #define DECLARE_ALIGN_MIDDLE(n)
#elif defined(_MSC_VER) && (_MSC_VER >= 1500)	/* end of __GNUC__ */
    #define DECLARE_ALIGN_BEGIN(n)      __declspec(align(n))
    #define DECLARE_ALIGN_END(n)        /* end of _MSC_VER */
    #define DECLARE_ALIGN_MIDDLE(n)
#else                                   /* end of _MSC_VER */
    #error "Unsupported Compiler in Simulator"
#endif

#if defined(__ARMCC_VERSION)
    #define PRAGMA_BEGIN_PACK_STRUCT    _Pragma("push")\
                                        _Pragma("pack(1)")
    #define PRAGMA_END_PACK_STRUCT      _Pragma("pop")
#elif defined(__MINGW32__)              /* end of __ARMCC_VERSION */
    #define PRAGMA_BEGIN_PACK_STRUCT    _Pragma("pack(push, 1)")
    #define PRAGMA_END_PACK_STRUCT      _Pragma("pack(pop)")
#elif defined(__GNUC__)                 /* end of _MINGW32_ */
    #define PRAGMA_BEGIN_PACK_STRUCT    _Pragma("pack(push, 1)")
    #define PRAGMA_END_PACK_STRUCT      _Pragma("pack(pop)")
#elif defined(_MSC_VER) && (_MSC_VER >= 1500)	/* end of __GNUC__ */
    #define PRAGMA_BEGIN_PACK_STRUCT    __pragma(pack(push, 1))
    #define PRAGMA_END_PACK_STRUCT      __pragma(pack(pop))
#else                                   /* end of _MSC_VER */
    #error "Unsupported Compiler in Simulator"
#endif


#if defined(__ARMCC_VERSION)
    #define RO_CODE_SECTION(section_name) __attribute__ ((section (#section_name)))
    #define RO_DATA_SECTION(section_name) __attribute__ ((section (#section_name)))
    #define RW_DATA_SECTION(section_name) __attribute__ ((section (#section_name)))
    #define ZI_DATA_SECTION(section_name) __attribute__ ((zero_init, section (#section_name)))
    #define DEFAULT_SECTION
#elif defined(__MINGW32__)              /* end of __ARMCC_VERSION */
    #define RO_CODE_SECTION(section_name) __attribute__ ((section (#section_name)))
    #define RO_DATA_SECTION(section_name) __attribute__ ((section (#section_name)))
    #define RW_DATA_SECTION(section_name) __attribute__ ((section (#section_name)))
    #define ZI_DATA_SECTION(section_name) __attribute__ ((section (#section_name)))
    #define DEFAULT_SECTION
#elif defined(__GNUC__)                 /* end of _MINGW32_ */
    #define RO_CODE_SECTION(section_name) __attribute__ ((section (#section_name)))
    #define RO_DATA_SECTION(section_name) __attribute__ ((section (#section_name)))
    #define RW_DATA_SECTION(section_name) __attribute__ ((section (#section_name)))
    #define ZI_DATA_SECTION(section_name) __attribute__ ((section (#section_name)))
    #define DEFAULT_SECTION
#elif defined(_MSC_VER) && (_MSC_VER >= 1500)	/* end of __GNUC__ */
    #define RO_CODE_SECTION(section_name)
    #define RO_DATA_SECTION(section_name)
    #define RW_DATA_SECTION(section_name)
    #define ZI_DATA_SECTION(section_name)
    #define DEFAULT_SECTION
#else                                   /* end of _MSC_VER */
    #error "Unsupported Compiler in Simulator"
#endif


#if defined(__ARMCC_VERSION)
    #define DECLARE_NOINLINE            __attribute__((noinline))
#elif defined(__MINGW32__)              /* end of __ARMCC_VERSION */
    #define DECLARE_NOINLINE            __attribute__((noinline))
#elif defined(__GNUC__)                 /* end of _MINGW32_ */
    #define DECLARE_NOINLINE            __attribute__((noinline))
#elif defined(_MSC_VER) && (_MSC_VER >= 1500)	/* end of __GNUC__ */
    #define DECLARE_NOINLINE
#else                                   /* end of _MSC_VER */
    #error "Unsupported Compiler in Simulator"
#endif


#if defined(__ARMCC_VERSION)
    #define DECLARE_WEAK                __attribute__((weak))
#elif defined(__MINGW32__)              /* end of __ARMCC_VERSION */
    #define DECLARE_WEAK                __attribute__((weak))
#elif defined(__GNUC__)                 /* end of _MINGW32_ */
    #define DECLARE_WEAK                __attribute__((weak))
#elif defined(_MSC_VER) && (_MSC_VER >= 1500)	/* end of __GNUC__ */
    #define DECLARE_WEAK
#else                                   /* end of _MSC_VER */
    #error "Unsupported Compiler in Simulator"
#endif


#if defined(__ARMCC_VERSION)
    #define DECLARE_DEPRECATED            __attribute__((deprecated))
#elif defined(__MINGW32__)              /* end of __ARMCC_VERSION */
    #define DECLARE_DEPRECATED            __attribute__((deprecated))
#elif defined(__GNUC__)                 /* end of _MINGW32_ */
    #define DECLARE_DEPRECATED            __attribute__((deprecated))
#elif defined(_MSC_VER) && (_MSC_VER >= 1500)	/* end of __GNUC__ */
    #define DECLARE_DEPRECATED
#else                                   /* end of _MSC_VER */
    #error "Unsupported Compiler in Simulator"
#endif


#if defined(__ARMCC_VERSION)
    #define UNUSED_PARAMETER(x)         (void)(x)
#elif defined(__MINGW32__)              /* end of __ARMCC_VERSION */
    #define UNUSED_PARAMETER(x)         (void)(x)
#elif defined(__GNUC__)                 /* end of _MINGW32_ */
    #define UNUSED_PARAMETER(x)         (void)(x)
#elif defined(_MSC_VER) && (_MSC_VER >= 1500)	/* end of __GNUC__ */
    #define UNUSED_PARAMETER(x)         (void)(x)
#else                                   /* end of _MSC_VER */
    #error "Unsupported Compiler in Simulator"
#endif


/*******************************************************************************
 * Type Definitions
 *******************************************************************************/
#if defined(_MSC_VER) && (_MSC_VER >= 1500)
    #define SHARED_VAR_ALIGNMENT_CHECK(name, aligned_size, alignment) \
                kal_char DISCARD__##name[sizeof(char[1 - 2*!!!(!( aligned_size % alignment))])];
#elif defined(__GNUC__) && defined(__PCORE__)
    #define SHARED_VAR_ALIGNMENT_CHECK(name, aligned_size, alignment) \
                __attribute__ ((section ("SHOULD_NOT_USED_RODATA"))) kal_char DISCARD__##name[sizeof(char[1 - 2*!!!(!( aligned_size % alignment))])];
#endif


#if defined(__ARMCC_VERSION)
    #error "Unsupported Compiler in Simulator"
#elif defined(__MINGW32__)              /* end of __ARMCC_VERSION */
    /** DNC **/
    #define DEFINE_DNC_SHARED_VAR(type, name) \
                type name;
    #define DEFINE_DNC_SHARED_ARRAY(type, name, size) \
                type name[size];
    #define DEFINE_RCU_DNC_SHARED_ARRAY(type, name, size) \
                type name[size];

    #define DEFINE_DNC_SHARED_VAR_ASSIGN(type, name, ...)  \
                type name = {__VA_ARGS__};
    #define DEFINE_DNC_SHARED_ARRAY_ASSIGN(type, name, size, ...) \
                type name[size] = {__VA_ARGS__};

    /** NC **/
    #define DEFINE_NC_SHARED_VAR(type, name) DEFINE_DNC_SHARED_VAR(type, name)
    #define DEFINE_NC_SHARED_ARRAY(type, name, size) DEFINE_DNC_SHARED_ARRAY(type, name, size)
    #define DEFINE_RCU_NC_SHARED_ARRAY(type, name, size) DEFINE_RCU_DNC_SHARED_ARRAY(type, name, size)

    #define DEFINE_NC_SHARED_VAR_ASSIGN(type, name, ...)  DEFINE_DNC_SHARED_VAR_ASSIGN(type, name, {__VA_ARGS__})
    #define DEFINE_NC_SHARED_ARRAY_ASSIGN(type, name, size, ...) DEFINE_DNC_SHARED_ARRAY_ASSIGN(type, name, size, {__VA_ARGS__})

    /** DNC ALIGNED **/
    #define DEFINE_DNC_ALIGNED_SHARED_VAR(type, name, aligned_size) \
                type name;
    #define DEFINE_DNC_ALIGNED_SHARED_ARRAY(type, name, size, aligned_size) \
                type name[size];

    #define DEFINE_DNC_ALIGNED_SHARED_VAR_ASSIGN(type, name, aligned_size, ...)  \
                type name = {__VA_ARGS__};
    #define DEFINE_DNC_ALIGNED_SHARED_ARRAY_ASSIGN(type, name, size, alignd_size, ...) \
                type name[size] = {__VA_ARGS__};

    /** NC ALIGNED **/
    #define DEFINE_NC_ALIGNED_SHARED_VAR(type, name, aligned_size) DEFINE_DNC_ALIGNED_SHARED_VAR(type, name, aligned_size)
    #define DEFINE_NC_ALIGNED_SHARED_ARRAY(type, name, size, aligned_size) DEFINE_DNC_ALIGNED_SHARED_ARRAY(type, name, size, aligned_size)

    #define DEFINE_NC_ALIGNED_SHARED_VAR_ASSIGN(type, name, aligned_size, ...)  DEFINE_DNC_ALIGNED_SHARED_VAR_ASSIGN(type, name, aligned_size, {__VA_ARGS__})
    #define DEFINE_NC_ALIGNED_SHARED_ARRAY_ASSIGN(type, name, size, aligned_size, ...) DEFINE_DNC_ALIGNED_SHARED_ARRAY_ASSIGN(type, name, size, aligned_size, {__VA_ARGS__})

    #define DECLARE_SHARED_VAR(type, name) extern type name;
    #define DECLARE_SHARED_ARRAY(type, name, size) extern type name[size];

    #define SHARED_VAR(name) (name)
    #define SHARED_ARRAY(name) (name)
    #define SHARED_pVAR(name) (&name)
    #define SHARED_pARRAY(name) (&name)
#elif defined(_MSC_VER) && (_MSC_VER >= 1500)   /* end of __MINGW32__ */
    /** DNC **/
    #define DEFINE_DNC_SHARED_VAR(type, name) \
                __declspec(align(32)) type name;
    #define DEFINE_DNC_SHARED_ARRAY(type, name, size) \
                __declspec(align(32)) type name[size];
    #define DEFINE_RCU_DNC_SHARED_ARRAY(type, name, size) \
                __declspec(align(64)) type name[size];

    #define DEFINE_DNC_SHARED_VAR_ASSIGN(type, name, ...)  \
                __declspec(align(32)) type name = {__VA_ARGS__};
    #define DEFINE_DNC_SHARED_ARRAY_ASSIGN(type, name, size, ...) \
                __declspec(align(32)) type name[size] = {__VA_ARGS__};

    /** NC **/ /* we do not apply the alignment as GCC since VC only support constant value alignment */
    #define DEFINE_NC_SHARED_VAR(type, name) \
                __declspec(align(4)) type name;
    #define DEFINE_NC_SHARED_ARRAY(type, name, size)\
                __declspec(align(4)) type name[size];
    #define DEFINE_RCU_NC_SHARED_ARRAY(type, name, size)\
                __declspec(align(64)) type name[size];

    #define DEFINE_NC_SHARED_VAR_ASSIGN(type, name, ...) \
                __declspec(align(4)) type name = {__VA_ARGS__};
    #define DEFINE_NC_SHARED_ARRAY_ASSIGN(type, name, size, ...) \
                __declspec(align(4)) type name[size] = {__VA_ARGS__};

    /** DNC ALIGNED **/
    #define DEFINE_DNC_ALIGNED_SHARED_VAR(type, name, aligned_size) \
                __declspec(align(aligned_size)) type name; \
                SHARED_VAR_ALIGNMENT_CHECK(name, aligned_size, 32);
    #define DEFINE_DNC_ALIGNED_SHARED_ARRAY(type, name, size, aligned_size) \
                __declspec(align(aligned_size)) type name[size]; \
                SHARED_VAR_ALIGNMENT_CHECK(name, aligned_size, 32);

    #define DEFINE_DNC_ALIGNED_SHARED_VAR_ASSIGN(type, name, aligned_size, ...)  \
                __declspec(align(aligned_size)) type name = {__VA_ARGS__}; \
                SHARED_VAR_ALIGNMENT_CHECK(name, aligned_size, 32);
    #define DEFINE_DNC_ALIGNED_SHARED_ARRAY_ASSIGN(type, name, size, aligned_size, ...) \
                __declspec(align(aligned_size)) type name[size] = {__VA_ARGS__}; \
                SHARED_VAR_ALIGNMENT_CHECK(name, aligned_size, 32);

    /** NC ALIGNED **/
    #define DEFINE_NC_ALIGNED_SHARED_VAR(type, name, aligned_size) \
                __declspec(align(aligned_size)) type name; \
                SHARED_VAR_ALIGNMENT_CHECK(name, aligned_size, (aligned_size>=32 ? 32 : 4));
    #define DEFINE_NC_ALIGNED_SHARED_ARRAY(type, name, size, aligned_size)\
                __declspec(align(aligned_size)) type name[size]; \
                SHARED_VAR_ALIGNMENT_CHECK(name, aligned_size, (aligned_size>=32 ? 32 : 4));

    #define DEFINE_NC_ALIGNED_SHARED_VAR_ASSIGN(type, name, aligned_size, ...) \
                __declspec(align(aligned_size)) type name = {__VA_ARGS__}; \
                SHARED_VAR_ALIGNMENT_CHECK(name, aligned_size, (aligned_size>=32 ? 32 : 4));
    #define DEFINE_NC_ALIGNED_SHARED_ARRAY_ASSIGN(type, name, size, aligned_size, ...) \
                __declspec(align(aligned_size)) type name[size] = {__VA_ARGS__}; \
                SHARED_VAR_ALIGNMENT_CHECK(name, aligned_size, (aligned_size>=32 ? 32 : 4));

    
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    
    /*MCU-RO & HW-RW */
    #define DEFINE_MCURO_HWRW_DNC_ALIGNED_SHARED_ARRAY(type, name, size, aligned_size)              DEFINE_NC_ALIGNED_SHARED_ARRAY(type, name, size, aligned_size)
    #define DEFINE_MCURO_HWRW_DNC_ALIGNED_SHARED_ARRAY_ASSIGN(type, name, size, aligned_size, ...)  DEFINE_NC_ALIGNED_SHARED_ARRAY_ASSIGN(type, name, size, aligned_size, ...)
    #define DEFINE_MCURO_HWRW_NC_ALIGNED_SHARED_ARRAY(type, name, size, aligned_size)               DEFINE_NC_ALIGNED_SHARED_ARRAY(type, name, size, aligned_size)
    #define DEFINE_MCURO_HWRW_NC_ALIGNED_SHARED_ARRAY_ASSIGN(type, name, size, aligned_size, ...)   DEFINE_NC_ALIGNED_SHARED_ARRAY_ASSIGN(type, name, size, aligned_size, ...)
        
    /*MCU-RW & HW-RW */
    #define DEFINE_MCURW_HWRW_DNC_ALIGNED_SHARED_ARRAY(type, name, size, aligned_size)              DEFINE_NC_ALIGNED_SHARED_ARRAY(type, name, size, aligned_size)
    #define DEFINE_MCURW_HWRW_DNC_ALIGNED_SHARED_ARRAY_ASSIGN(type, name, size, aligned_size, ...)  DEFINE_NC_ALIGNED_SHARED_ARRAY_ASSIGN(type, name, size, aligned_size, ...)
    #define DEFINE_MCURW_HWRW_NC_ALIGNED_SHARED_ARRAY(type, name, size, aligned_size)               DEFINE_NC_ALIGNED_SHARED_ARRAY(type, name, size, aligned_size)
    #define DEFINE_MCURW_HWRW_NC_ALIGNED_SHARED_ARRAY_ASSIGN(type, name, size, aligned_size, ...)   DEFINE_NC_ALIGNED_SHARED_ARRAY_ASSIGN(type, name, size, aligned_size, ...)
    



    #define DECLARE_SHARED_VAR(type, name) extern type name;
    #define DECLARE_SHARED_ARRAY(type, name, size) extern type name[size];

    #define SHARED_VAR(name) (name)
    #define SHARED_ARRAY(name) (name)
    #define SHARED_pVAR(name) (&name)
    #define SHARED_pARRAY(name) (&name)
#elif defined(__GNUC__) && defined(__PCORE__)        /* end of _MINGW32_ */
    /** DNC **/
    #define DEFINE_DNC_SHARED_VAR(type, name) \
                type name __attribute__ ((section("SHARED_BUFF_DYNAMICCACHEABLEZI_NC"), aligned(32)));
    #define DEFINE_DNC_SHARED_ARRAY(type, name, size) \
                type name[size] __attribute__ ((section("SHARED_BUFF_DYNAMICCACHEABLEZI_NC"), aligned(32)));
    #define DEFINE_RCU_DNC_SHARED_ARRAY(type, name, size) \
                type name[size] __attribute__ ((section("SHARED_BUFF_DYNAMICCACHEABLEZI_NC"), aligned(64)));

    #define DEFINE_DNC_SHARED_VAR_ASSIGN(type, name, ...)  \
                type name __attribute__ ((section("SHARED_BUFF_DYNAMICCACHEABLERW_NC"), aligned(32))) = {__VA_ARGS__};
    #define DEFINE_DNC_SHARED_ARRAY_ASSIGN(type, name, size, ...) \
                type name[size] __attribute__ ((section("SHARED_BUFF_DYNAMICCACHEABLERW_NC"), aligned(32))) = {__VA_ARGS__};

    /** NC **/
    #define DEFINE_NC_SHARED_VAR(type, name) \
                type name __attribute__ ((section("SHARED_BUFF_NONCACHEDZI"), aligned((sizeof(type)>=32 ? 32 : 4))));
    #define DEFINE_NC_SHARED_ARRAY(type, name, size) \
                type name[size] __attribute__ ((section("SHARED_BUFF_NONCACHEDZI"), aligned(((sizeof(type)*size)>=32 ? 32 : 4))));
    #define DEFINE_RCU_NC_SHARED_ARRAY(type, name, size) \
                type name[size] __attribute__ ((section("SHARED_BUFF_NONCACHEDZI"), aligned(64)));

    #define DEFINE_NC_SHARED_VAR_ASSIGN(type, name, ...)  \
                type name __attribute__ ((section("SHARED_BUFF_NONCACHEDRW"), aligned((sizeof(type)>=32 ? 32 : 4)))) = {__VA_ARGS__};
    #define DEFINE_NC_SHARED_ARRAY_ASSIGN(type, name, size, ...) \
                type name[size] __attribute__ ((section("SHARED_BUFF_NONCACHEDRW"), aligned(((sizeof(type)*size)>=32 ? 32 : 4)))) = {__VA_ARGS__};

    /** DNC ALIGNED **/
    #define DEFINE_DNC_ALIGNED_SHARED_VAR(type, name, aligned_size) \
                type name __attribute__ ((section("SHARED_BUFF_DYNAMICCACHEABLEZI_NC"), aligned(aligned_size))); \
                SHARED_VAR_ALIGNMENT_CHECK(name, aligned_size, 32);
    #define DEFINE_DNC_ALIGNED_SHARED_ARRAY(type, name, size, aligned_size) \
                type name[size] __attribute__ ((section("SHARED_BUFF_DYNAMICCACHEABLEZI_NC"), aligned(aligned_size))); \
                SHARED_VAR_ALIGNMENT_CHECK(name, aligned_size, 32);

    #define DEFINE_DNC_ALIGNED_SHARED_VAR_ASSIGN(type, name, aligned_size, ...)  \
                type name __attribute__ ((section("SHARED_BUFF_DYNAMICCACHEABLERW_NC"), aligned(aligned_size))) = {__VA_ARGS__}; \
                SHARED_VAR_ALIGNMENT_CHECK(name, aligned_size, 32);
    #define DEFINE_DNC_ALIGNED_SHARED_ARRAY_ASSIGN(type, name, size, aligned_size, ...) \
                type name[size] __attribute__ ((section("SHARED_BUFF_DYNAMICCACHEABLERW_NC"), aligned(aligned_size))) = {__VA_ARGS__}; \
                SHARED_VAR_ALIGNMENT_CHECK(name, aligned_size, 32);

    /** NC ALIGNED **/
    #define DEFINE_NC_ALIGNED_SHARED_VAR(type, name, aligned_size) \
                type name __attribute__ ((section("SHARED_BUFF_NONCACHEDZI"), aligned((aligned_size>=32 ? aligned_size : (sizeof(type)>=32 ? 32 : aligned_size))))); \
                SHARED_VAR_ALIGNMENT_CHECK(name, aligned_size, (aligned_size>=32 ? 32 : 4));
    #define DEFINE_NC_ALIGNED_SHARED_ARRAY(type, name, size, aligned_size) \
                type name[size] __attribute__ ((section("SHARED_BUFF_NONCACHEDZI"), aligned((aligned_size>=32 ? aligned_size : ((sizeof(type)*size)>=32 ? 32 : aligned_size))))); \
                SHARED_VAR_ALIGNMENT_CHECK(name, aligned_size, (aligned_size>=32 ? 32 : 4));

    #define DEFINE_NC_ALIGNED_SHARED_VAR_ASSIGN(type, name, aligned_size, ...)  \
                type name __attribute__ ((section("SHARED_BUFF_NONCACHEDRW"), aligned((aligned_size>=32 ? aligned_size : (sizeof(type)>=32 ? 32 : aligned_size))))) = {__VA_ARGS__}; \
                SHARED_VAR_ALIGNMENT_CHECK(name, aligned_size, (aligned_size>=32 ? 32 : 4));
    #define DEFINE_NC_ALIGNED_SHARED_ARRAY_ASSIGN(type, name, size, aligned_size, ...) \
                type name[size] __attribute__ ((section("SHARED_BUFF_NONCACHEDRW"), aligned((aligned_size>=32 ? aligned_size : ((sizeof(type)*size)>=32 ? 32 : aligned_size))))) = {__VA_ARGS__}; \
                SHARED_VAR_ALIGNMENT_CHECK(name, aligned_size, (aligned_size>=32 ? 32 : 4));

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
#endif

    /*MCU-RO & HW-RW */
        /** DNC ALIGNED **/
        #define DEFINE_MCURO_HWRW_DNC_ALIGNED_SHARED_ARRAY(type, name, size, aligned_size) \
                    type name[size] __attribute__ ((section("SHARED_BUFF_MCURO_HWRW_DYNAMICCACHEABLEZI_NC"), aligned(aligned_size))); \
                    SHARED_VAR_ALIGNMENT_CHECK(name, aligned_size, 32);

        #define DEFINE_MCURO_HWRW_DNC_ALIGNED_SHARED_ARRAY_ASSIGN(type, name, size, aligned_size, ...) \
                    type name[size] __attribute__ ((section("SHARED_BUFF_MCURO_HWRW_DYNAMICCACHEABLERW_NC"), aligned(aligned_size))) = {__VA_ARGS__}; \
                    SHARED_VAR_ALIGNMENT_CHECK(name, aligned_size, 32);

        /** NC ALIGNED **/
        #define DEFINE_MCURO_HWRW_NC_ALIGNED_SHARED_ARRAY(type, name, size, aligned_size) \
                    type name[size] __attribute__ ((section("SHARED_BUFF_MCURO_HWRW_NONCACHEDZI"), aligned((aligned_size>=32 ? aligned_size : ((sizeof(type)*size)>=32 ? 32 : aligned_size))))); \
                    SHARED_VAR_ALIGNMENT_CHECK(name, aligned_size, (aligned_size>=32 ? 32 : 4));

        #define DEFINE_MCURO_HWRW_NC_ALIGNED_SHARED_ARRAY_ASSIGN(type, name, size, aligned_size, ...) \
                    type name[size] __attribute__ ((section("SHARED_BUFF_MCURO_HWRW_NONCACHEDRW"), aligned((aligned_size>=32 ? aligned_size : ((sizeof(type)*size)>=32 ? 32 : aligned_size))))) = {__VA_ARGS__}; \
                    SHARED_VAR_ALIGNMENT_CHECK(name, aligned_size, (aligned_size>=32 ? 32 : 4));

    
    /*MCU-RW & HW-RW */
        /** DNC ALIGNED **/
        #define DEFINE_MCURW_HWRW_DNC_ALIGNED_SHARED_ARRAY(type, name, size, aligned_size) \
                    type name[size] __attribute__ ((section("SHARED_BUFF_MCURW_HWRW_DYNAMICCACHEABLEZI_NC"), aligned(aligned_size))); \
                    SHARED_VAR_ALIGNMENT_CHECK(name, aligned_size, 32);

        #define DEFINE_MCURW_HWRW_DNC_ALIGNED_SHARED_ARRAY_ASSIGN(type, name, size, aligned_size, ...) \
                    type name[size] __attribute__ ((section("SHARED_BUFF_MCURW_HWRW_DYNAMICCACHEABLERW_NC"), aligned(aligned_size))) = {__VA_ARGS__}; \
                    SHARED_VAR_ALIGNMENT_CHECK(name, aligned_size, 32);

        /** NC ALIGNED **/
        #define DEFINE_MCURW_HWRW_NC_ALIGNED_SHARED_ARRAY(type, name, size, aligned_size) \
                    type name[size] __attribute__ ((section("SHARED_BUFF_MCURW_HWRW_NONCACHEDZI"), aligned((aligned_size>=32 ? aligned_size : ((sizeof(type)*size)>=32 ? 32 : aligned_size))))); \
                    SHARED_VAR_ALIGNMENT_CHECK(name, aligned_size, (aligned_size>=32 ? 32 : 4));

        #define DEFINE_MCURW_HWRW_NC_ALIGNED_SHARED_ARRAY_ASSIGN(type, name, size, aligned_size, ...) \
                    type name[size] __attribute__ ((section("SHARED_BUFF_MCURW_HWRW_NONCACHEDRW"), aligned((aligned_size>=32 ? aligned_size : ((sizeof(type)*size)>=32 ? 32 : aligned_size))))) = {__VA_ARGS__}; \
                    SHARED_VAR_ALIGNMENT_CHECK(name, aligned_size, (aligned_size>=32 ? 32 : 4));


    #define DECLARE_SHARED_VAR(type, name) extern type name;
    #define DECLARE_SHARED_ARRAY(type, name, size) extern type name[size];

    #define SHARED_VAR(name) (name)
    #define SHARED_ARRAY(name) (name)
    #define SHARED_pVAR(name) (&name)
    #define SHARED_pARRAY(name) (&name)
#elif defined(__GNUC__) && defined(__L1CORE__)        /* end of __GNUC__ & __PCORE__ */
    /** DNC **/
    #define DEFINE_DNC_SHARED_VAR(type, name)                       RO_DATA_SECTION(EXTSRAM_SHARE_BUFFER) \
                                                                        extern type *p_##name; \
                                                                        type *p_##name = (type*)0xdeaddead; \
                                                                        DEFAULT_SECTION
    #define DEFINE_DNC_SHARED_ARRAY(type, name, size)               DEFINE_DNC_SHARED_VAR(type, name)
    #define DEFINE_RCU_DNC_SHARED_ARRAY(type, name, size)           DEFINE_DNC_SHARED_VAR(type, name)
    #define DEFINE_DNC_SHARED_VAR_ASSIGN(type, name, ...)           DEFINE_DNC_SHARED_VAR(type, name)
    #define DEFINE_DNC_SHARED_ARRAY_ASSIGN(type, name, size, ...)   DEFINE_DNC_SHARED_VAR(type, name)
    
    /** NC **/
    #define DEFINE_NC_SHARED_VAR(type, name)                        DEFINE_DNC_SHARED_VAR(type, name)
    #define DEFINE_NC_SHARED_ARRAY(type, name, size)                DEFINE_DNC_SHARED_VAR(type, name)
    #define DEFINE_RCU_NC_SHARED_ARRAY(type, name, size)            DEFINE_DNC_SHARED_VAR(type, name)
    #define DEFINE_NC_SHARED_VAR_ASSIGN(type, name, ...)            DEFINE_DNC_SHARED_VAR(type, name)
    #define DEFINE_NC_SHARED_ARRAY_ASSIGN(type, name, size, ...)    DEFINE_DNC_SHARED_VAR(type, name)

    /** DNC ALIGNED **/
    #define DEFINE_DNC_ALIGNED_SHARED_VAR(type, name, aligned_size)                     DEFINE_DNC_SHARED_VAR(type, name)
    #define DEFINE_DNC_ALIGNED_SHARED_ARRAY(type, name, size, aligned_size)             DEFINE_DNC_SHARED_VAR(type, name)
    #define DEFINE_DNC_ALIGNED_SHARED_VAR_ASSIGN(type, name, aligned_size, ...)         DEFINE_DNC_SHARED_VAR(type, name)
    #define DEFINE_DNC_ALIGNED_SHARED_ARRAY_ASSIGN(type, name, size, aligned_size, ...) DEFINE_DNC_SHARED_VAR(type, name)
    
    /** NC ALIGNED **/
    #define DEFINE_NC_ALIGNED_SHARED_VAR(type, name, aligned_size)                      DEFINE_DNC_SHARED_VAR(type, name)
    #define DEFINE_NC_ALIGNED_SHARED_ARRAY(type, name, size, aligned_size)              DEFINE_DNC_SHARED_VAR(type, name)
    #define DEFINE_NC_ALIGNED_SHARED_VAR_ASSIGN(type, name, aligned_size, ...)          DEFINE_DNC_SHARED_VAR(type, name)
    #define DEFINE_NC_ALIGNED_SHARED_ARRAY_ASSIGN(type, name, size, aligned_size, ...)  DEFINE_DNC_SHARED_VAR(type, name)

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    /*MCU-RO & HW-RW */
    #define DEFINE_MCURO_HWRW_DNC_ALIGNED_SHARED_ARRAY(type, name, size, aligned_size)              DEFINE_DNC_SHARED_VAR(type, name)
    #define DEFINE_MCURO_HWRW_DNC_ALIGNED_SHARED_ARRAY_ASSIGN(type, name, size, aligned_size, ...)  DEFINE_DNC_SHARED_VAR(type, name)
    #define DEFINE_MCURO_HWRW_NC_ALIGNED_SHARED_ARRAY(type, name, size, aligned_size)               DEFINE_DNC_SHARED_VAR(type, name)
    #define DEFINE_MCURO_HWRW_NC_ALIGNED_SHARED_ARRAY_ASSIGN(type, name, size, aligned_size, ...)   DEFINE_DNC_SHARED_VAR(type, name)
    
    /*MCU-RW & HW-RW */
    #define DEFINE_MCURW_HWRW_DNC_ALIGNED_SHARED_ARRAY(type, name, size, aligned_size)              DEFINE_DNC_SHARED_VAR(type, name)
    #define DEFINE_MCURW_HWRW_DNC_ALIGNED_SHARED_ARRAY_ASSIGN(type, name, size, aligned_size, ...)  DEFINE_DNC_SHARED_VAR(type, name)
    #define DEFINE_MCURW_HWRW_NC_ALIGNED_SHARED_ARRAY(type, name, size, aligned_size)               DEFINE_DNC_SHARED_VAR(type, name)
    #define DEFINE_MCURW_HWRW_NC_ALIGNED_SHARED_ARRAY_ASSIGN(type, name, size, aligned_size, ...)   DEFINE_DNC_SHARED_VAR(type, name)


    #define DECLARE_SHARED_VAR(type, name) extern type *p_##name;
    #define DECLARE_SHARED_ARRAY(type, name, size) extern type *p_##name;
    
    #define SHARED_VAR(name) (*p_##name)
    #define SHARED_ARRAY(name) (p_##name)
    #define SHARED_pVAR(name) (p_##name)
    #define SHARED_pARRAY(name) (p_##name)
#else
    #error "Unsupported Compiler in Simulator"
#endif


#endif  /* _KAL_GENERAL_TYPES_H */
