#ifndef __AUDIO_STRUCT_H__
#define __AUDIO_STRUCT_H__

#include "kal_general_types.h"
#include "kal_public_api.h"

/* for MACE */
//#include "audio_msgid.h"
#include "global_sap.h"


typedef struct{
    LOCAL_PARA_HDR  /* size is 4 bytes now */
	kal_uint8 data[256];
}audio_logging_sidetone_struct;

typedef struct{
    LOCAL_PARA_HDR  /* size is 4 bytes now */
	kal_uint8	local_hdr_len;
	kal_uint8	reserved[3];
	kal_uint32	data_len;
	kal_uint8	data[256];
}audio_logging_speech_struct;
/*
typedef struct{
    LOCAL_PARA_HDR  // size is 4 bytes now 
	kal_uint8 tx_data[256];
}audio_logging_bt_tx_data_struct;
*/
typedef struct{
    LOCAL_PARA_HDR  /* size is 4 bytes now */
	kal_uint8	header_count;
	kal_uint32  pkt_length;
	kal_uint32  pkt_number;
	kal_uint8   tx_data[256];
}audio_logging_bt_tx_struct;

typedef struct{
    LOCAL_PARA_HDR  /* size is 4 bytes now */
	kal_uint8	header_count;
	kal_uint32  pkt_length;
	kal_uint32  pkt_number;
	kal_uint8   rx_data[256];
}audio_logging_bt_rx_struct;


typedef struct{
    LOCAL_PARA_HDR  // size is 4 bytes now 
	kal_uint8	header_count;
	kal_uint8	bt_type;
	kal_uint8	bt_dir;
	kal_uint16	seq;
	kal_uint32	pkt_length;
	kal_uint8   bt_data[256];
}audio_logging_bt_struct;

#endif /* __AUDIO_STRUCT_H__ */
