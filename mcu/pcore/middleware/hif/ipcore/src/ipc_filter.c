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

/*******************************************************************************
 * Filename:
 * ---------
 *   ipc_filter.c
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   Packet filtering.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *                 HISTORY
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "kal_public_api.h"
#include "intrCtrl.h"
#include "mw_sap.h"
#include "ipcore_upcm_struct.h"

#include "ipc_enums.h"
#include "ipc_defs.h"
#include "ipc_debug.h"
#include "ipc_utils.h"
#include "ipc_filter.h"
#include "ipcore_iph.h"
#include "qmu_bm_util.h"


#define IPC_NEXT_FILTER_MAP_SIZE    2

typedef struct _ipc_filter_t ipc_filter_t;
typedef struct _ipc_filter_t {
    IPC_DECLARE_OBJECT

    kal_int32               filter_id;
    ipc_filter_rules_t      rules;
    kal_bool                callback_with_info;
    void                   *callback_func;
    void                   *callback_context;
    module_type             module_id;
    kal_uint8               rsvd[2];
    void                   *module_context;
    ipc_filter_t           *next_filter_map[IPC_NEXT_FILTER_MAP_SIZE];
} ipc_filter_t;

typedef struct _ipc_filter_list_t {
    IPC_DECLARE_OBJECT

    kal_uint32              count;
    ipc_filter_t           *filter_head;
    kal_uint8               ip_type;
} ipc_filter_list_t;

typedef struct _ipc_packet_info_t{
	kal_uint32 info_valid_fields;
    kal_uint32 src_addr[4];
    kal_uint32 dst_addr[4];
    kal_uint16 src_port;
    kal_uint16 dst_port;
    kal_uint16 tcp_flags;
    kal_uint8 reserved[2];
    kal_uint8 icmpv4_type;
    kal_uint8 icmpv6_type;
    kal_uint8 protocol;
    kal_bool fragment;
    kal_uint32 data_offset;
}ipc_packet_info_t;

typedef enum _ipc_pkt_do_filter_result_e {
    IPC_PKT_DO_FILTER_NOT_MATCHED = 0,
    IPC_PKT_DO_FILTER_MATCHED = 1,
    IPC_PKT_DO_FILTER_INVALID_LEN = 2,
    IPC_PKT_DO_FILTER_ERROR = 3,
    IPC_PKT_DO_FILTER_NONE = 4
} ipc_pkt_do_filter_result_e;

/*------------------------------------------------------------------------------
 * Global variables.
 *----------------------------------------------------------------------------*/
kal_uint32  ipc_dl_valid_packet_len_s;
static ipc_filter_t         ipc_filter_pool_s[IPC_MAX_FILTER_CNT];
/* For downlink */
static ipc_filter_list_t    ipc_dl_v4_filter_list_s[1];
static ipc_filter_list_t    ipc_dl_v6_filter_list_s[1];
/* For uplink */
static ipc_filter_list_t    ipc_ul_v4_filter_list_s[1];
static ipc_filter_list_t    ipc_ul_v6_filter_list_s[1];
/*------------------------------------------------------------------------------
 * Helper macro.
 *----------------------------------------------------------------------------*/
#define ipc_next_filter_hash(_ip_type) \
            ((_ip_type) & 0x1)

#define _PRIORITY_OF_FILTER(_filter) (_filter->rules.priority)

