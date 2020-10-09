# Define source file lists to SRC_LIST
SRC_LIST  = ${CORE_ROOT}/driver/devdrv/common/src/devdrv_common.c \
            ${COMMON_ROOT}/driver/devdrv/pcmon/src/drv_pcmon.c \
            ${COMMON_ROOT}/driver/devdrv/asm/src/drv_asm.c \
            $(strip $(COMMON_ROOT))/driver/devdrv/ect/src/ect.c \
            ${COMMON_ROOT}/driver/devdrv/pfb/src/drv_pfb.c
ifeq ($(filter __ARM7EJ_S__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += ${CORE_ROOT}/driver/devdrv/common/src/$(COMPILER)/mon_counter.S
endif

#SRC_LIST = ${CORE_ROOT}/driver/devdrv/common/src/drv_comm.c \
		   ${CORE_ROOT}/driver/devdrv/common/src/$(COMPILER)/mon_counter.S

# Define include path lists to INC_DIR
INC_DIR  = ${CORE_ROOT}/driver/devdrv/common/inc \
           ${CORE_ROOT}/driver/devdrv/trace \
		   ${COMMON_ROOT}/driver/sys_drv/cache/inc \
           ${COMMON_ROOT}/interface/driver/devdrv/ect \
           ${COMMON_ROOT}/service/sst/include \
           ${CORE_ROOT}/service/sst/include \
           ${COMMON_ROOT}/service/sss/interface/inc \
           ${CORE_ROOT}/service/sys_svc/gfh/public \
           ${CORE_ROOT}/interface/service/sys_svc \
           $(strip $(PROJDIR))/custom/driver/drv_gen \
           ${COMMON_ROOT}/interface/service/sst \
           ${COMMON_ROOT}/driver/devdrv/pcmon/inc \
           ${COMMON_ROOT}/driver/devdrv/asm/inc \
           ${CORE_ROOT}/interface/driver/sib_drv/scc \
           ${COMMON_ROOT}/driver/devdrv/pfb/inc \
           ${CORE_ROOT}/driver/sib_drv/mtad/inc

# Define the specified compile options to COMP_DEFS
COMP_DEFS =


# Define the source file search paths to SRC_PATH
SRC_PATH  = ${CORE_ROOT}/driver/devdrv/common/src \
		  ${CORE_ROOT}/driver/devdrv/common/src/$(COMPILER)

-include make/${CORE_ROOT}/module/driver/devdrv/gpt.mak

-include make/${CORE_ROOT}/module/driver/devdrv/uart.mak
-include make/${CORE_ROOT}/module/driver/devdrv/gdma.mak
-include make/${CORE_ROOT}/module/driver/devdrv/l1gdma.mak
-include make/${CORE_ROOT}/module/driver/devdrv/usim.mak
-include make/${CORE_ROOT}/module/driver/devdrv/coresight.mak
-include make/${CORE_ROOT}/module/driver/devdrv/gpio.mak
-include make/${CORE_ROOT}/module/driver/devdrv/eint.mak
-include make/${CORE_ROOT}/module/driver/devdrv/dem.mak
#-include make/${CORE_ROOT}/module/driver/devdrv/pfc.mak
-include make/${CORE_ROOT}/module/driver/devdrv/idc.mak
-include make/${CORE_ROOT}/module/driver/devdrv/cirq.mak
-include make/${CORE_ROOT}/module/driver/devdrv/us_counter.mak
-include make/${CORE_ROOT}/module/driver/devdrv/devdrv_fakeapi.mak
-include make/${CORE_ROOT}/module/driver/devdrv/auxadc.mak
#-include make/${CORE_ROOT}/module/driver/mc.mak
-include make/${CORE_ROOT}/module/driver/devdrv/rtc.mak
#-include make/${CORE_ROOT}/module/driver/devdrv/malmo.mak
-include make/${CORE_ROOT}/module/driver/devdrv/pmic.mak
-include make/${CORE_ROOT}/module/driver/devdrv/pmic_wrap.mak
-include make/${CORE_ROOT}/module/driver/devdrv/bsi.mak
-include make/${CORE_ROOT}/module/driver/devdrv/cfgctl.mak
-include make/${CORE_ROOT}/module/driver/devdrv/f32k_clk.mak
-include make/${CORE_ROOT}/module/driver/devdrv/dcm.mak
-include make/${CORE_ROOT}/module/driver/devdrv/emi.mak
-include make/${CORE_ROOT}/module/driver/devdrv/pll.mak
-include make/${CORE_ROOT}/module/driver/devdrv/iomux.mak
-include make/${CORE_ROOT}/module/driver/devdrv/busmon.mak
-include make/${CORE_ROOT}/module/driver/devdrv/pdn.mak
-include make/${CORE_ROOT}/module/driver/devdrv/arm7wdt.mak
-include make/${CORE_ROOT}/module/driver/devdrv/boot_init.mak
-include make/${CORE_ROOT}/module/driver/devdrv/pw.mak
-include make/${CORE_ROOT}/module/driver/devdrv/chr_det.mak
-include make/${CORE_ROOT}/module/driver/devdrv/bus.mak
-include make/${CORE_ROOT}/module/driver/devdrv/i2c_pmic.mak

-include make/${CORE_ROOT}/module/driver/devdrv/rstctl.mak
-include make/${CORE_ROOT}/module/driver/devdrv/mdipc.mak
-include make/${CORE_ROOT}/module/driver/devdrv/mdl_ebc.mak
-include make/${CORE_ROOT}/module/driver/devdrv/ect.mak
-include make/${CORE_ROOT}/module/driver/devdrv/elm.mak
-include make/${CORE_ROOT}/module/driver/devdrv/mdap_interface.mak

ifeq ($(strip $(COMPILER)),GCC)
    CFLAGS += -Werror
endif

ifneq ($(filter TRUE,$(SIM_SWTICH_CONTROLLER_MT6306)),)
  -include make/${CORE_ROOT}/module/driver/devdrv/mt6306.mak
endif

# These modules have no HW & Drv now, only fake api for compile
#-include make\bsp\devdrv\lcd.mak

ifeq ($(strip $(TEST_LOAD_TYPE)),BASIC)
  INC_DIR += ${COMMON_ROOT}/interface/service/hif \
    ${CORE_ROOT}/interface/service/hif
endif
