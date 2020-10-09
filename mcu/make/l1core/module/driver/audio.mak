# Define source file folder to SRC_LIST
ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
   AUDFOLDER = ${CORE_ROOT}/driver/audio/src/v2
   AUD_SOLUTION      =  V2
else   
   AUDFOLDER = ${CORE_ROOT}/driver/audio/src/v1
   AUD_SOLUTION      =  V1
endif


#ifeq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
ifneq ($(strip $(TEST_LOAD_TYPE)),NONE)
  SRC_LIST = $(strip $(AUDFOLDER))/dummy_audio_L.c
else #ifneq ($(strip $(TEST_LOAD_TYPE)),NONE)


ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
ifeq ($(strip $(DHL_SUPPORT)),TRUE)
  SRC_LIST = $(strip $(CUS_MTK_REL))/dhl/l1trace/l1audio_trace_l1core.c
else
  SRC_LIST = $(strip $(CUS_MTK_REL))/ts/l1trace/l1audio_trace_l1core.c
endif
else
  SRC_LIST = $(strip $(CGEN_L1_OUTDIR))/l1audio_trace_l1core.c
endif


SRC_LIST += $(strip $(AUDFOLDER))/am_L.c \
            $(strip $(AUDFOLDER))/sal_exp.c \
            $(strip $(AUDFOLDER))/sal_impl.c \
            $(strip $(AUDFOLDER))/sal_dsp.c
            

endif #ifneq ($(strip $(TEST_LOAD_TYPE)),NONE)


#  Define include path lists to INC_DIR
INC_DIR = $(strip $(AUDFOLDER)) \
          $(strip $(AUDFOLDER))/inc \
          ${CORE_ROOT}/interface/driver/devdrv/mdipc \
          ${COMMON_ROOT}/interface/modem/general


SRC_PATH += $(strip $(AUDFOLDER))
