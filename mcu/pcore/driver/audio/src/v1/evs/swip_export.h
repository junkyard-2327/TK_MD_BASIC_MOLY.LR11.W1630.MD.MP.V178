/*******************************************************************************
 * Included header files
 *******************************************************************************/

#include "kal_general_types.h"
#include "kal_public_api.h"

/*************************************************************************
 * Type definitions
 *************************************************************************/
 
/* max size of SWIP secret key&array in bytes*/
#define SWIP_AES_KEY_LEN								 16
#define SWIP_AES_ARRAY_LEN								 16

/* Error types of error_msg*/
#define SWIP_BIND_DEFAULT						 	0x00
#define SWIP_BIND_ERROR_NONE						0x01
#define SWIP_BIND_ERROR_BYPASS_CHALLENGE			0x02
#define SWIP_BIND_ERROR_CHALLENGE_FAIL				0x04
#define SWIP_BIND_ERROR_PLATFORM_CHECK_FAIL			0x08
#define SWIP_BIND_ERROR_ARRAY_LEN_NOT_MATCH			0x10
#define SWIP_BIND_ERROR_SEED_OR_KEY_IS_NULL			0x20
#define SWIP_BIND_ALWAYS_FAIL						0x40

/*****************************************************************************
 * FUNCTION
 *   SWIP_BIND(SB)
 *
 * DESCRIPTION
 *   EVS use this function to challenge with SST
 *
 * PARAMETERS
 *   rand_array(r)           [IN] : input data source, rand_array from EVS
 *	 challenge_array(c)		 [IN] : input data source, defalut NULL
 *	 error_msg(e)			 [OUT] : error msg for debug, defalut NULL
 *****************************************************************************/
#define SB(r, c, e, s, k)																				\
	do	{																								\
		s[0] = 0x83FFDD44;																				\
		s[1] = 0xE4BC732C;																				\
		s[2] = 0x21794BEE;																				\
		s[3] = 0xE6D923F7;																				\
		k[0] = 0x90FA06C4;																				\
		k[1] = 0xD6200965;																				\
		k[2] = 0xA786C37F;																				\
		k[3] = 0xB4D60175;																				\
		*e = SWIP_BIND_DEFAULT; 																		\
		SC(r, c, e);																					\
		if(*e == 0) 																					\
		{																								\
			*e |= SWIP_BIND_ERROR_BYPASS_CHALLENGE; 													\
		}																								\
		if(c == NULL) 																					\
		{																								\
			*e |= SWIP_BIND_ERROR_BYPASS_CHALLENGE; 													\
		}																								\
		SSC((kal_uint8*)s, (kal_uint8*)k, e);															\
		SA(0, c, (kal_uint32*)s, (kal_uint32*)k);														\
		if(memcmp(r, c, SWIP_AES_ARRAY_LEN) != 0)														\
			*e |= SWIP_BIND_ERROR_CHALLENGE_FAIL;														\
		ST(e);																							\
		if(*e == SWIP_BIND_ERROR_NONE)																	\
			SBR = KAL_TRUE;																				\
	} while(0)


extern void SSC(kal_uint8 * es, kal_uint8 * ek, kal_int32 * e);

extern void SA(kal_uint8 d, kal_uint32 * aa , kal_uint32 * as, kal_uint32 * ak);

extern void SC(kal_uint32 *r, kal_uint32 *c, kal_int32 * e);

extern void ST(kal_int32 * e);
