#ifndef __DRV_PCM_H__
#define __DRV_PCM_H__

#include "dcl.h"

/*****************************************************************************
 *  					 Symbol/Type Definition 	                         *
 *****************************************************************************/

typedef struct pcm_config_t{
	kal_uint32	pc_diff;
} pcm_config;

typedef enum {
    PCMON_OK,
    PCMON_FAIL,
    PCMON_UNSUPPORTED,
    PCMON_INVALID_ARGUMENT,
    PCMON_ALREADY_STARTED,
    PCMON_ALREADY_STOPPED,
} PCMON_RET;

/**
 * Stop source of PCMon
 */
typedef enum {
    PCMON_SRC_NONE = 0,
    PCMON_SRC_AP_BUSMON = 0x1,
    PCMON_SRC_PS_BUSMON = 0x2,
    PCMON_SRC_L1_BUSMON = 0x4,
    PCMON_SRC_CTI = 0x8,
    PCMON_SRC_AP_BUSERR = 0x10,
    PCMON_SRC_PS_BUSERR = 0x20,
    PCMON_SRC_L1_BUSERR= 0x40,
    PCMON_SRC_RGU = 0x80,
    PCMON_SRC_RMPU = 0x100,
    PCMON_SRC_SELF = 0x200,
} PCMON_STOP_SOURCE;

/**
 * PC record
 */
typedef struct pcm_pc_record_t {
    kal_uint32 pc;
    kal_uint32 cid;
} PCM_PC_RECORD;

/**
 * Data access record
 */
typedef struct pcm_da_record_t {
    kal_uint32 pc;
    kal_uint32 da;
} PCM_DA_RECORD;

/**
 * Total PCMon record
 */
typedef struct pcm_record_t {
    PCM_PC_RECORD pc_piped[3];
    PCM_DA_RECORD da_piped[2];
    PCM_PC_RECORD pc_record[32];
    PCM_DA_RECORD da_record[32];
} PCM_RECORD;

/*****************************************************************************
 *						 function declaration                                *
 *****************************************************************************/
void drv_pcm_reset(void);
PCMON_RET drv_pcm_initialize(void);
PCMON_RET drv_pcm_set_config(pcm_config *pcm_cfg);
void drv_pcm_get_config(pcm_config *pcm_cfg);
PCMON_RET drv_pcm_start_capture(void);
PCMON_RET drv_pcm_stop_capture(void);
PCMON_RET drv_pcm_get_pc_pair(kal_uint8 num, kal_uint32 *pc0, kal_uint32 *pc1);
PCMON_RET drv_pcm_get_cid_pair(kal_uint8 num, kal_uint32 *cid0, kal_uint32 *cid1);
PCMON_RET drv_pcm_get_da(kal_uint8 num, kal_uint32 *pc, kal_uint32 *da);
kal_uint32 drv_pcm_get_pc_count();
kal_uint32 drv_pcm_get_da_count();

PCMON_RET drv_l1pcm_start_capture(void);
PCMON_RET drv_l1pcm_stop_capture(void);
PCMON_RET drv_l1pcm_get_pc_pair(kal_uint8 num, kal_uint32 *pc0, kal_uint32 *pc1);
PCMON_RET drv_l1pcm_get_da(kal_uint8 num, kal_uint32 *pc, kal_uint32 *da);
kal_uint32 drv_l1pcm_get_pc_count();
kal_uint32 drv_l1pcm_get_da_count();

///////////////////////////////////////////////////////////////////////////////
/// \brief          This function is used to get stop source.
///
/// \param [in/out] source A pointer of integer to store stop source bit mask.
///
/// \return         PCMON_OK if PCMon is stopped.
/// \return         PCMON_FAIL if PCMon is not stopped.
///////////////////////////////////////////////////////////////////////////////
PCMON_RET drv_pcm_get_stop_source(kal_uint32 *source);

///////////////////////////////////////////////////////////////////////////////
/// \brief                      This function is used to backup PC/DA record and 
///                             re-start PCMon.
///
/// \param [in] mcu             KAL_TRUE means backup PC/DA record by MCU.
///                             KAL_FALSE means backup PC/DA record by GDMA.
/// \param [in/out] data_ptr    A pointer of buffer to store PC/DA record.
/// \param [in] size            Size of data_ptr in byes. This value must be 256.
/// \param [in] mask            KAL_TRUE means mask RMPU stop source after backup.
///                             KAL_FALSE means unmask RMPU stop source after backup.
///
/// \return                     PCMON_INVALID_ARGUMENT means \size if not the 
///                             proper value.
/// \return                     PCMON_OK if backup and restart are done.
/// \return                     PCMON_FAIL if PCMon is not stopped. Backup can not 
///                             be done.
///////////////////////////////////////////////////////////////////////////////
PCMON_RET drv_pcm_backup_and_restart(kal_bool mcu, PCM_RECORD *data_ptr, kal_bool mask);

///////////////////////////////////////////////////////////////////////////////
/// \brief                      This function is used to mask/un-mask stop source.
///
/// \param [in] source          Stop source enumeration.
///                             Please refer to PCMON_STOP_SOURCE.
/// \param [in] mask            KAL_TRUE means mask stop source.
///                             KAL_FALSE means unmask stop source.
///
/// \return                     PCMON_OK if mask/un-mask operation is done.
///////////////////////////////////////////////////////////////////////////////
PCMON_RET drv_pcm_mask_stop_source(kal_uint32 source, kal_bool mask);

///////////////////////////////////////////////////////////////////////////////
/// \brief                      This function is used to poll backup is done.
///
/// \return                     PCMON_OK if backup is done.
///////////////////////////////////////////////////////////////////////////////
PCMON_RET drv_pcm_poll_backup_done();

///////////////////////////////////////////////////////////////////////////////
/// \brief                      This function is used to check backup is done.
///
/// \return                     KAL_TRUE if backup flow of PCore and L1Core are done.
/// \return                     KAL_FALSE if not all backup flow are done.
///////////////////////////////////////////////////////////////////////////////
kal_bool drv_pcm_is_backup_done();

#endif /* end of __DRV_PCM_H__ */