#define _FEATURES_CONTAIN(_rules, _name) \
        (IPC_FILTER_FEATURE_ ## _name == ((_rules)->features & IPC_FILTER_FEATURE_ ## _name))

#define _RULES_CONTAIN(_rules, _name) \
        (IPC_FILTER_BY_ ## _name == ((_rules)->valid_fields & IPC_FILTER_BY_ ## _name))

#define _RULES_CONTAIN_IPV4(_rules) \
        (IPC_IP_TYPE_IPV4 == (_rules)->ip_type || IPC_IP_TYPE_MIXED == (_rules)->ip_type)

#define _RULES_CONTAIN_IPV6(_rules) \
        (IPC_IP_TYPE_IPV6 == (_rules)->ip_type || IPC_IP_TYPE_MIXED == (_rules)->ip_type)

#define _IS_UNSUPPORTED_PROTOCOL(_protocol) \
        ((IPC_HDR_PROT_UDP != (_protocol)) && (IPC_HDR_PROT_TCP != (_protocol)) && (IPC_HDR_PROT_ICMP != (_protocol)) && (IPC_HDR_PROT_ICMPV6 != (_protocol)))

/*------------------------------------------------------------------------------
 * Private function.
 *----------------------------------------------------------------------------*/
kal_bool
ipc_validate_rules(
    kal_bool                uplink,
    ipc_filter_rules_t     *rules)
{
    if (_FEATURES_CONTAIN(rules, WC)) {
        /* Pass other checking if it's WC filter. */
        return KAL_TRUE;
    }

    if (0 == rules->valid_fields) {
        hif_trace_error(IPC_TR_INVALID_RULES_ZERO_VALID_FIELD);
        return KAL_FALSE;
    }

    if (    (KAL_TRUE == uplink) &&
            (   _RULES_CONTAIN(rules, EBI)      /* EBI is used for downlink filter only */ ||
                _RULES_CONTAIN(rules, PDN_ID)   /* PDN ID is used in downlink filter only */)
        ) {
        hif_trace_error(IPC_TR_INVALID_RULES_FOR_UL, uplink, rules->valid_fields, rules->ip_type);
        return KAL_FALSE;        
    }

    if ( (IPC_IP_TYPE_IPV4 == rules->ip_type) &&
         (( (KAL_TRUE == uplink) ||
            ((KAL_FALSE == uplink)&& !_RULES_CONTAIN(rules, EBI))) && 
          !_RULES_CONTAIN(rules, NETIF_ID) &&
          !_RULES_CONTAIN(rules, PROTOCOL) &&
          !_RULES_CONTAIN(rules, SRC_PORT) && !_RULES_CONTAIN(rules, DST_PORT) &&
          !_RULES_CONTAIN(rules, SRC_IPV4) && !_RULES_CONTAIN(rules, DST_IPV4) &&
          !_RULES_CONTAIN(rules, ICMPV4_TYPE)) ) {
        hif_trace_error(IPC_TR_INVALID_RULES_FOR_IPV4, uplink, rules->valid_fields, rules->ip_type);
        return KAL_FALSE;
    }

    if ( (IPC_IP_TYPE_IPV6 == rules->ip_type) &&
         (( (KAL_TRUE == uplink) ||
            ((KAL_FALSE == uplink)&& !_RULES_CONTAIN(rules, EBI))) && 
          !_RULES_CONTAIN(rules, NETIF_ID) &&
          !_RULES_CONTAIN(rules, PROTOCOL) &&
          !_RULES_CONTAIN(rules, SRC_PORT) && !_RULES_CONTAIN(rules, DST_PORT) &&
          !_RULES_CONTAIN(rules, SRC_IPV6) && !_RULES_CONTAIN(rules, DST_IPV6) &&
          !_RULES_CONTAIN(rules, ICMPV6_TYPE)) ) {
        hif_trace_error(IPC_TR_INVALID_RULES_FOR_IPV6, uplink, rules->valid_fields, rules->ip_type);
        return KAL_FALSE;
    }
 
    if ( _RULES_CONTAIN(rules, PROTOCOL) && _IS_UNSUPPORTED_PROTOCOL(rules->protocol) ) {
        hif_trace_error(IPC_TR_INVALID_RULES_FOR_UNSUPPORTED_PROTOCOL, rules->protocol);
        return KAL_FALSE;
    }

    return KAL_TRUE;
}

ipc_filter_t *
ipc_new_filter(
    ipc_filter_t           *filter_pool,
    kal_uint32              pool_size,
    ipc_filter_rules_t     *rules,
    kal_bool                callback_with_info,
    void                   *callback_func,
    void                   *callback_context,
    module_type             module_id)
{
    ipc_filter_t    *filter;
    kal_uint32       idx;
    kal_uint32       mask;

   if ( (NULL == rules) ||
        (!_FEATURES_CONTAIN(rules, BWM) && NULL == callback_func && MOD_NIL == module_id) ) {
        hif_trace_error(IPC_TR_NEW_FILTER_INVALID_PARAMS, rules, callback_func, module_id);
        return NULL;
    }

    for (idx = 0; idx < pool_size; idx++) {
        filter = filter_pool + idx;

        if (!IPC_IS_VALID_OBJECT(filter)) {
            IPC_INIT_OBJECT_BEGIN(filter, mask);

            filter->filter_id = idx;

            kal_mem_cpy( &(filter->rules), rules, sizeof(*rules) );
        #ifdef __MULTIPLE_PS__
            IPC_MASK_PROTOID_ON_PDNID(filter->rules.pdn_id, filter->rules.proto_idx);
            IPC_MASK_PROTOID_ON_PDNID(filter->rules.ebi, filter->rules.proto_idx);
        #endif
            filter->callback_with_info = callback_with_info;
            filter->callback_func = callback_func;
            filter->module_id = module_id;
            if (MOD_NIL == module_id) {
                filter->callback_context = callback_context;
                filter->module_context = NULL;
            } else {
                filter->callback_context = filter;
                filter->module_context = callback_context;
            }

            kal_mem_set(filter->next_filter_map, 0, sizeof(filter->next_filter_map));
            IPC_INIT_OBJECT_END(filter, mask);
            return filter;
        }
    }
    hif_trace_error(IPC_TR_NEW_FILTER_UNAVAILABLE);
    return NULL;
}

void
ipc_del_filter(
    ipc_filter_t    *filter)
{
    kal_uint32  mask;

    if (IPC_IS_VALID_OBJECT(filter)) {
        IPC_DEINIT_OBJECT_BEGIN(filter, mask);
        IPC_DEINIT_OBJECT_END(filter, mask);
    } else {
        hif_trace_error(IPC_TR_DEL_FILTER_INVALID_OBJECT, filter);
    }
}

ipc_filter_t *
ipc_find_filter_by_id(
    ipc_filter_t           *filter_pool,
    kal_int32               filter_id)
{
    IPC_ASSERT(0 <= filter_id && IPC_MAX_FILTER_CNT > filter_id);
    return (filter_pool + filter_id);
}

void
ipc_add_filter_to_list(
    ipc_filter_list_t   *list,
    ipc_filter_t        *filter,
    kal_uint8            ip_type)
{
    kal_uint32      mask;
    ipc_filter_t   *curr_filter;
    ipc_filter_t   *prev_filter;

    prev_filter = NULL;
    IPC_R_LOCK_OBJECT(list, mask);
    if (list) {
        if (!list->filter_head) {
            IPC_R_TO_W_LOCK_OBJECT(list, mask);
            if (list) {
                list->filter_head = filter;
                list->count++;
                IPC_W_TO_R_LOCK_OBJECT(list, mask);
            }
        } else {
            curr_filter = list->filter_head;
            while (curr_filter) {
                IPC_R_LOCK_OBJECT(curr_filter, mask);
                if (curr_filter) {
                    if (_PRIORITY_OF_FILTER(curr_filter) >= _PRIORITY_OF_FILTER(filter)) {
                        /* Insert the filter to this position. */
                        if (prev_filter) {
                            /* It's not the head of the list. */
                            IPC_R_TO_W_LOCK_OBJECT(prev_filter, mask);
                            if (prev_filter) {
                                filter->next_filter_map[ipc_next_filter_hash(ip_type)] = curr_filter;
                                prev_filter->next_filter_map[ipc_next_filter_hash(ip_type)] = filter;
                                IPC_W_UNLOCK_OBJECT(prev_filter, mask);

                                IPC_R_TO_W_LOCK_OBJECT(list, mask);
                                if (list) {
                                    list->count++;
                                    IPC_W_TO_R_LOCK_OBJECT(list, mask);
                                }
                            }

                        } else {
                            /* Insert to the head of the list. */
                            IPC_R_TO_W_LOCK_OBJECT(list, mask);
                            if (list) {
                                filter->next_filter_map[ipc_next_filter_hash(ip_type)] = curr_filter;
                                list->filter_head = filter;
                                list->count++;
                                IPC_W_TO_R_LOCK_OBJECT(list, mask);
                            }
                        }
                        IPC_R_UNLOCK_OBJECT(curr_filter, mask);
                        break;
                    } else if (!curr_filter->next_filter_map[ipc_next_filter_hash(ip_type)]) {
                        /* The current filter is the last one. Insert the filter after it. */
                        if (prev_filter) {
                            IPC_R_UNLOCK_OBJECT(prev_filter, mask);
                        }
                        IPC_R_TO_W_LOCK_OBJECT(curr_filter, mask);
                        if (curr_filter) {
                            curr_filter->next_filter_map[ipc_next_filter_hash(ip_type)] = filter;
                            IPC_W_UNLOCK_OBJECT(curr_filter, mask);

                            IPC_R_TO_W_LOCK_OBJECT(list, mask);
                            if (list) {
                                list->count++;
                                IPC_W_TO_R_LOCK_OBJECT(list, mask);
                            }
                        }
                        break;
                    } else {
                        /* Keep searching */
                        if (prev_filter) {
                            IPC_R_UNLOCK_OBJECT(prev_filter, mask);
                        }
                        prev_filter = curr_filter;
                        curr_filter = curr_filter->next_filter_map[ipc_next_filter_hash(ip_type)];
                    }
                } else {
                    IPC_ASSERT(KAL_FALSE);
                }
            }
        }

        IPC_R_UNLOCK_OBJECT(list, mask);
    } else {
        IPC_ASSERT(KAL_FALSE);
    }
}

void
ipc_remove_filter_from_list(
    ipc_filter_list_t   *list,
    ipc_filter_t        *filter,
    kal_uint8            ip_type)
{
    kal_uint32      mask;
    ipc_filter_t   *curr_filter;
    ipc_filter_t   *prev_filter;

    prev_filter = NULL;
    IPC_R_LOCK_OBJECT(list, mask);
    if (list) {
        curr_filter = list->filter_head;
        while (curr_filter) {
            IPC_R_LOCK_OBJECT(curr_filter, mask);
            if (curr_filter) {
                if (curr_filter == filter) {
                    /* Found the filter! */
                    if (prev_filter) {
                        /* It's not the head of the list. */
                        IPC_R_TO_W_LOCK_OBJECT(prev_filter, mask);
                        if (prev_filter) {
                            prev_filter->next_filter_map[ipc_next_filter_hash(ip_type)] = curr_filter->next_filter_map[ipc_next_filter_hash(ip_type)];
                            IPC_W_UNLOCK_OBJECT(prev_filter, mask);

                            IPC_R_TO_W_LOCK_OBJECT(list, mask);
                            if (list) {
                                list->count--;
                                IPC_W_TO_R_LOCK_OBJECT(list, mask);
                            }
                        }
                    } else {
                        /* Remove the head of the list. */
                        IPC_R_TO_W_LOCK_OBJECT(list, mask);
                        if (list) {
                            list->filter_head = curr_filter->next_filter_map[ipc_next_filter_hash(ip_type)];
                            list->count--;
                            IPC_W_TO_R_LOCK_OBJECT(list, mask);
                        }
                    }
                    IPC_R_UNLOCK_OBJECT(curr_filter, mask);
                    break;
                } else {
                    /* Keep searching */
                    if (prev_filter) {
                        IPC_R_UNLOCK_OBJECT(prev_filter, mask);
                    }
                    prev_filter = curr_filter;
                    curr_filter = curr_filter->next_filter_map[ipc_next_filter_hash(ip_type)];
                }
            } else {
                IPC_ASSERT(KAL_FALSE);
            }
        }

        IPC_R_UNLOCK_OBJECT(list, mask);
    } else {
        IPC_ASSERT(KAL_FALSE);
    }
}

kal_bool
ipc_get_ip_packet(
    qbm_gpd        *desc,   /* GPD to get IP header */
    qbm_gpd       **bd,     /* BD of IP header pointer (NULL if not exist) */
    kal_uint8     **buffer, /* IP header pointer */
    kal_uint32     *length  /* GPD total length */)
{
    IPC_ASSERT(desc);
    IPC_ASSERT(bd);
    IPC_ASSERT(buffer);
    IPC_ASSERT(length);

    *bd = NULL;
    *length = QBM_DES_GET_DATALEN(desc);

    if (QBM_DES_GET_BDP(desc)) {
        desc = (qbm_gpd *)QBM_DES_GET_DATAPTR(desc);
        while (0 == QBM_DES_GET_DATALEN(desc)) {
            if (!QBM_DES_GET_EOL(desc)) {
                desc = (qbm_gpd *)QBM_DES_GET_NEXT(desc);
            } else {
                IPC_ASSERT(KAL_FALSE);
                return KAL_FALSE;
            }
        }
        /* Found : record BD pointer */
        *bd = desc;
    }

    *buffer = (kal_uint8*)QBM_DES_GET_DATAPTR(desc);

    return KAL_TRUE;
}

/*!
 * Get new address in GPD with shift for specific offset.
 *
 * @param   base_addr_p [IN] Basic address pointer from GPD/BD payload content.
 * @param   gpd [IN] GPD of input packet.
 * @param   base_bd [IN] Corresponding BD for base_addr_p. It might be NULL if the GPD does not have BD list.
 * @param   offset [IN] Offset to shift.
 * @param   offset_addr_pp [OUT] Pointer of packet content after shift.
 * @param   offset_bd_p [OUT] Pointer of corresponding BD for *offset_addr_pp.
 *
 * @return KAL_TRUE if the process is success.
 * @return KAL_FALSE if the process is failed.
 */
static INLINE kal_bool
ipc_shift_gpd_content_ptr(
    kal_uint8  *base_addr_p,
    qbm_gpd    *gpd,
    qbm_gpd    *base_bd,
    kal_uint32  offset,
    kal_uint8 **offset_addr_pp,
    qbm_gpd   **offset_bd_p
)
{

    IPC_ASSERT(base_addr_p);
    IPC_ASSERT(gpd);
    IPC_ASSERT(offset_addr_pp);
    IPC_ASSERT(offset_bd_p);

    if (NULL == base_bd)
    {
        *offset_addr_pp = (kal_uint8*)(base_addr_p + offset);
        *offset_bd_p = NULL;
    } else
    {        
        kal_uint32  remaining_offset;
        kal_uint32  remaining_bd_length;
        kal_uint8  *offset_addr_p;
        qbm_gpd    *curr_bd;

        curr_bd = base_bd;
        offset_addr_p = base_addr_p;
        remaining_offset = offset;
        remaining_bd_length = (kal_uint32)QBM_DES_GET_DATALEN(curr_bd) - (kal_uint32)(base_addr_p - (kal_uint8*)QBM_DES_GET_DATAPTR(curr_bd));

        while (remaining_offset)
        {
            if (remaining_offset <= remaining_bd_length)
            {   /* Found */
                offset_addr_p = (kal_uint8*)(offset_addr_p + remaining_offset);
                remaining_offset = 0;
            } else
            {
                if (!QBM_DES_GET_EOL(curr_bd))
                {
                    remaining_offset = remaining_offset - remaining_bd_length;

                    /* Shift to next BD and get information for next loop */
                    curr_bd = (qbm_gpd *)QBM_DES_GET_NEXT(curr_bd);
                    remaining_bd_length = QBM_DES_GET_DATALEN(curr_bd);
                    offset_addr_p = (kal_uint8*)QBM_DES_GET_DATAPTR(curr_bd);
                } else
                {
                    hif_trace_error(IPC_TR_SHIFT_OFFSET_FAILED, gpd, base_bd, curr_bd, QBM_DES_GET_DATALEN(curr_bd), remaining_offset, base_addr_p, offset);
                    goto process_failed;

                }
            }
        }
        IPC_ASSERT(offset_addr_p);

        /* Set return values */
        *offset_addr_pp = offset_addr_p;
        *offset_bd_p = curr_bd;
    }

    return KAL_TRUE;

process_failed:
    return KAL_FALSE;
}

/*!
 * Return pointer with "continous content" with specific length.
 * If original GPD/BD is already continuous within gotten length, this procedure will return pointer from it.
 * If packet content of original GPD/BD is divided in multiple pieces, this procedure will use "cont_addr_p" buffer to collect continous content to return.
 *
 * @param   base_addr_p [IN] Basic address pointer from GPD/BD payload content.
 * @param   offset [IN] Offset to get payload content.
 * @param   gpd [IN] GPD of input packet.
 * @param   base_bd [IN] Corresponding BD for base_addr_p. It might be NULL if the GPD does not have BD list.
 * @param   length [IN] Length of return continuous content.
 * @param   cont_addr_pp [OUT] Pointer of returned continuous content. It might point to GPD payload or cont_buff_p if process SUCCESS.
 * @param   cont_buff_p [IN] Alternative buffer used if GPD content is not continuous. Caller should guarantee its size >= length.
 *
 * @return KAL_TRUE if the process is success.
 * @return KAL_FALSE if the process is failed.
 */
static INLINE kal_bool
ipc_get_continuous_content(
    kal_uint8  *base_addr_p,
    kal_uint32  offset,
    qbm_gpd    *gpd,
    qbm_gpd    *base_bd,
    kal_uint32  length,
    kal_uint8 **cont_addr_pp,
    kal_uint8  *cont_buff_p
)
{
    IPC_ASSERT(base_addr_p);
    IPC_ASSERT(gpd);
    IPC_ASSERT(cont_addr_pp);
    IPC_ASSERT(cont_buff_p);

    *cont_addr_pp = NULL;

    /* Decide whether original GPD/BD can provide continuous content */
    /* ----------------------------------------------------- */
    if (NULL == base_bd)
    {   /* This packet is single GPD and content is continuous */
        goto org_buff_is_continuous;
    }

    if ((kal_uint32)QBM_DES_GET_DATALEN(base_bd) >= ((kal_uint32)((kal_uint8*)base_addr_p - (kal_uint8*)QBM_DES_GET_DATAPTR(base_bd)) + offset + length))
    {   /* This BD is enough to support continuous content */
        goto org_buff_is_continuous;
    }

    /* Using alternative buffer (cont_buff_p) */
    /* ----------------------------------------------------- */

    /* Copy content to alternative buffer */
    {
        kal_uint8  *data_src_p;
        kal_uint8  *data_dst_p;
        qbm_gpd    *curr_bd;

        data_dst_p = cont_buff_p;
        curr_bd = base_bd;

        /* Find data source pointer */
        if (KAL_TRUE != ipc_shift_gpd_content_ptr(base_addr_p, gpd, curr_bd, offset, &data_src_p, &curr_bd))
        {
            hif_trace_error(IPC_TR_CONTENT_LENGTH_TOO_SHORT, gpd, base_bd, curr_bd, base_addr_p, offset, length);
            goto process_failed;
        }
        IPC_ASSERT(data_src_p);

        /* Copy data from source (BD list) to destination (single buffer) */
        {
            kal_uint32 remaining_length;
            kal_uint32 remaining_bd_length;

            remaining_length = length;
            remaining_bd_length = (kal_uint32)QBM_DES_GET_DATALEN(curr_bd) - (kal_uint32)(data_src_p - (kal_uint8*)QBM_DES_GET_DATAPTR(curr_bd));

            while (remaining_length)
            {
                if (remaining_length <= remaining_bd_length)
                {   /* Latest copy */
					QBM_CACHE_INVALID(data_src_p, remaining_length);
                    kal_mem_cpy(data_dst_p, data_src_p, remaining_length);
                    remaining_length = 0;
                } else
                {
					QBM_CACHE_INVALID(data_src_p, remaining_bd_length);
                    kal_mem_cpy(data_dst_p, data_src_p, remaining_bd_length);
                    data_dst_p = (kal_uint8*)(data_dst_p + remaining_bd_length);

                    if (!QBM_DES_GET_EOL(curr_bd))
                    {
                        remaining_length = remaining_length - remaining_bd_length;

                        /* Shift to next BD and get information for next loop */
                        curr_bd = (qbm_gpd *)QBM_DES_GET_NEXT(curr_bd);
                        remaining_bd_length = QBM_DES_GET_DATALEN(curr_bd);
                        data_src_p = (kal_uint8*)QBM_DES_GET_DATAPTR(curr_bd);
                    } else
                    {
                        hif_trace_error(IPC_TR_CONTENT_LENGTH_TOO_SHORT_TO_COPY, gpd, base_bd, curr_bd, QBM_DES_GET_DATALEN(curr_bd), remaining_length, base_addr_p, offset, length);
                        goto process_failed;
                    }
                }
            }
        }
    }

    /* continuous buffer is from cont_buff_p and return TRUE */
    *cont_addr_pp = cont_buff_p;

    return KAL_TRUE;

org_buff_is_continuous:
	QBM_CACHE_INVALID((kal_uint8*)(base_addr_p + offset), length);
    *cont_addr_pp = (kal_uint8*)(base_addr_p + offset);
    return KAL_TRUE;

process_failed:
    return KAL_FALSE;   
}

static INLINE kal_bool
ipc_match_ipv4_rules(
    ipc_filter_rules_t *rules,
    ipc_packet_info_t *content)
{
    /* << Start to compare multi-byte IPv4 header content, content dividing issue need to handle >> */
    /* --------------------------------------------------------------------------------------- */

    if (_RULES_CONTAIN(rules, SRC_IPV4))
    {
        if (!(content->info_valid_fields & IPC_FILTER_BY_SRC_IPV4))
        {
            return KAL_FALSE;
        }
    
        /* Compare content */
        if (content->src_addr[0] != rules->src_ipv4.addr32)// uint32 compare
        {
            return KAL_FALSE;
        }
    }

    if (_RULES_CONTAIN(rules, DST_IPV4))
    {
        if (!(content->info_valid_fields & IPC_FILTER_BY_DST_IPV4))
        {
            return KAL_FALSE;
        }
    
        /* Compare content */
        if (content->dst_addr[0] != rules->dst_ipv4.addr32)// uint32 compare    
        {
            return KAL_FALSE;
        }
    }

    if (_RULES_CONTAIN(rules, PROTOCOL))
    {
        if (!(content->info_valid_fields & IPC_FILTER_BY_PROTOCOL))
        {
            return KAL_FALSE;
        }
    
        if (    /* Protocol not match */
                (content->protocol != rules->protocol) ||
                /* Is Fragmentation packet */
                content->fragment)
        {
            return KAL_FALSE;
        }

        /* L4 packet content */
        switch (rules->protocol)
        {
            case IPC_HDR_PROT_UDP:
            case IPC_HDR_PROT_TCP:    
            {
                /* -------------------------------------------------------------------------------------- */

                if (_RULES_CONTAIN(rules, SRC_PORT))
                {
                    if (!(content->info_valid_fields & IPC_FILTER_BY_SRC_PORT))
                    {
                        return KAL_FALSE;
                    }

                    /* Compare content */
                    if (content->src_port != rules->src_port)
                    {
                        return KAL_FALSE;
                    }
                }                
                if (_RULES_CONTAIN(rules, DST_PORT))
                {
                    if (!(content->info_valid_fields & IPC_FILTER_BY_DST_PORT))
                    {
                        return KAL_FALSE;
                    }

                    /* Compare content */                
                    if (content->dst_port != rules->dst_port)
                    {
                        return KAL_FALSE;
                    }
                }
                if (_RULES_CONTAIN(rules, TCP_FLAGS)) {
                    if (  (IPC_HDR_PROT_TCP != rules->protocol) ||
                         !(content->info_valid_fields & IPC_FILTER_BY_TCP_FLAGS) ) {
                        return KAL_FALSE;
                    }

                    /* Compare content */
                    if (content->tcp_flags != rules->tcp_flags)
                    {
                        return KAL_FALSE;
                    }
                }

                /* -------------------------------------------------------------------------------------- */
                break;
            }
            case IPC_HDR_PROT_ICMP:
            {
                /* -------------------------------------------------------------------------------------- */

                if (_RULES_CONTAIN(rules, ICMPV4_TYPE))
                {
                    if (!(content->info_valid_fields & IPC_FILTER_BY_ICMPV4_TYPE))
                    {
                        return KAL_FALSE;
                    }
                    
                    /* Compare content */
                    if (content->icmpv4_type != rules->icmpv4_type)
                    {
                        return KAL_FALSE;
                    }
                }

                /* -------------------------------------------------------------------------------------- */
                break;
            }
            default:
                /* No L4 content checking rule, pass it directly */
                break;
        }
    }

    return KAL_TRUE;
}

static INLINE kal_bool
ipc_match_ipv6_rules(
    ipc_filter_rules_t *rules,
    ipc_packet_info_t *content)
{
    /* << Start to compare multi-byte IPv4 header content, content dividing issue need to handle >> */
    /* --------------------------------------------------------------------------------------- */

    if (_RULES_CONTAIN(rules, SRC_IPV6))
    {
        if (!(content->info_valid_fields & IPC_FILTER_BY_SRC_IPV6))
        {
            return KAL_FALSE;
        }
    
        /* Compare content */
        if (content->src_addr[0] != rules->src_ipv6.addr32[0])// uint32 compare
        {    
            return KAL_FALSE;
        }
        if (content->src_addr[1] != rules->src_ipv6.addr32[1])// uint32 compare
        {     
            return KAL_FALSE;
        }
        if (content->src_addr[2] != rules->src_ipv6.addr32[2])// uint32 compare
        {       
            return KAL_FALSE;
        }
        if (content->src_addr[3] != rules->src_ipv6.addr32[3])// uint32 compare
        {       
            return KAL_FALSE;
        }
    }

    if (_RULES_CONTAIN(rules, DST_IPV6))
    {
        if (!(content->info_valid_fields & IPC_FILTER_BY_DST_IPV6))
        {
            return KAL_FALSE;
        }
    
        /* Compare content */
        if (content->dst_addr[0] != rules->dst_ipv6.addr32[0])// uint32 compare    
        {       
            return KAL_FALSE;
        }
        if (content->dst_addr[1] != rules->dst_ipv6.addr32[1])// uint32 compare
        {          
            return KAL_FALSE;
        }
        if (content->dst_addr[2] != rules->dst_ipv6.addr32[2])// uint32 compare
        {       
            return KAL_FALSE;
        } 
        if (content->dst_addr[3] != rules->dst_ipv6.addr32[3])// uint32 compare
        {       
            return KAL_FALSE;
        }
    }

    if (_RULES_CONTAIN(rules, PROTOCOL))
    {
        if (!(content->info_valid_fields & IPC_FILTER_BY_PROTOCOL))
        {
            return KAL_FALSE;
        }
    
        if (content->protocol != rules->protocol)/* Protocol not match */
        {
            return KAL_FALSE;
        }

        /* L4 packet content */
        switch (rules->protocol)
        {
            case IPC_HDR_PROT_UDP:
            case IPC_HDR_PROT_TCP:    
            {
                /* -------------------------------------------------------------------------------------- */

                if (_RULES_CONTAIN(rules, SRC_PORT))
                {
                    if (!(content->info_valid_fields & IPC_FILTER_BY_SRC_PORT))
                    {
                        return KAL_FALSE;
                    }

                    /* Compare content */
                    if (content->src_port != rules->src_port)
                    {
                        return KAL_FALSE;
                    }
                }                
                if (_RULES_CONTAIN(rules, DST_PORT))
                {
                    if (!(content->info_valid_fields & IPC_FILTER_BY_DST_PORT))
                    {
                        return KAL_FALSE;
                    }

                    /* Compare content */
                    if (content->dst_port != rules->dst_port)
                    {
                        return KAL_FALSE;
                    }
                }
                if (_RULES_CONTAIN(rules, TCP_FLAGS)) {
                    if (  (IPC_HDR_PROT_TCP != rules->protocol) ||
                         !(content->info_valid_fields & IPC_FILTER_BY_TCP_FLAGS) ) {
                        return KAL_FALSE;
                    }

                    /* Compare content */
                    if (content->tcp_flags != rules->tcp_flags)
                    {
                        return KAL_FALSE;
                    }
                }

                /* -------------------------------------------------------------------------------------- */
                break;
            }
            case IPC_HDR_PROT_ICMPV6:
            {
                /* -------------------------------------------------------------------------------------- */

                if (_RULES_CONTAIN(rules, ICMPV6_TYPE))
                {
                    if (!(content->info_valid_fields & IPC_FILTER_BY_ICMPV6_TYPE))
                    {
                        return KAL_FALSE;
                    }

                    /* Compare content */
                    if (content->icmpv6_type != rules->icmpv6_type)
                    {
                        return KAL_FALSE;
                    }
                }

                /* -------------------------------------------------------------------------------------- */
                break;
            }
            default:
                /* No L4 content checking rule, pass it directly */
                break;
        }
    }

    return KAL_TRUE;
}

/*------------------------------------------------------------------------------
 * Public fucntions.
 *----------------------------------------------------------------------------*/
void ipc_filter_init(void)
{
    kal_uint32  mask;
    kal_uint32  idx;
    static ipc_filter_list_t  *fls_v4_set[] = {ipc_ul_v4_filter_list_s, ipc_dl_v4_filter_list_s};
    static ipc_filter_list_t  *fls_v6_set[] = {ipc_ul_v6_filter_list_s, ipc_dl_v6_filter_list_s};

#if defined(__MTK_TARGET__)
    IPC_ASSERT(sizeof(ipc_filter_t) % 4 == 0);
    IPC_ASSERT(sizeof(ipc_filter_list_t) % 4 == 0);
#endif

    kal_mem_set( ipc_filter_pool_s, 0, sizeof(ipc_filter_pool_s) );

    for (idx = 0; idx < sizeof(fls_v4_set) / sizeof(ipc_filter_list_t*); idx++) {
        kal_mem_set( fls_v4_set[idx], 0, sizeof(ipc_filter_list_t) );
        fls_v4_set[idx]->ip_type = IPC_IP_TYPE_IPV4;
        IPC_INIT_OBJECT_BEGIN( fls_v4_set[idx], mask );
        IPC_INIT_OBJECT_END( fls_v4_set[idx], mask );
    }
    for (idx = 0; idx < sizeof(fls_v6_set) / sizeof(ipc_filter_list_t*); idx++) {
        kal_mem_set( fls_v6_set[idx], 0, sizeof(ipc_filter_list_t) );
        fls_v6_set[idx]->ip_type = IPC_IP_TYPE_IPV6;
        IPC_INIT_OBJECT_BEGIN( fls_v6_set[idx], mask );
        IPC_INIT_OBJECT_END( fls_v6_set[idx], mask );
    }
}

kal_int32
ipc_register_filter(
    kal_bool                uplink,
    kal_bool                callback_with_info,
    ipc_filter_rules_t     *rules,
    void                   *callback_func,
    void                   *callback_context,
    module_type             module_id)
{
    ipc_filter_t   *filter;
    kal_bool        with_ipv4;
    kal_bool        with_ipv6;

    if (!ipc_validate_rules(uplink, rules)) {
        hif_trace_error(IPC_TR_REGISTER_FILTER_VALIDATE_FAIL, uplink);
        ipc_ut_set_error(IPC_UT_REGISTER_FILTER_VALIDATE_FAIL);
        return -1;
    }

    filter = ipc_new_filter(
                ipc_filter_pool_s,
                IPC_MAX_FILTER_CNT,
                rules,
                callback_with_info,
                callback_func,
                callback_context,
                module_id);
    if (filter) {
        /* WC filter should be added to both lists (ipv4 & ipv6). */
        with_ipv4 = _RULES_CONTAIN_IPV4(rules) || _FEATURES_CONTAIN(rules, WC);
        with_ipv6 = _RULES_CONTAIN_IPV6(rules) || _FEATURES_CONTAIN(rules, WC);
        hif_trace_info(IPC_TR_REGISTER_FILTER_OK, uplink, filter->filter_id, rules->features, rules->ip_type, rules->valid_fields, with_ipv4, with_ipv6);

        IPC_ASSERT( 0 < _PRIORITY_OF_FILTER(filter) &&
                    _PRIORITY_OF_FILTER(filter) < (KAL_TRUE == uplink)? NUM_OF_IPC_UL_FILTER:
                                                                        NUM_OF_IPC_DL_FILTER );

        if (with_ipv4) {
            ipc_add_filter_to_list(
                (KAL_TRUE == uplink)?  ipc_ul_v4_filter_list_s:
                                       ipc_dl_v4_filter_list_s,
                filter, IPC_IP_TYPE_IPV4);
            hif_trace_info(IPC_TR_REGISTER_FILTER_ADD_TO_LIST, filter->filter_id, 4, uplink);
        }
        if (with_ipv6) {
            ipc_add_filter_to_list(
                (KAL_TRUE == uplink)?   ipc_ul_v6_filter_list_s:
                                        ipc_dl_v6_filter_list_s,
                filter, IPC_IP_TYPE_IPV6);
            hif_trace_info(IPC_TR_REGISTER_FILTER_ADD_TO_LIST, filter->filter_id, 6, uplink);
        }
        return filter->filter_id;
    } else {
        hif_trace_info(IPC_TR_REGISTER_FILTER_NG);
        ipc_ut_set_error(IPC_UT_REGISTER_FILTER_NG);
        return -1;
    }
}

void
ipc_deregister_filter(
    kal_int32      filter_id)
{
    ipc_filter_t   *filter;
    ipc_filter_rules_t *rules;
    kal_bool        with_ipv4;
    kal_bool        with_ipv6;
    kal_uint32      mask;

    if (0 > filter_id || IPC_MAX_FILTER_CNT <= filter_id) {
        hif_trace_error(IPC_TR_DEREGISTER_FILTER_WITH_INVALID_ID, filter_id);
        ipc_ut_set_error(IPC_UT_DEREGISTER_FILTER_WITH_INVALID_ID);
        return;
    }

    filter = ipc_find_filter_by_id(ipc_filter_pool_s, filter_id);
    IPC_R_LOCK_OBJECT(filter, mask);
    if (filter) {
        rules = &(filter->rules);
        with_ipv4 = _RULES_CONTAIN_IPV4(rules) || _FEATURES_CONTAIN(rules, WC);
        with_ipv6 = _RULES_CONTAIN_IPV6(rules) || _FEATURES_CONTAIN(rules, WC);
        hif_trace_info(IPC_TR_DEREGISTER_FILTER_INFO, filter->filter_id, rules->features, rules->valid_fields, with_ipv4, with_ipv6);

        if (with_ipv4) {
            /* Remove from UL filter list */
            ipc_remove_filter_from_list(ipc_ul_v4_filter_list_s, filter, IPC_IP_TYPE_IPV4);
            /* Remove from DL filter list */
            ipc_remove_filter_from_list(ipc_dl_v4_filter_list_s, filter, IPC_IP_TYPE_IPV4);
            hif_trace_info(IPC_TR_REMOVE_DL_FILTER_FROM_LIST, filter->filter_id, 4);
        }
        if (with_ipv6) {
            /* Remove from UL filter list */
            ipc_remove_filter_from_list(ipc_ul_v6_filter_list_s, filter, IPC_IP_TYPE_IPV6);
            /* Remove from DL filter list */
            ipc_remove_filter_from_list(ipc_dl_v6_filter_list_s, filter, IPC_IP_TYPE_IPV6);
            hif_trace_info(IPC_TR_REMOVE_DL_FILTER_FROM_LIST, filter->filter_id, 6);
        }

        IPC_R_UNLOCK_OBJECT(filter, mask);
        ipc_del_filter(filter);
    } else {
        hif_trace_error(IPC_TR_DEREGISTER_FILTER_NOT_FOUND, filter_id);
        ipc_ut_set_error(IPC_UT_DEREGISTER_FILTER_NOT_FOUND);
    }
}

static INLINE void
ipc_gpd_unite(
    kal_bool    uplink,
    qbm_gpd     *p_gpd_in,
    qbm_gpd     **pp_gpd_out)
{
    IPC_ASSERT(p_gpd_in);
    IPC_ASSERT(pp_gpd_out);

    /*
        *   =============================================================
        *   Check if this GPD is needed to unite:
        *
        *   1. This GPD has BD list.
        *   2. First BD (containing data) does not have full data within it.
        *   =============================================================
        */
    {
        qbm_gpd* bd;

        if (!QBM_DES_GET_BDP(p_gpd_in))
        {
            goto no_change;
        }

        /* get 1st bd data ptr */
        bd = QBM_DES_GET_DATAPTR(p_gpd_in);

        /* Loop to trace 1st DL BD with data buffer */
        while (bd && (QBM_DES_GET_DATALEN(bd) == 0))
        {
            bd = (QBM_DES_GET_EOL(bd))?(NULL):((qbm_gpd*)QBM_DES_GET_NEXT(bd));
        }

        /* No any BD have data */
        if (NULL == bd)
        {
            hif_trace_error(IPC_TR_GPD_UNITE_NULL_BD_LIST, uplink, p_gpd_in);
            goto no_change;
        }

        if (QBM_DES_GET_DATALEN(p_gpd_in) == QBM_DES_GET_DATALEN(bd))
        {
            goto no_change;
        }
    }

    /*
        *   =============================================================
        *   This packet is divided into several pieces of data segment, unite them into single one.
        *   =============================================================
        */
    {
        kal_uint32  total_len;
        kal_uint32  copied_len;
        kal_uint8   *p_buff;

        total_len = QBM_DES_GET_DATALEN(p_gpd_in);

        if (total_len == 0)
        {
            hif_trace_error(IPC_TR_GPD_UNITE_ZERO_LENGTH_GPD, uplink, p_gpd_in);
            goto no_change;
        }

        if (1 != qbmt_alloc_q_no_tail(
                        (KAL_TRUE == uplink)?QBM_TYPE_NET_UL_SHRD/*UL*/:QBM_TYPE_HIF_DL/*DL*/, /* type */
                        1, /* buff_num */
                        (void**)pp_gpd_out, /* pp_head */
                        (void**)pp_gpd_out  /* pp_tail */))
        {   /* Allocation fail */
            hif_trace_error(IPC_TR_GPD_UNITE_ALLOC_GPD_NG, uplink, p_gpd_in, total_len);
            goto unite_failed;
        }

        /* Copy data from input GPD to output GPD */
        IPC_ASSERT(*pp_gpd_out);
        ipc_set_gpd_datalen(*pp_gpd_out, total_len, (void**)&p_buff);
        IPC_ASSERT(p_buff);

        if (KAL_TRUE != ipc_do_gpd_copy(    p_buff,
                                            total_len,
                                            &copied_len,
                                            p_gpd_in,
                                            p_gpd_in))
        {   /* data copy fail */
            hif_trace_error(IPC_TR_GPD_UNITE_GPD_COPY_NG, uplink, p_buff, total_len, copied_len, p_gpd_in);
            /* Free allocated new GPD */
            qbmt_dest_q(*pp_gpd_out, *pp_gpd_out);
            goto unite_failed;
        }

        /* Sync SW control field from UPCM for DL traffic */
        if (KAL_FALSE == uplink)
        {   /* SW control field is from UPCM */
            kal_mem_cpy(    (void*)QBM_DES_GET_SW_CTRL_FIELD(*pp_gpd_out),
                            (void*)QBM_DES_GET_SW_CTRL_FIELD(p_gpd_in),
                            sizeof(upcm_dlvr_dl_info_t));
        }
    }

   /*
        *   =============================================================
        *   Unite done : return new GPD.
        *   =============================================================
        */
    hif_data_trace(IPC_GE_UNITED_GPD, uplink, p_gpd_in, *pp_gpd_out, QBM_DES_GET_DATALEN(*pp_gpd_out));
    IPC_ASSERT(*pp_gpd_out);
    return;

no_change:
    *pp_gpd_out = p_gpd_in;
    return;

unite_failed:
    hif_trace_error(IPC_TR_GPD_UNITE_FAILED, uplink, p_gpd_in);

    *pp_gpd_out = NULL;
    return;
}

/*!
 * Look into packet to gather necessary IP header & the upper layer protocol header information.
 * Note that, for IPv6's packet, current implementation don't handle the following cases and take them  as not found:
 *     #1. IPv6 packet with ESP header:
 *        According to RFC 4303 section 3.1, everything after ESP header is encrypted.
 *        Since we cannot decrypt it, we cannot acturally look into the upper layer protocol.
 *
 *     #2. IPv6 extension header not defined in RFC 2460:
 *        If necessary, we will handle them here according to corresponding RFC.
 *
 *     #3. fragmentation:
 *        No application needs IPv6 fragmentation on a modem platform so far.
 *
 * @param   ipv6_packet [IN] The packet.
 * @param   gpd [IN] GPD of packet content.
 * @param   base_bd [IN] Corresponding BD for base_addr_p. It might be NULL if the GPD does not have BD list.
 * @param   p_info [OUT] The necessary information gathered for later packete filtering.
 *
 * @return KAL_TRUE if the packet's information was gathered sucessfully, KAL_FALSE otherwise.
 */
kal_bool ipc_get_packet_info(kal_uint8 *p_packet, qbm_gpd *gpd, qbm_gpd *base_bd, ipc_packet_info_t *p_info)
{
    kal_uint32 ip_header_len;
    kal_uint16 tmp_len;
    qbm_gpd *next_bd;
    kal_uint8 *p_addr;
    kal_uint8 comm_buff[16];// max is ipv6 src/dest addr
    kal_uint8 *comm_continuous_p = NULL;
    
    p_addr = p_packet;
    next_bd = base_bd;

    //kal_mem_set(p_info, 0, sizeof(ipc_packet_info_t));// init
    p_info->info_valid_fields = 0;//init
    
    QBM_CACHE_INVALID(p_packet, 1);
    if (IPC_HDR_IS_V4(p_packet)){
        // check first 12B(fragment, total len, header len, protocol)
        if (KAL_TRUE != ipc_get_continuous_content(p_addr, 0, gpd, next_bd, 12, &comm_continuous_p, comm_buff))
        {
            hif_trace_error(IPC_TR_GET_INFO_V4_IPV4_HDR_FAILED, p_addr, 0, gpd, next_bd, 12);
            return KAL_FALSE;
        }
        p_info->fragment = ((IPC_NE_GET_2B(comm_continuous_p + 6) & 0x9FFF) > 0);
        ip_header_len = (kal_uint32)IPC_HDR_V4_GET_IHL(comm_continuous_p + 0);
        p_info->protocol = IPC_NE_GET_1B(comm_continuous_p + 9);
        p_info->info_valid_fields |= IPC_FILTER_BY_PROTOCOL;
        // check src/dest addr
        if (KAL_TRUE != ipc_get_continuous_content(p_addr, 12, gpd, next_bd, 8, &comm_continuous_p, comm_buff))
        {
            hif_trace_error(IPC_TR_GET_INFO_V4_IPV4_HDR_FAILED, p_addr, 12, gpd, next_bd, 8);
            return KAL_FALSE;
        }        
        kal_mem_cpy(p_info->src_addr, comm_continuous_p, 4);
        kal_mem_cpy(p_info->dst_addr, comm_continuous_p + 4, 4);
        p_info->info_valid_fields |= (IPC_FILTER_BY_SRC_IPV4 + IPC_FILTER_BY_DST_IPV4);
      
        if (p_info->protocol == IPC_HDR_PROT_UDP){

            // check src/dest port
            if (KAL_TRUE != ipc_get_continuous_content(p_addr, ip_header_len, gpd, next_bd, 4, &comm_continuous_p, comm_buff))
            {
                hif_trace_error(IPC_TR_GET_INFO_V4_UDP_HDR_FAILED, p_addr, ip_header_len, gpd, next_bd, 4);
                return KAL_FALSE;
            }

            p_info->src_port = IPC_NE_GET_2B(comm_continuous_p);           
            p_info->dst_port = IPC_NE_GET_2B(comm_continuous_p + 2);
            p_info->info_valid_fields |= (IPC_FILTER_BY_SRC_PORT + IPC_FILTER_BY_DST_PORT);
            p_info->data_offset = ip_header_len + IPC_HDR_UDP_HEADER_SIZE;
        }
        else if (p_info->protocol == IPC_HDR_PROT_TCP){

            // check src/dest port & flags
            if (KAL_TRUE != ipc_get_continuous_content(p_addr, ip_header_len, gpd, next_bd, 14, &comm_continuous_p, comm_buff))
            {
                hif_trace_error(IPC_TR_GET_INFO_V4_TCP_HDR_FAILED, p_addr, ip_header_len, gpd, next_bd, 14);
                return KAL_FALSE;
            }

            p_info->src_port = IPC_NE_GET_2B(comm_continuous_p);           
            p_info->dst_port = IPC_NE_GET_2B(comm_continuous_p + 2);
            p_info->tcp_flags = IPC_HDR_TCP_GET_FLAGS(comm_continuous_p);
            p_info->info_valid_fields |= (IPC_FILTER_BY_SRC_PORT + IPC_FILTER_BY_DST_PORT + IPC_FILTER_BY_TCP_FLAGS);
            p_info->data_offset = ip_header_len + IPC_HDR_TCP_GET_OFFSET(comm_continuous_p);
        }
        else if (p_info->protocol == IPC_HDR_PROT_ICMP){

            // check type
            if (KAL_TRUE != ipc_get_continuous_content(p_addr, ip_header_len, gpd, next_bd, 1, &comm_continuous_p, comm_buff))
            {
                hif_trace_error(IPC_TR_GET_INFO_V4_ICMP_HDR_FAILED, p_addr, ip_header_len, gpd, next_bd, 1);
                return KAL_FALSE;
            }
            
            p_info->icmpv4_type = IPC_NE_GET_1B(comm_continuous_p);
            p_info->info_valid_fields |= IPC_FILTER_BY_ICMPV4_TYPE;
            p_info->data_offset = ip_header_len + IPC_HDR_ICMP_HEADER_SIZE;
        }
    }else if (IPC_HDR_IS_V6(p_packet)){
        p_info->fragment = 0;
        // check first 8B(total len, protocol(next header))
        if (KAL_TRUE != ipc_get_continuous_content(p_addr, 0, gpd, next_bd, 8, &comm_continuous_p, comm_buff))
        {
            hif_trace_error(IPC_TR_GET_INFO_V6_IPV6_HDR_FAILED, p_addr, 0, gpd, next_bd, 8);
            return KAL_FALSE;
        }
        ip_header_len = 40;// fix
        p_info->data_offset = ip_header_len;
        p_info->protocol = IPC_NE_GET_1B(comm_continuous_p + 6);// next header
        p_info->info_valid_fields |= IPC_FILTER_BY_PROTOCOL;
        // check src addr
        if (KAL_TRUE != ipc_get_continuous_content(p_addr, 8, gpd, next_bd, 16, &comm_continuous_p, comm_buff))
        {
            hif_trace_error(IPC_TR_GET_INFO_V6_IPV6_HDR_FAILED, p_addr, 8, gpd, next_bd, 16);
            return KAL_FALSE;
        }        
        kal_mem_cpy(p_info->src_addr, comm_continuous_p, 16);
        p_info->info_valid_fields |= IPC_FILTER_BY_SRC_IPV6;
        // check dest addr
        if (KAL_TRUE != ipc_get_continuous_content(p_addr, 24, gpd, next_bd, 16, &comm_continuous_p, comm_buff))
        {
            hif_trace_error(IPC_TR_GET_INFO_V6_IPV6_HDR_FAILED, p_addr, 24, gpd, next_bd, 16);
            return KAL_FALSE;
        }        
        kal_mem_cpy(p_info->dst_addr, comm_continuous_p, 16);
        p_info->info_valid_fields |= IPC_FILTER_BY_DST_IPV6;

        // parsing extention header
        tmp_len = ip_header_len;
        while(1){
            if ((p_info->protocol == IPC_HDR_PROT_IPV6_HOP) || 
                (p_info->protocol == IPC_HDR_PROT_IPV6_ROUTE) ||
                (p_info->protocol == IPC_HDR_PROT_IPV6_DEST)){

                if (KAL_TRUE != ipc_shift_gpd_content_ptr(p_addr, gpd, next_bd, tmp_len, &p_addr, &next_bd))
                {                 
                    hif_trace_error(IPC_TR_GET_INFO_FIND_V6_EXT_HDR_SHIFT_FAILED, gpd, base_bd, p_packet, tmp_len, p_addr, next_bd);
                    return KAL_FALSE;
                }              
                if (KAL_TRUE != ipc_get_continuous_content(p_addr, 0, gpd, next_bd, 2, &comm_continuous_p, comm_buff))
                {
                    hif_trace_error(IPC_TR_GET_INFO_FIND_V6_EXT_HDR_FAILED, gpd, base_bd, p_addr, tmp_len, next_bd);
                    return KAL_FALSE;
                }
       
                // next header
                p_info->protocol = IPC_NE_GET_1B(comm_continuous_p);
                // current header len
                tmp_len = (IPC_NE_GET_1B(comm_continuous_p + 1) + 1)*8;
                p_info->data_offset += tmp_len;
            }else if (p_info->protocol == IPC_HDR_PROT_AH){ 

                if (KAL_TRUE != ipc_shift_gpd_content_ptr(p_addr, gpd, next_bd, tmp_len, &p_addr, &next_bd))
                {
                    hif_trace_error(IPC_TR_GET_INFO_FIND_V6_EXT_HDR_SHIFT_FAILED, gpd, base_bd, p_packet, tmp_len, p_addr, next_bd);
                    return KAL_FALSE;
                }              
                if (KAL_TRUE != ipc_get_continuous_content(p_addr, 0, gpd, next_bd, 2, &comm_continuous_p, comm_buff))
                {
                    hif_trace_error(IPC_TR_GET_INFO_FIND_V6_EXT_HDR_FAILED, gpd, base_bd, p_addr, tmp_len, next_bd);
                    return KAL_FALSE;
                }
       
                // next header
                p_info->protocol = IPC_NE_GET_1B(comm_continuous_p);
                // current header len
                tmp_len = (IPC_NE_GET_1B(comm_continuous_p + 1) + 2)*4;
                p_info->data_offset += tmp_len;
            }else{
                break;
            }
        }

        if (p_info->protocol == IPC_HDR_PROT_UDP){
            
            if (KAL_TRUE != ipc_shift_gpd_content_ptr(p_addr, gpd, next_bd, tmp_len, &p_addr, &next_bd))
            {
                hif_trace_error(IPC_TR_GET_INFO_FIND_V6_EXT_HDR_SHIFT_FAILED, gpd, base_bd, p_packet, tmp_len, p_addr, next_bd);
                return KAL_FALSE;
            }              
            if (KAL_TRUE != ipc_get_continuous_content(p_addr, 0, gpd, next_bd, 4, &comm_continuous_p, comm_buff))
            {
                hif_trace_error(IPC_TR_GET_INFO_V6_UDP_HDR_FAILED, p_addr, 0, gpd, next_bd, 4);
                return KAL_FALSE;
            }           
            p_info->src_port = IPC_NE_GET_2B(comm_continuous_p);         
            p_info->dst_port = IPC_NE_GET_2B(comm_continuous_p + 2);
            p_info->info_valid_fields |= (IPC_FILTER_BY_SRC_PORT + IPC_FILTER_BY_DST_PORT);
            p_info->data_offset += IPC_HDR_UDP_HEADER_SIZE;
        }
        else if (p_info->protocol == IPC_HDR_PROT_TCP){

            if (KAL_TRUE != ipc_shift_gpd_content_ptr(p_addr, gpd, next_bd, tmp_len, &p_addr, &next_bd))
            {
                hif_trace_error(IPC_TR_GET_INFO_FIND_V6_EXT_HDR_SHIFT_FAILED, gpd, base_bd, p_packet, tmp_len, p_addr, next_bd);
                return KAL_FALSE;
            }              
            if (KAL_TRUE != ipc_get_continuous_content(p_addr, 0, gpd, next_bd, 14, &comm_continuous_p, comm_buff))
            {
                hif_trace_error(IPC_TR_GET_INFO_V6_TCP_HDR_FAILED, p_addr, 0, gpd, next_bd, 14);
                return KAL_FALSE;
            }           
            p_info->src_port = IPC_NE_GET_2B(comm_continuous_p);         
            p_info->dst_port = IPC_NE_GET_2B(comm_continuous_p + 2);
            p_info->tcp_flags = IPC_HDR_TCP_GET_FLAGS(comm_continuous_p);
            p_info->info_valid_fields |= (IPC_FILTER_BY_SRC_PORT + IPC_FILTER_BY_DST_PORT + IPC_FILTER_BY_TCP_FLAGS);
            p_info->data_offset += IPC_HDR_TCP_GET_OFFSET(comm_continuous_p);
        }
        else if (p_info->protocol == IPC_HDR_PROT_ICMPV6){

            if (KAL_TRUE != ipc_shift_gpd_content_ptr(p_addr, gpd, next_bd, tmp_len, &p_addr, &next_bd))
            {
                hif_trace_error(IPC_TR_GET_INFO_FIND_V6_EXT_HDR_SHIFT_FAILED, gpd, base_bd, p_packet, tmp_len, p_addr, next_bd);
                return KAL_FALSE;
            }
            if (KAL_TRUE != ipc_get_continuous_content(p_addr, 0, gpd, next_bd, 1, &comm_continuous_p, comm_buff))
            {
                hif_trace_error(IPC_TR_GET_INFO_V6_ICMP_HDR_FAILED, p_addr, 0, gpd, next_bd, 4);
                return KAL_FALSE;
            }
            p_info->icmpv6_type = IPC_NE_GET_1B(p_addr);
            p_info->info_valid_fields |= IPC_FILTER_BY_ICMPV6_TYPE;
            p_info->data_offset += IPC_HDR_ICMP_HEADER_SIZE;
        }

    }

    return KAL_TRUE;
}

/*!
 * The SPD version of ipc_get_packet_info(). The packet would be a continuous buffer rather than a GPD. For more information, please refer ipc_get_packet_info()
 *
 * @param   ipv6_packet [IN] The packet.
 * @param   packet_len [IN] Length of the packet.
 * @param   p_info [OUT] The necessary information gathered for later packete filtering.
 *
 * @return KAL_TRUE if the packet's information was gathered sucessfully, KAL_FALSE otherwise.
 */
kal_bool ipc_get_packet_info_spd(kal_uint8 *p_packet, kal_uint16 packet_len, ipc_packet_info_t *p_info)
{
    kal_uint32 ip_header_len;
    kal_uint16 data_len, tmp_len;
    kal_uint8 *p_addr;

    //kal_mem_set(p_info, 0, sizeof(ipc_packet_info_t));// init
    p_info->info_valid_fields = 0;//init

    /*
     * (2015/09/03) Should invalidate cache before get packet info.
     * Invalidate the larger size between IPv4 & IPv6 header.
     */
    QBM_CACHE_INVALID(p_packet, 40);
    if (IPC_HDR_IS_V4(p_packet)){
        // check first 12B(fragment, total len, header len, protocol)
        p_addr = p_packet;
        data_len = 12;
        if (packet_len < data_len) {
            hif_trace_error(IPC_TR_GET_INFO_SPD_V4_IPV4_HDR_FAILED, p_packet, data_len, packet_len);
            return KAL_FALSE;
        }
        p_info->fragment = ((IPC_NE_GET_2B(p_addr + 6) & 0x9FFF) > 0);
        ip_header_len = (kal_uint32)IPC_HDR_V4_GET_IHL(p_addr + 0);
        p_info->protocol = IPC_NE_GET_1B(p_addr + 9);
        p_info->info_valid_fields |= IPC_FILTER_BY_PROTOCOL;

        // check src/dest addr
        p_addr = p_packet + data_len;
        data_len += 8;
        if (packet_len < data_len) {
            hif_trace_error(IPC_TR_GET_INFO_SPD_V4_IPV4_HDR_FAILED, p_packet, data_len, packet_len);
            return KAL_FALSE;
        }
        kal_mem_cpy(p_info->src_addr, p_addr, 4);
        kal_mem_cpy(p_info->dst_addr, p_addr + 4, 4);
        p_info->info_valid_fields |= (IPC_FILTER_BY_SRC_IPV4 + IPC_FILTER_BY_DST_IPV4);

        if (p_info->protocol == IPC_HDR_PROT_UDP){

            // check src/dest port
            p_addr = p_packet + ip_header_len;
            data_len = ip_header_len + 4;
            if (packet_len < data_len)
            {
                hif_trace_error(IPC_TR_GET_INFO_SPD_V4_UDP_HDR_FAILED, p_packet, data_len, packet_len);
                return KAL_FALSE;
            }
            QBM_CACHE_INVALID(p_addr, 4);

            p_info->src_port = IPC_NE_GET_2B(p_addr);
            p_info->dst_port = IPC_NE_GET_2B(p_addr + 2);
            p_info->info_valid_fields |= (IPC_FILTER_BY_SRC_PORT + IPC_FILTER_BY_DST_PORT);
            p_info->data_offset = ip_header_len + IPC_HDR_UDP_HEADER_SIZE;
        }
        else if (p_info->protocol == IPC_HDR_PROT_TCP){

            // check src/dest port & flags
            p_addr = p_packet + ip_header_len;
            data_len = ip_header_len + 14;
            if (packet_len < data_len)
            {
                hif_trace_error(IPC_TR_GET_INFO_SPD_V4_TCP_HDR_FAILED, p_packet, data_len, packet_len);
                return KAL_FALSE;
            }
            QBM_CACHE_INVALID(p_addr, 14);

            p_info->src_port = IPC_NE_GET_2B(p_addr);
            p_info->dst_port = IPC_NE_GET_2B(p_addr + 2);
            p_info->tcp_flags = IPC_HDR_TCP_GET_FLAGS(p_addr);
            p_info->info_valid_fields |= (IPC_FILTER_BY_SRC_PORT + IPC_FILTER_BY_DST_PORT + IPC_FILTER_BY_TCP_FLAGS);
            p_info->data_offset = ip_header_len + IPC_HDR_TCP_GET_OFFSET(p_addr);
        }
        else if (p_info->protocol == IPC_HDR_PROT_ICMP){

            // check type
            p_addr = p_packet + ip_header_len;
            data_len = ip_header_len + 1;
            if (packet_len < data_len)
            {
                hif_trace_error(IPC_TR_GET_INFO_SPD_V4_ICMP_HDR_FAILED, p_packet, data_len, packet_len);
                return KAL_FALSE;
            }
            QBM_CACHE_INVALID(p_addr, 1);

            p_info->icmpv4_type = IPC_NE_GET_1B(p_addr);
            p_info->info_valid_fields |= IPC_FILTER_BY_ICMPV4_TYPE;
            p_info->data_offset = ip_header_len + IPC_HDR_ICMP_HEADER_SIZE;
        }
    }else if (IPC_HDR_IS_V6(p_packet)){
        p_info->fragment = 0;
        // check first 8B(total len, protocol(next header))
        p_addr = p_packet;
        data_len = 8;
        if (packet_len < data_len)
        {
            hif_trace_error(IPC_TR_GET_INFO_SPD_V6_IPV6_HDR_FAILED, p_packet, data_len, packet_len);
            return KAL_FALSE;
        }
        ip_header_len = 40;// fix
        p_info->data_offset = ip_header_len;
        p_info->protocol = IPC_NE_GET_1B(p_addr + 6);// next header
        p_info->info_valid_fields |= IPC_FILTER_BY_PROTOCOL;
        // check src addr
        p_addr = p_packet + data_len;
        data_len += 16;
        if (packet_len < data_len)
        {
            hif_trace_error(IPC_TR_GET_INFO_SPD_V6_IPV6_HDR_FAILED, p_packet, data_len, packet_len);
            return KAL_FALSE;
        }
        kal_mem_cpy(p_info->src_addr, p_addr, 16);
        p_info->info_valid_fields |= IPC_FILTER_BY_SRC_IPV6;
        // check dest addr
        p_addr = p_packet + data_len;
        data_len += 16;
        if (packet_len < data_len)
        {
            hif_trace_error(IPC_TR_GET_INFO_SPD_V6_IPV6_HDR_FAILED, p_packet, data_len, packet_len);
            return KAL_FALSE;
        }
        kal_mem_cpy(p_info->dst_addr, p_addr, 16);
        p_info->info_valid_fields |= IPC_FILTER_BY_DST_IPV6;

        // parsing extention header
        data_len = ip_header_len;
        while(1){
            if ((p_info->protocol == IPC_HDR_PROT_IPV6_HOP) ||
                (p_info->protocol == IPC_HDR_PROT_IPV6_ROUTE) ||
                (p_info->protocol == IPC_HDR_PROT_IPV6_DEST)){

                p_addr = p_packet + data_len;
                data_len += 2;
                if (packet_len < data_len)
                {
                    hif_trace_error(IPC_TR_GET_INFO_SPD_FIND_V6_EXT_HDR_FAILED, p_packet, data_len, packet_len);
                    return KAL_FALSE;
                }
                QBM_CACHE_INVALID(p_addr, 2);

                // next header
                p_info->protocol = IPC_NE_GET_1B(p_addr);
                // current header len (the first 2 bytes have been added already)
                tmp_len = (IPC_NE_GET_1B(p_addr + 1) + 1)*8 - 2;
                data_len += tmp_len;
                p_info->data_offset += tmp_len;
            }else if (p_info->protocol == IPC_HDR_PROT_AH){

                p_addr = p_packet + data_len;
                data_len += 2;
                if (packet_len < data_len)
                {
                    hif_trace_error(IPC_TR_GET_INFO_SPD_FIND_V6_EXT_HDR_FAILED, p_packet, data_len, packet_len);
                    return KAL_FALSE;
                }
                QBM_CACHE_INVALID(p_addr, 2);

                // next header
                p_info->protocol = IPC_NE_GET_1B(p_addr);
                // current header len (the first 2 bytes have been added already)
                tmp_len = (IPC_NE_GET_1B(p_addr + 1) + 2)*4 - 2;
                data_len += tmp_len;
                p_info->data_offset += tmp_len;
            }else{
                break;
            }
        }

        if (p_info->protocol == IPC_HDR_PROT_UDP){

            p_addr = p_packet + data_len;
            data_len += 4;
            if (packet_len < data_len)
            {
                hif_trace_error(IPC_TR_GET_INFO_SPD_V6_UDP_HDR_FAILED, p_packet, data_len, packet_len);
                return KAL_FALSE;
            }
            QBM_CACHE_INVALID(p_addr, 4);
            p_info->src_port = IPC_NE_GET_2B(p_addr);
            p_info->dst_port = IPC_NE_GET_2B(p_addr + 2);
            p_info->info_valid_fields |= (IPC_FILTER_BY_SRC_PORT + IPC_FILTER_BY_DST_PORT);
            p_info->data_offset += IPC_HDR_UDP_HEADER_SIZE;
        }
        else if (p_info->protocol == IPC_HDR_PROT_TCP){

            p_addr = p_packet + data_len;
            data_len += 14;
            if (packet_len < data_len)
            {
                hif_trace_error(IPC_TR_GET_INFO_SPD_V6_TCP_HDR_FAILED, p_packet, data_len, packet_len);
                return KAL_FALSE;
            }
            QBM_CACHE_INVALID(p_addr, 14);
            p_info->src_port = IPC_NE_GET_2B(p_addr);
            p_info->dst_port = IPC_NE_GET_2B(p_addr + 2);
            p_info->tcp_flags = IPC_HDR_TCP_GET_FLAGS(p_addr);
            p_info->info_valid_fields |= (IPC_FILTER_BY_SRC_PORT + IPC_FILTER_BY_DST_PORT + IPC_FILTER_BY_TCP_FLAGS);
            p_info->data_offset += IPC_HDR_TCP_GET_OFFSET(p_addr);
        }
        else if (p_info->protocol == IPC_HDR_PROT_ICMPV6){

            p_addr = p_packet + data_len;
            data_len += 1;
            if (packet_len < data_len)
            {
                hif_trace_error(IPC_TR_GET_INFO_SPD_V6_ICMP_HDR_FAILED, p_packet, data_len, packet_len);
                return KAL_FALSE;
            }
            QBM_CACHE_INVALID(p_addr, 1);
            p_info->icmpv6_type = IPC_NE_GET_1B(p_addr);
            p_info->info_valid_fields |= IPC_FILTER_BY_ICMPV6_TYPE;
            p_info->data_offset += IPC_HDR_ICMP_HEADER_SIZE;
        }
    }

    return KAL_TRUE;
}
static INLINE ipc_pkt_do_filter_result_e
ipc_pkt_do_filter(
    kal_bool            uplink,
    kal_bool            spd,
    ipc_filter_list_t **fls_set_p,
    kal_uint32          fls_set_cnt,
    kal_uint8           session_type,
    kal_uint32          pdn_id,
    kal_uint32          netif_id,
    kal_uint8          *ip_packet,// input for spd only
    kal_uint32         *packet_len,
    kal_uint8           ebi_info,// for record ebi, which is saved in the 1st GPD
    qbm_gpd            *curr_gpd,
    ipc_filter_t       *matched_filter,
    ipc_filter_info_t  *filter_info)
{
    ipc_filter_list_t  *filter_list;
    kal_uint8           filter_list_type;
    ipc_filter_t       *filter;
    kal_uint32          fls_idx;
    kal_bool            matched;
    ipc_packet_info_t   packet_info;
    kal_bool            get_pkt_info;
    qbm_gpd            *curr_bd = NULL;
    kal_uint32          mask;


    if (!spd) {
        /*
         * For DL 3G packet, packet content might be divided in several pieces in BD list.
         * To handle this situation, IPCore MUST aware this during packet content checking.
         */
        if (KAL_TRUE != ipc_get_ip_packet(curr_gpd, &curr_bd, &ip_packet, packet_len))
        {
            hif_trace_error(IPC_TR_DO_FILTER_INVALID_GPD, curr_gpd);
            return IPC_PKT_DO_FILTER_ERROR;
        }
    }

#if (IPC_DL_INVALID_LEN_DROP_EN)
    if ( (!uplink) &&
         (*packet_len > ipc_dl_valid_packet_len_s) ) {
        // packet info
        hif_data_trace(IPC_DL_INVALID_LEN_CHK, ebi_info, curr_gpd, curr_bd, *packet_len, ipc_dl_valid_packet_len_s);
        // dump ip header
        hif_data_trace(IPC_DL_INVALID_LEN_PKT_IP_HDR, 0, IPC_NE_GET_4B(ip_packet));
        hif_data_trace(IPC_DL_INVALID_LEN_PKT_IP_HDR, 1, IPC_NE_GET_4B(ip_packet+4));
        hif_data_trace(IPC_DL_INVALID_LEN_PKT_IP_HDR, 2, IPC_NE_GET_4B(ip_packet+8));
        hif_data_trace(IPC_DL_INVALID_LEN_PKT_IP_HDR, 3, IPC_NE_GET_4B(ip_packet+12));
        hif_data_trace(IPC_DL_INVALID_LEN_PKT_IP_HDR, 4, IPC_NE_GET_4B(ip_packet+16));
        return IPC_PKT_DO_FILTER_INVALID_LEN;
    }
#endif

    get_pkt_info = KAL_FALSE;// init per GPD start
    matched = KAL_FALSE;// init per GPD start
    filter_list = NULL;// init per GPD start

    for (fls_idx = 0; fls_idx < fls_set_cnt; fls_idx++) {
        if (filter_list) {
            IPC_R_UNLOCK_OBJECT(filter_list, mask);
        }
        filter_list = fls_set_p[fls_idx];
        IPC_R_LOCK_OBJECT(filter_list, mask);

        if (!filter_list || 0 == filter_list->count) {
            continue; /* Skip empty filter list. */
        }

        filter_list_type = filter_list->ip_type;

        if (IPC_IP_TYPE_IPV4 == session_type) {
            if (IPC_IP_TYPE_IPV4 != filter_list_type) {
                continue; /* Skip the filter list if IP type mismatched. */
            }
        } else if (IPC_IP_TYPE_IPV6 == session_type) {
            if (IPC_IP_TYPE_IPV6 != filter_list_type) {
                continue; /* Skip the filter list if IP type mismatched. */
            }
        }

        if (KAL_FALSE == get_pkt_info)
        {
            // get packet info
            if (spd) {
                IPC_ASSERT(ip_packet && packet_len);
                ipc_get_packet_info_spd(ip_packet, *packet_len, &packet_info);
            } else {
                IPC_ASSERT(ip_packet && curr_gpd);
                ipc_get_packet_info(ip_packet, curr_gpd, curr_bd, &packet_info);
            }
            get_pkt_info = KAL_TRUE;// already get info, get info GPD
        }

        for (filter = filter_list->filter_head; filter;
             filter = filter->next_filter_map[ipc_next_filter_hash(filter_list_type)]) {
            if (!filter) continue;

            /* Check if its the Wild Card filter */
            if (_FEATURES_CONTAIN(&filter->rules, WC)) {
                goto filter_matched;
            }

            /* PDN ID is only valid for downlink filter */
            if ((KAL_FALSE == uplink) &&
                _RULES_CONTAIN(&filter->rules, PDN_ID) &&
                pdn_id != filter->rules.pdn_id) {
                continue; /* Skip the filter if PDN ID mismatched. */
            }

            if (_RULES_CONTAIN(&filter->rules, NETIF_ID) &&
                netif_id != filter->rules.netif_id) {
                continue;   /* Skip the filter if Network interface ID mismatched. */
            }

            /*
            *        1. ebi is only valid for downlink filter
            *        2. (2013/11/4) According to UPCM comment, EBI is only brought in first GPD of GPD list.
            *        3. (2015/1/14)  EBI info in the 1st GPD is recorded before filtering. (saved in ebi_info)
            */
            if ((KAL_FALSE == uplink) &&
                _RULES_CONTAIN(&filter->rules, EBI) &&
                ebi_info != filter->rules.ebi)
            {
                continue;
            }

            do
            {
                matched = KAL_FALSE;

                /* Check for IP version : single byte check, no content dividing issue */
                if ( IPC_HDR_IS_V4(ip_packet) ) {
                    if (_RULES_CONTAIN_IPV4(&filter->rules)) {
                        matched = ipc_match_ipv4_rules(&filter->rules, &packet_info);
                    }
                } else {
                    if (_RULES_CONTAIN_IPV6(&filter->rules)) {
                        matched = ipc_match_ipv6_rules(&filter->rules, &packet_info);
                    }
                }
            } while (0);

            if (matched) {
                goto filter_matched;
            }
        }
    } /* for each filter_list, fls_idx */
    if (filter_list) {
        IPC_R_UNLOCK_OBJECT(filter_list, mask);
    }

    return IPC_PKT_DO_FILTER_NOT_MATCHED;

filter_matched:
    hif_data_trace(IPC_GE_FILTER_RULE_MATCHED, 0, &filter->rules, filter->rules.features, filter->rules.valid_fields);

    /*
     * (2015/2/9) LTECSR preempts and deregisters the filter between IPCore filtering and call cbk.
     * 1. IPCore uses filter_list read lock to prevent filter_list being modifed while filtering.
     * 2. IPCore should NOT hold the read lock while calling cbk function, or it may cause "Dead Lock".
     * 3. Cache the filter info before release the read lock to prevent accessing dirty data.
     *    However, it's possible that user's cbk will still be called once after filter deregistered.
     */
    matched_filter->filter_id = filter->filter_id;
    matched_filter->rules.features = filter->rules.features;
    matched_filter->callback_with_info = filter->callback_with_info;
    matched_filter->callback_func = filter->callback_func;
    matched_filter->callback_context = filter->callback_context;
    matched_filter->module_id = filter->module_id;
    matched_filter->module_context = filter->module_context;

    if (filter_list) {
        IPC_R_UNLOCK_OBJECT(filter_list, mask);
    }

    /*
     * DO NOT access filter after this point.
     */
    if (KAL_TRUE == matched_filter->callback_with_info) {
        /* Fill filter_info */
        ipc_netif_t *netif;

        filter_info->netif_id = netif_id;

        netif = ipc_find_netif(netif_id);
        if (netif) {
            filter_info->ip_id = ipc_map_netif_to_ip_id(netif);
            IPC_R_UNLOCK_OBJECT(netif, mask);
        } else {
            filter_info->ip_id = -1;
        }

        /*
         *      1. ebi is only valid for downlink filter
         *      2. (2013/11/4)  According to UPCM comment, EBI is only brought in first GPD of GPD list.
         */
        if (KAL_FALSE == uplink) {
            filter_info->ebi = ebi_info;
        #ifdef __MULTIPLE_PS__
            IPC_RETRIEVE_PROTOID_FROM_PDNID(filter_info->ebi, filter_info->proto_idx);
            IPC_UNMASK_PROTOID_FROM_PDNID(filter_info->ebi);
        #endif
        } else {
            filter_info->ebi = -1;
        }
        /*
         * (2014/11/11) Based on LTECSR's requirement, carry RTP data_offset info to them.
         */
        filter_info->data_offset = packet_info.data_offset;
    }

    return IPC_PKT_DO_FILTER_MATCHED;
}

static INLINE void
ipc_call_filter_cbk(
    kal_bool            uplink,
    qbm_gpd            *callback_gpd_p,
    kal_uint16          callback_gpd_data_len,
    ipc_filter_t       *filter,
    ipc_filter_info_t  *filter_info)
{
    IPC_ASSERT(callback_gpd_p);
    IPC_ASSERT(filter);
    IPC_ASSERT(filter_info);

    hif_data_trace(IPC_GE_FILTER_OUT_INFO, uplink, filter->callback_context, filter->filter_id);
    hif_data_trace(IPC_GE_FILTER_OUT_GPD, uplink, callback_gpd_p, callback_gpd_data_len);

    if (KAL_TRUE == filter->callback_with_info)
    {
        ipc_filter_with_info_callback_t callback_func;

        callback_func = (ipc_filter_with_info_callback_t)(filter->callback_func);

        callback_func(      filter_info,
                            filter->callback_context,
                            filter->filter_id,
                            callback_gpd_p,
                            callback_gpd_p,
                            (kal_uint32)callback_gpd_data_len   );
    } else
    {
        ipc_filter_callback_t callback_func;

        callback_func = (ipc_filter_callback_t)(filter->callback_func);

        callback_func(      filter->callback_context,
                            filter->filter_id,
                            callback_gpd_p,
                            callback_gpd_p,
                            (kal_uint32)callback_gpd_data_len   );
    }
}

static INLINE void
ipc_do_filter(
    kal_bool            uplink,
    ipc_filter_list_t **fls_set_p,
    kal_uint32          fls_set_cnt,
    kal_uint8           session_type,
    kal_uint32          pdn_id,
    kal_uint32          netif_id,
    qbm_gpd           **pp_head,
    qbm_gpd           **pp_tail)
{
    qbm_gpd            *first_gpd;
    qbm_gpd            *last_gpd;
    qbm_gpd            *curr_gpd;
    qbm_gpd            *prev_gpd;
    qbm_gpd            *next_gpd;
    kal_bool            end_of_list;
    kal_uint8           ebi_info = 0;// for record ebi, which is saved in the 1st GPD
    kal_uint8          *ip_packet = NULL;
    kal_uint32          length;
    ipc_filter_t        filter;
    ipc_filter_info_t   filter_info;
    kal_bool            spd;
    qbm_spd_pi         *p_spd_pi;
    qbm_spd_pie        *p_spd_pie = NULL;// spd payload info element
    qbm_spd_pie        *p_prev_spd_pie;
    kal_uint8           idx;
    kal_uint32          payload_len = 0;
    kal_uint16          packet_num = 0;
    kal_uint8           remain_packet_num = 0; // the num of packets not filtered out
    ipc_pkt_do_filter_result_e  result;


    first_gpd = *pp_head;
    last_gpd = *pp_tail;

    if (first_gpd) {
        ebi_info = ((upcm_dlvr_dl_info_t *)QBM_DES_GET_SW_CTRL_FIELD(first_gpd))->ebi;
    }

    prev_gpd = NULL;
    end_of_list = (NULL == first_gpd);

    for (curr_gpd = first_gpd; curr_gpd && !end_of_list; curr_gpd = next_gpd)
    {
        spd = (QBM_DES_GET_PDT(curr_gpd) != 0);

        next_gpd = QBM_DES_GET_NEXT(curr_gpd);
        end_of_list = (curr_gpd == last_gpd);

        result = IPC_PKT_DO_FILTER_NONE;// reset for each GPD

        if (spd){
            /*
             * It's SPD (PDT != 0)
             * Need to traverse all of the packets in it.
             */

            ip_packet = QBM_DES_GET_DATAPTR(curr_gpd);
            length = QBM_DES_GET_DATALEN(curr_gpd);
            IPC_ASSERT(length > 0);
            p_spd_pi = QBM_SPD_GET_PI((qbm_spd *)curr_gpd);
            p_prev_spd_pie = NULL;

            packet_num = QBM_SPD_PI_GET_PKTNUM(p_spd_pi);
            IPC_ASSERT(packet_num > 0);

            remain_packet_num = 0;
            for (idx = 0; idx < packet_num; idx++) {
                if (idx == 0) {
                    p_spd_pie = QBM_SPD_PI_GET_FIRST_PIE(p_spd_pi);
                } else {
                    ip_packet = QBM_SPD_PAYLOAD_NEXT(ip_packet, payload_len);
                    p_spd_pie = QBM_SPD_PIE_NEXT(p_spd_pie);
                }

                payload_len = QBM_SPD_PIE_GET_PAYLOAD_LEN(p_spd_pie);

                /* Bypass the packets with IGR bit set. */
                if (!QBM_SPD_PIE_GET_IGR(p_spd_pie)) {
                    IPC_ASSERT(payload_len > 0);
                    result = ipc_pkt_do_filter(uplink, spd, fls_set_p, fls_set_cnt, session_type, pdn_id, netif_id, ip_packet, &payload_len, ebi_info, curr_gpd, &filter, &filter_info);

                    if ( (IPC_PKT_DO_FILTER_MATCHED == result && !_FEATURES_CONTAIN(&filter.rules, BWM)) ||
                         (IPC_PKT_DO_FILTER_INVALID_LEN == result) ) {
                        hif_data_trace(IPC_GE_SPD_ENTRY_IGR_INFO, uplink, curr_gpd, idx, payload_len);

                        QBM_SPD_PIE_SET_IGR(p_spd_pie);
                        length -= payload_len;

                        if (QBM_SPD_PIE_GET_EOL(p_spd_pie) && (NULL != p_prev_spd_pie)) {
                            /* Move the EOL bit to the previous SPD entry */
                            IPC_ASSERT(remain_packet_num > 0);

                            QBM_SPD_PIE_SET_EOL(p_prev_spd_pie);
                        }

                        if (IPC_PKT_DO_FILTER_MATCHED == result) {
                            qbm_gpd    *callback_gpd_p;
                            kal_uint8  *callback_gpd_data_p;
                            /*
                             * 1. A packet is indivisible from the SPD, so we need to allocate a GPD for it.
                             * 2. Uplink SPD is not used.
                             * 3. (2014/8/13 Stan.Chen) Use QBM_TYPE_NET_DL, if it use out, use QBM_TYPE_HIF_DL instead.
                             */
                            if (1 != qbmt_alloc_q_no_tail(
                                        (KAL_TRUE == uplink)?QBM_TYPE_NET_UL/*UL*/:QBM_TYPE_NET_DL/*DL*/, /* type */
                                        1, /* buff_num */
                                        (void**)&callback_gpd_p, /* pp_head */
                                        (void**)&callback_gpd_p  /* pp_tail */)) {
                                if (1 != qbmt_alloc_q_no_tail(
                                            (KAL_TRUE == uplink)?QBM_TYPE_HIF_UL/*UL*/:QBM_TYPE_HIF_DL/*DL*/, /* type */
                                            1, /* buff_num */
                                            (void**)&callback_gpd_p, /* pp_head */
                                            (void**)&callback_gpd_p  /* pp_tail */)) {
                                    hif_trace_error(IPC_TR_DO_FILTER_ALLOC_GPD_NG, uplink, 1, curr_gpd, idx, payload_len);
                                    continue;
                                }
                                hif_trace_error(IPC_TR_DO_FILTER_ALLOC_GPD_NG, uplink, 0, curr_gpd, idx, payload_len);
                                continue;
                            }

                            /* Copy data from SPD payload to output GPD */
                            IPC_ASSERT(callback_gpd_p);
                            ipc_set_gpd_datalen(callback_gpd_p, payload_len, (void**)&callback_gpd_data_p);
                            IPC_ASSERT(callback_gpd_data_p);

                            QBM_CACHE_INVALID(ip_packet, payload_len);
                            kal_mem_cpy(callback_gpd_data_p, ip_packet, payload_len);
                            QBM_CACHE_FLUSH(callback_gpd_data_p, payload_len);

                            /* Forward GPD by filter's callback function */
                            ipc_call_filter_cbk(uplink, callback_gpd_p, payload_len, &filter, &filter_info);
                        }
                    } else {
                        remain_packet_num ++;
                        p_prev_spd_pie = p_spd_pie;
                    }
                }

                if (QBM_SPD_PIE_GET_EOL(p_spd_pie)) {
                    /* end of packet list */
                    break;
                }
            }

            /* Update SPD's Transfer Data Length */
            QBM_DES_SET_DATALEN(curr_gpd, length);

        } else {
            /*
             * It's GPD (PDT == 0)
             * There is only one packet, so just do it.
             */
            result = ipc_pkt_do_filter(uplink, spd, fls_set_p, fls_set_cnt, session_type, pdn_id, netif_id, ip_packet, &length, ebi_info, curr_gpd, &filter, &filter_info);
        }

        if ( ( (spd && (0 == remain_packet_num)) || (!spd) ) &&
             ( (IPC_PKT_DO_FILTER_MATCHED == result && !_FEATURES_CONTAIN(&filter.rules, BWM)) ||
               (IPC_PKT_DO_FILTER_INVALID_LEN == result) ) ) {
            /*
             * For either SPD & all packet filtered out or GPD case,
             * extract the SPD/GPD from the list
             */
            if (curr_gpd == first_gpd) {
                if (curr_gpd == last_gpd) {
                    first_gpd = NULL;
                    last_gpd = NULL;

                    IPC_ASSERT(end_of_list);
                    end_of_list = KAL_TRUE; /* All GPD's in the list are freed, exit the loop after curr_gpd released. */
                } else {
                    IPC_ASSERT(next_gpd);
                    first_gpd = next_gpd;
                }
                prev_gpd = NULL;
            } else {
                IPC_ASSERT(prev_gpd);
                if (curr_gpd == last_gpd) {
                    last_gpd = prev_gpd;
                    QBM_DES_SET_NEXT(prev_gpd, NULL);

                    IPC_ASSERT(end_of_list);
                    end_of_list = KAL_TRUE; /* To exit the loop after curr_gpd released. */
                } else {
                    IPC_ASSERT(next_gpd);
                    QBM_DES_SET_NEXT(prev_gpd, next_gpd);
                }
            }
            QBM_DES_SET_NEXT(curr_gpd, NULL);

            if (spd && (0 == remain_packet_num)) {
                /* Destroy SPD since there is no packet remained. */
                IPC_ASSERT(length == 0);

                hif_data_trace(IPC_GE_SPD_ALL_IGR_INFO, uplink, curr_gpd, packet_num);
                qbmt_dest_q(curr_gpd, curr_gpd);
            } else if ( (!spd) && (IPC_PKT_DO_FILTER_MATCHED == result) ) {
                /* GPD & matched case: Forward "curr_gpd" to callback function */
                qbm_gpd *callback_gpd_p;

                length = QBM_DES_GET_DATALEN(curr_gpd);

                if (KAL_TRUE == uplink)
                {   /* For UL GPD, NO unite issue */
                    callback_gpd_p = curr_gpd;
                } else {
                    /* For DL GPD, do unite before actually calling callback functions */
                    ipc_gpd_unite(uplink, curr_gpd, &callback_gpd_p);

                    if (callback_gpd_p != curr_gpd)
                    {
                        hif_data_trace( IPC_GE_DO_FILTER_GPD_UPDATE,
                                        uplink,
                                        curr_gpd,
                                        callback_gpd_p,
                                        (callback_gpd_p)?(QBM_DES_GET_DATALEN(callback_gpd_p)):0);

                        /* Always destroy "curr_gpd" */
                        QBM_DES_SET_NEXT(curr_gpd, NULL);
                        qbmt_dest_q(curr_gpd, curr_gpd);
                    }

                    if (!callback_gpd_p) {
                        hif_data_trace(IPC_GE_UNITE_FAIL_DROP, length, curr_gpd);
                        hif_data_trace(IPC_GE_UNITE_FAIL_DROP_INFO, filter.filter_id,
                                                                    curr_gpd,
                                                                    pdn_id,
                                                                    netif_id);
                        continue;
                    }
                }

                /* Forward GPD by filter's callback function */
                ipc_call_filter_cbk(uplink, callback_gpd_p, length, &filter, &filter_info);
            } else if ( (!spd) && (IPC_PKT_DO_FILTER_INVALID_LEN == result) ) {
                qbmt_dest_q(curr_gpd, curr_gpd);
            }
        } else {
            /* Continue with next SPD/GPD if not matched. */
            prev_gpd = curr_gpd;
        }

    } /* for each GPD, curr_gpd */

    *pp_head = first_gpd;
    *pp_tail = last_gpd;
}

void
ipc_do_ul_filter(
    kal_uint8       session_type,
    kal_uint32      netif_id,
    qbm_gpd       **pp_head,
    qbm_gpd       **pp_tail)
{
    static ipc_filter_list_t   *fls_set[] = {ipc_ul_v4_filter_list_s, ipc_ul_v6_filter_list_s};

	ipc_do_filter(KAL_TRUE, fls_set, sizeof(fls_set)/sizeof(ipc_filter_list_t*), session_type, 0, netif_id, pp_head, pp_tail);
}

void
ipc_do_dl_filter(
    kal_uint8       session_type,
    kal_uint32      netif_id,
    kal_uint32      pdn_id,
    qbm_gpd       **pp_head,
    qbm_gpd       **pp_tail)
{
    static ipc_filter_list_t   *fls_set[] = {ipc_dl_v4_filter_list_s, ipc_dl_v6_filter_list_s};

	ipc_do_filter(KAL_FALSE, fls_set, sizeof(fls_set)/sizeof(ipc_filter_list_t*), session_type, pdn_id, netif_id, pp_head, pp_tail);  
}

#if (IPC_DL_INVALID_LEN_DROP_EN)
void ipc_dl_invalid_len_chk(qbm_gpd **pp_head, qbm_gpd **pp_tail)
{
    qbm_gpd *first_gpd;
    qbm_gpd *last_gpd;
    qbm_gpd *curr_gpd, *curr_bd;
    qbm_gpd *prev_gpd;
    qbm_gpd *next_gpd;
    kal_uint32 length;
    kal_bool end_of_list = KAL_FALSE;
    kal_bool start_of_list = KAL_TRUE;
    kal_uint8 ebi_info = 0;
    kal_bool ebi_info_succeed = KAL_FALSE;
    kal_uint8 *data_ptr;

    first_gpd = *pp_head;
    last_gpd = *pp_tail;

    prev_gpd = NULL;
    end_of_list = (NULL == first_gpd);

    for (curr_gpd = first_gpd; curr_gpd && !end_of_list; curr_gpd = next_gpd){

        next_gpd = QBM_DES_GET_NEXT(curr_gpd);
        end_of_list = (curr_gpd == last_gpd);
        
        // record ebi info in first downlink gpd
        if (KAL_TRUE == start_of_list){
            ebi_info = ((upcm_dlvr_dl_info_t *)QBM_DES_GET_SW_CTRL_FIELD(curr_gpd))->ebi;
            start_of_list = KAL_FALSE;
        }

        length = QBM_DES_GET_DATALEN(curr_gpd);

        if (length > ipc_dl_valid_packet_len_s){
            if (curr_gpd == first_gpd){
                if (KAL_FALSE == ebi_info_succeed){
                    ebi_info_succeed = KAL_TRUE;
                }
                
                if (curr_gpd == last_gpd){
                    first_gpd = NULL;
                    last_gpd = NULL;
    
                    IPC_ASSERT(end_of_list);
                    end_of_list = KAL_TRUE;
                }else {
                    IPC_ASSERT(next_gpd);
                    first_gpd = next_gpd;
                }
                prev_gpd = NULL;
            }else{
                IPC_ASSERT(prev_gpd);
                if (curr_gpd == last_gpd){
                    last_gpd = prev_gpd;
                    QBM_DES_SET_NEXT(prev_gpd, NULL);
    
                    IPC_ASSERT(end_of_list);
                    end_of_list = KAL_TRUE;
                }else{
                    IPC_ASSERT(next_gpd);
                    QBM_DES_SET_NEXT(prev_gpd, next_gpd);
                }
            }
            
            ipc_get_ip_packet(curr_gpd, &curr_bd, &data_ptr, &length);
            // packet info
            hif_data_trace(IPC_DL_INVALID_LEN_CHK, ebi_info, curr_gpd, curr_bd, length, ipc_dl_valid_packet_len_s);
            // dump ip header
            hif_data_trace(IPC_DL_INVALID_LEN_PKT_IP_HDR, 0, IPC_NE_GET_4B(data_ptr));
            hif_data_trace(IPC_DL_INVALID_LEN_PKT_IP_HDR, 1, IPC_NE_GET_4B(data_ptr+4));
            hif_data_trace(IPC_DL_INVALID_LEN_PKT_IP_HDR, 2, IPC_NE_GET_4B(data_ptr+8));
            hif_data_trace(IPC_DL_INVALID_LEN_PKT_IP_HDR, 3, IPC_NE_GET_4B(data_ptr+12));
            hif_data_trace(IPC_DL_INVALID_LEN_PKT_IP_HDR, 4, IPC_NE_GET_4B(data_ptr+16));
            
            QBM_DES_SET_NEXT(curr_gpd, NULL);
            qbmt_dest_q(curr_gpd, curr_gpd);
        }else{
            // restore to succeed GPD
            if (KAL_TRUE == ebi_info_succeed){
                ((upcm_dlvr_dl_info_t *)QBM_DES_GET_SW_CTRL_FIELD(curr_gpd))->ebi = ebi_info;
                ebi_info_succeed = KAL_FALSE;
            }

            prev_gpd = curr_gpd;
        }
    }

    // update head & tail, after re-link list
    *pp_head = first_gpd;
    *pp_tail = last_gpd;    
}
#endif

void
ipc_forward_packet_by_msg(
    msg_type       msg_id,
    void           *context, 
    kal_int32       filter_id,
    qbm_gpd        *head_gpd, 
    qbm_gpd        *tail_gpd, 
    kal_uint32      length)
{
    ipc_filter_t   *filter = (ipc_filter_t *)context;
    ipc_packet_filtered_req_t *req;

    req = (ipc_packet_filtered_req_t *)construct_local_para(sizeof(ipc_packet_filtered_req_t), TD_RESET);
    req->context = filter->module_context;
    req->filter_id = filter_id;
    req->head_gpd = head_gpd;
    req->tail_gpd = tail_gpd;
    req->length = length;
    
    msg_send6(
#ifdef ATEST_SYS_IPCORE
                MOD_NIL, /* src_mod_id */
#else
                MOD_IPCORE, /* src_mod_id */
#endif
                filter->module_id, /* dest_mod_id */
                IPCORE_SAP, /* sap_id */
                msg_id, /* msg_id */
                (local_para_struct *)req, /* local_para_ptr */
                NULL); /* peer_buff_ptr */
}

void
ipc_forward_packet_with_info_by_msg(
    msg_type             msg_id,
    ipc_filter_info_t   *info_p,
    void                *context,
    kal_int32            filter_id,
    qbm_gpd             *head_gpd, 
    qbm_gpd             *tail_gpd, 
    kal_uint32           length)
{
    ipc_filter_t   *filter = (ipc_filter_t *)context;
    ipc_packet_filtered_with_info_req_t *req;

    req = (ipc_packet_filtered_with_info_req_t *)construct_local_para(sizeof(ipc_packet_filtered_with_info_req_t), TD_RESET);
    kal_mem_cpy(&(req->info), info_p, sizeof(ipc_filter_info_t));
    req->context = filter->module_context;
    req->filter_id = filter_id;
    req->head_gpd = head_gpd;
    req->tail_gpd = tail_gpd;
    req->length = length;
    
    msg_send6(
#ifdef ATEST_SYS_IPCORE
                MOD_NIL, /* src_mod_id */
#else
                MOD_IPCORE, /* src_mod_id */
#endif
                filter->module_id, /* dest_mod_id */
                IPCORE_SAP, /* sap_id */
                msg_id, /* msg_id */
                (local_para_struct *)req, /* local_para_ptr */
                NULL); /* peer_buff_ptr */
}

void 
ipc_forward_ul_packet_by_msg(
        void           *context, 
        kal_int32       filter_id,
        qbm_gpd        *head_gpd, 
        qbm_gpd        *tail_gpd, 
        kal_uint32      length)
{
    ipc_forward_packet_by_msg(
        MSG_ID_IPCORE_UL_PACKET_FILTERED_REQ,
        context,
        filter_id,
        head_gpd,
        tail_gpd,
        length
        );
}

void 
ipc_forward_dl_packet_by_msg(
        void           *context, 
        kal_int32       filter_id,
        qbm_gpd        *head_gpd, 
        qbm_gpd        *tail_gpd, 
        kal_uint32      length)
{
    ipc_forward_packet_by_msg(
        MSG_ID_IPCORE_DL_PACKET_FILTERED_REQ,
        context,
        filter_id,
        head_gpd,
        tail_gpd,
        length
        );
}

void 
ipc_forward_ul_packet_with_info_by_msg(
        ipc_filter_info_t   *info_p,
        void                *context, 
        kal_int32            filter_id,
        qbm_gpd             *head_gpd, 
        qbm_gpd             *tail_gpd, 
        kal_uint32           length)
{
    ipc_forward_packet_with_info_by_msg(
        MSG_ID_IPCORE_UL_PACKET_FILTERED_WITH_INFO_REQ,
        info_p,
        context,
        filter_id,
        head_gpd,
        tail_gpd,
        length
        );
}

void 
ipc_forward_dl_packet_with_info_by_msg(
        ipc_filter_info_t   *info_p,
        void                *context, 
        kal_int32            filter_id,
        qbm_gpd             *head_gpd, 
        qbm_gpd             *tail_gpd, 
        kal_uint32           length)
{
    ipc_forward_packet_with_info_by_msg(
        MSG_ID_IPCORE_DL_PACKET_FILTERED_WITH_INFO_REQ,
        info_p,
        context,
        filter_id,
        head_gpd,
        tail_gpd,
        length
        );
}

kal_bool ipc_gpd_chk_is_icmp6_ra(qbm_gpd* gpd)
{
    qbm_gpd* bd;
    kal_uint8* ip_packet;
    kal_uint32 packet_len;
    ipc_packet_info_t packet_info;

    if(!ipc_get_ip_packet(gpd, &bd, &ip_packet, &packet_len) || !ip_packet) {
        return KAL_FALSE;
    }
    
    if(!(IPC_HDR_IS_V6(ip_packet)) || !ipc_get_packet_info(ip_packet, gpd, bd, &packet_info)) {
        return KAL_FALSE;
    } 
    
    return ((packet_info.icmpv6_type == IPC_HDR_ICMP6_TYPE_RA)? KAL_TRUE:KAL_FALSE);
}

kal_bool ipc_spd_chk_is_icmp6_ra(void* ip_packet, kal_uint32 payload_len)
{
    ipc_packet_info_t packet_info;

    if(payload_len <= 0) {
        return KAL_FALSE;
    }

    if(!(IPC_HDR_IS_V6(ip_packet)) || !ipc_get_packet_info_spd(ip_packet, payload_len, &packet_info)) {
        return KAL_FALSE;
    }
    
    return ((packet_info.icmpv6_type == IPC_HDR_ICMP6_TYPE_RA)? KAL_TRUE:KAL_FALSE);
}
