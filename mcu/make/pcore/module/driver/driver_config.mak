ifeq ($(strip $(RTOS)),NUCLEUS_V2)
  CATEGORY_INCDIRS += ${COMMON_ROOT}/service/nucleus_v2/inc
  CATEGORY_INCDIRS += ${COMMON_ROOT}/service/kal/common/include
  CATEGORY_INCDIRS += ${COMMON_ROOT}/service/kal/nucleus/include
  CATEGORY_INCDIRS += ${COMMON_ROOT}/service/kal/mlib/include
endif
ifeq ($(strip $(RTOS)),NUCLEUS)
  CATEGORY_INCDIRS    += ${COMMON_ROOT}/service/nucleus/inc
  CATEGORY_INCDIRS += ${COMMON_ROOT}/service/kal/common/include
  CATEGORY_INCDIRS += ${COMMON_ROOT}/service/kal/nucleus/include
  CATEGORY_INCDIRS += ${COMMON_ROOT}/service/kal/mlib/include
endif

ifeq ($(strip $(RTOS)),THREADX)
  CATEGORY_INCDIRS += ${COMMON_ROOT}/service/kal/common/include
  CATEGORY_INCDIRS += ${COMMON_ROOT}/service/kal/mlib/include
endif

CATEGORY_DEFS += 
