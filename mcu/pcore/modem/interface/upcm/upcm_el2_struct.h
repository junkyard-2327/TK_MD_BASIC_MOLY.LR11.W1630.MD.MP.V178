#ifndef  UPCM_EL2_STRUCT_INC
#define  UPCM_EL2_STRUCT_INC

#include "kal_public_api.h"
#include "ps_public_enum.h"
#include "ps_public_struct.h"

typedef struct 
{
    LOCAL_PARA_HDR 

	/* the bitmap of the ims-related EPS bearers */
    kal_uint32 ims_epsb_bmp; // first LSB is not used due to that EBI begin with 0

}upcm_el2_ims_epsb_bmp_struct;

#endif
