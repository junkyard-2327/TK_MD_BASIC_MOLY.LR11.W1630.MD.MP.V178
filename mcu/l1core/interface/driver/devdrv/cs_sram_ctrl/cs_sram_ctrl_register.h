#if (defined(TK6291))
    #include "cs_sram_ctrl_register_tk6291.h"
#elif (defined(MT6755))
    #include "cs_sram_ctrl_register_mt6755.h"
#elif (defined(MT6797))
    #include "cs_sram_ctrl_register_mt6797.h"
#elif (defined(MT6750) || defined(MT6750S))
    #include "cs_sram_ctrl_register_mt6750.h"
#elif (defined(MT6757))
    #include "cs_sram_ctrl_register_mt6757.h"
#else
    #error "SRAM control didn't support on this chip!!!"
#endif
