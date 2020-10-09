<How to Use>
adt_codegen.pl %ADT(AUTO_TCM) Function List File%  %Output C File%  %Output H File%

PS. %Output C File% must be added into module make file e.g "el1d.mak"

-------------------------------------------------------------------------------------------
<Example>
./l1core/tools/adt/adt_codegen.pl ./l1core/modem/el1/el1d/misc/auto_tcm_function_list_tk6291_el1d.txt ./l1core/modem/el1/el1d/src/common/ladt.c  ./l1core/modem/el1/el1d/inc/common/ladt.h
-------------------------------------------------------------------------------------------
<ADT Function List File Fomat>
Usually, it is the same file with AUTO_TCM function list file
The following is the example

[ADT][SET_TCM_FN] void EL1D_ADT_Switch_TCM( void )   #The function to switch all ADT function pointer to TCM ones
[ADT][SET_EMI_FN] void EL1D_ADT_Switch_EMI( void )   #The function to switch all ADT function pointer to EMI ones
[ADT][JMP_FP] __attribute__((section("INTSRAM_RW")))
[ADT][JMP_FN] __attribute__((section("INTSRAM_ROCODE"))) __attribute__((always_inline))
[ADT][TCM_FN] __attribute__((section("##############"))) __attribute__((noinline))
EL1D_CM_CSIF_MPC_CTRL_RPT_5ms_Valid_Set lcmcsifhandler.obj
EL1D_CMD_Get_Free_Lisr_Command lcmd.obj
EL1D_RxTool_Get_RX_ABS_SF_Time lrxtool.obj
EL1D_Esl_Init el1d_esl.obj
EL1D_RF_CW_TX_Band_Selection lrfdepdata.obj
EL1D_RxFsm_Get_POS_Pre_Sync_Length lrxfsm.obj
EL1D_RxSync_Is_Next_Pre_SYNC_State lrxsync.obj
EL1D_RxCmd_Parse_TX_Command lrxcmd.obj
EL1D_RxFsm_SF_Tick_Post_Handler lrxfsm.obj
EL1D_RxFsm_Get_Rx_Next_State lrxfsm.obj
el1d_rx_fsm_srv_rx_run lrxfsm.obj



