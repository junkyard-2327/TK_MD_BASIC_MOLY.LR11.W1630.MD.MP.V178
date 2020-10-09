

CATEGORY_INCDIRS += $(strip ${PCORE_ROOT})/modem/interface/general \
                    $(strip ${PCORE_ROOT})/modem/interface/l4 \
                    $(strip ${PCORE_ROOT})/modem/interface/l4misc \
                    $(strip ${PCORE_ROOT})/modem/l4/include \
                    $(strip ${PCORE_ROOT})/modem/l4/atci/include \
                    $(strip ${PCORE_ROOT})/modem/l4/l4c/include/common \
                    $(strip ${PCORE_ROOT})/modem/l4/l4c/include/proc \
                    $(strip ${PCORE_ROOT})/modem/l4/csm/cc/include \
                    $(strip ${PCORE_ROOT})/modem/l4/uem/include \
                    $(strip ${PCORE_ROOT})/modem/l4/phb/include \
                    $(strip ${PCORE_ROOT})/modem/l4/csm/cc/include \
                    $(strip ${PCORE_ROOT})/modem/l4/csm \
                    $(strip ${PCORE_ROOT})/modem/l4/smsal/include \
                    $(strip ${PCORE_ROOT})/modem/l4/csm/ss/asn1/gen/include \
                    $(strip ${PCORE_ROOT})/modem/l4/smu/include \
                    $(strip ${PCORE_ROOT})/modem/l4/smslib/include \
                    $(strip ${CORE_ROOT})/modem/gl1/l1d_ext


ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R8_SUPPORT)
  CATEGORY_INCDIRS += $(strip ${CORE_ROOT})/modem/ul1/ul1_hs_plus/ul1d_ext
else
  ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R7_SUPPORT)
    CATEGORY_INCDIRS += $(strip ${CORE_ROOT})/modem/ul1/ul1_hs_plus/ul1d_ext
  else
    ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLATFORM)),)
      CATEGORY_INCDIRS += $(strip ${CORE_ROOT})/modem/ul1/ul1_hs/ul1d_ext
    endif
  endif
endif

CATEGORY_DEFS += 
