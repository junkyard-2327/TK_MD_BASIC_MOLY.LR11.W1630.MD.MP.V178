Upper = $(subst z,Z,$(subst y,Y,$(subst x,X,$(subst w,W,$(subst v,V,$(subst u,U,$(subst t,T,$(subst s,S,$(subst r,R,$(subst q,Q,$(subst p,P,$(subst o,O,$(subst n,N,$(subst m,M,$(subst l,L,$(subst k,K,$(subst j,J,$(subst i,I,$(subst h,H,$(subst g,G,$(subst f,F,$(subst e,E,$(subst d,D,$(subst c,C,$(subst b,B,$(subst a,A,$(1)))))))))))))))))))))))))))

ACTION_MODS :=

include make/pcore/buildConfig.mak

ifeq ($(strip $(CORE_ROOT)),L1CORE)
  INFOMAKELOG := $(COPRO_PROJDIR)/bin/log/infomake.log
endif
include $(INFOMAKELOG)

$(info COMPLIST    = $(COMPLIST))
$(info ACTION_MODS = $(ACTION_MODS))
$(info INFOMAKELOG = $(INFOMAKELOG))
$(info PROJECT_MAKEFILE = $(PROJECT_MAKEFILE))

CHK_COMPLIST = $(filter $(ACTION_MODS),$(COMPLIST))

ifneq ($(words $(CHK_COMPLIST)),0)
  $(info NEED_ACTION_MODS = $(foreach comp,$(CHK_COMPLIST),$(comp)))
else
  ifeq ($(strip $(CORE_ROOT)),L1CORE)
    $(error $(foreach comp,$(ACTION_MODS),"$(comp)") NOT in COMPLIST in l1core side)
  else
    $(error $(foreach comp,$(ACTION_MODS),"$(comp)") NOT in COMPLIST in pcore side)
  endif
endif

.PHONY: all

all:
	@echo CHECK done.
