ifeq ($(strip $(RTOS)),NUCLEUS_V2)
  CATEGORY_INCDIRS += ${COMMON_ROOT}/service/nucleus_v2/inc
  CATEGORY_INCDIRS += ${COMMON_ROOT}/service/kal/common/include
  CATEGORY_INCDIRS += ${COMMON_ROOT}/service/kal/nucleus/include
  CATEGORY_INCDIRS += ${COMMON_ROOT}/service/kal/mlib/include
endif


CATEGORY_INCDIRS +=$(strip ${CORE_ROOT})/service/sst/include \
                   $(strip ${COMMON_ROOT})/service/sst/include
CATEGORY_DEFS += 