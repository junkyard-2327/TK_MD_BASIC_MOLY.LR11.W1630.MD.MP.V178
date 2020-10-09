#ifdef __LTE_RAT__ 
		#include "log2SD_Catcher_filters_4G.ini"
#elif defined (__UMTS_RAT__) || defined (__UMTS_TDD128_MODE__)
		#include "log2SD_Catcher_filters_3G.ini"
#else
		#include "log2SD_Catcher_filters_2G_FDD.ini"
#endif
