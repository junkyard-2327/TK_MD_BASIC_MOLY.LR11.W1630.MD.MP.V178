#include "sp_EVS_CodIntf.h"
#include "sp_EVS_drv.h"
#include "sp_EVS_exp.h"

EVS_Drv_Par  gEVS_DrvPar;
EVS_Drv2_Par gEVS_Drv2Par;
EVS_Enc_Par  gEVS_EncPar;
EVS_Dec_Par  gEVS_DecPar;

kal_uint8 gaucEVS_EncHB[320];
kal_uint8 gaucEVS_DecHB[320];
