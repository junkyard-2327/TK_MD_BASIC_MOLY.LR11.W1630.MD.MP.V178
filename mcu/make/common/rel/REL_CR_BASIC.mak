#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2005
#
#  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
#  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
#  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
#  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
#  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
#  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
#  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
#  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
#  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
#  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
#  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
#  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
#
#  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
#  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
#  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
#  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
#  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
#  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
#  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
#  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
#  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
#  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
#

# *************************************************************************
# Custom Release Component Configuration
# *************************************************************************
# Be sure the following:
#    1. COMPLIST(for CUSTOM_RELEASE)      = CUS_REL_SRC_COMP + CUS_REL_PAR_SRC_COMP
#    2. CUS_REL_SRC_COMP + CUS_REL_PAR_SRC_COMP + CUS_REL_MTK_COMP = COMPLIST(CUSTOM_RELEASE = False)

CUS_REL_OPTION_FILTER   = TRUE
CUS_REL_HISTORY_FILTER  = TRUE
REL_PACKAGE_LEVEL = CR_BASIC

CUS_REL_BASE_COMP       =
CUS_REL_HDR_COMP        =
CUS_REL_FILES_LIST      =
CUS_REL_OBJ_LIST        =
NON_REL_FILES_LIST      =
NON_REL_DIRS_LIST       =

# Forbidden feature
#ifdef CHIP_VERSION_CHECK
#  ifneq ($(strip $(CHIP_VERSION_CHECK)),TRUE)
#    $(error Please set CHIP_VERSION_CHECK as TRUE !!)
#  endif
#endif

ifndef LEVEL
  LEVEL = LEVEL2_SRC
endif

include make/common/rel/REL_COMP_CR_BASIC.mak

# reset for UCR
CUS_REL_BASE_COMP :=

# universal common
CUS_REL_BASE_COMP += ../common/interface/driver/sys_drv

# from make
CUS_REL_BASE_COMP += make/common/modem_spec
CUS_REL_BASE_COMP += make/l1core/module/driver/devdrv
CUS_REL_BASE_COMP += make/pcore/module/driver/devdrv

# from common
CUS_REL_BASE_COMP += common/driver/devdrv
CUS_REL_BASE_COMP += common/driver/devdrv/asm/inc
CUS_REL_BASE_COMP += common/driver/devdrv/asm/src
CUS_REL_BASE_COMP += common/driver/devdrv/ect/src
CUS_REL_BASE_COMP += common/driver/devdrv/gpt/inc
CUS_REL_BASE_COMP += common/driver/devdrv/gpt/src
CUS_REL_BASE_COMP += common/driver/devdrv/iomux/inc
CUS_REL_BASE_COMP += common/driver/devdrv/mdap_interface/inc
CUS_REL_BASE_COMP += common/driver/devdrv/mdap_interface/src
CUS_REL_BASE_COMP += common/driver/devdrv/pcmon/inc
CUS_REL_BASE_COMP += common/driver/devdrv/pcmon/src
CUS_REL_BASE_COMP += common/driver/devdrv/pfb/inc
CUS_REL_BASE_COMP += common/driver/devdrv/pfb/src
CUS_REL_BASE_COMP += common/driver/devdrv/us_counter/inc
CUS_REL_BASE_COMP += common/driver/devdrv/us_counter/src
CUS_REL_BASE_COMP += common/driver/dp_engine/che/include
CUS_REL_BASE_COMP += common/driver/sleep_drv/inc
CUS_REL_BASE_COMP += common/driver/sys_drv/cache/inc
CUS_REL_BASE_COMP += common/driver/sys_drv/cache/src
CUS_REL_BASE_COMP += common/driver/sys_drv/dormant/inc
CUS_REL_BASE_COMP += common/driver/sys_drv/dormant/src
CUS_REL_BASE_COMP += common/driver/sys_drv/init/inc
CUS_REL_BASE_COMP += common/driver/sys_drv/init/src
CUS_REL_BASE_COMP += common/driver/sys_drv/pmu/inc
CUS_REL_BASE_COMP += common/driver/sys_drv/pmu/src
CUS_REL_BASE_COMP += common/driver/sys_drv/timer/src
CUS_REL_BASE_COMP += common/interface/common
CUS_REL_BASE_COMP += common/interface/cross_core
CUS_REL_BASE_COMP += common/interface/driver/audio
CUS_REL_BASE_COMP += common/interface/driver/devdrv/asm
CUS_REL_BASE_COMP += common/interface/driver/devdrv/dcm
CUS_REL_BASE_COMP += common/interface/driver/devdrv/ect
CUS_REL_BASE_COMP += common/interface/driver/devdrv/pcmon
CUS_REL_BASE_COMP += common/interface/driver/devdrv/pfb
CUS_REL_BASE_COMP += common/interface/driver/dp_engine/che
CUS_REL_BASE_COMP += common/interface/driver/md_drv
CUS_REL_BASE_COMP += common/interface/driver/peripheral
CUS_REL_BASE_COMP += common/interface/driver/sleep_drv
CUS_REL_BASE_COMP += common/interface/driver/sys_drv
CUS_REL_BASE_COMP += common/interface/middleware/meta
CUS_REL_BASE_COMP += common/interface/modem/general
CUS_REL_BASE_COMP += common/interface/modem/l1/fdd/external
CUS_REL_BASE_COMP += common/interface/modem/l1/gsm/external
CUS_REL_BASE_COMP += common/interface/modem/l1/lte/external
CUS_REL_BASE_COMP += common/interface/modem/l1/mml1/external
CUS_REL_BASE_COMP += common/interface/modem/l1/tdd
CUS_REL_BASE_COMP += common/interface/modem/l4
CUS_REL_BASE_COMP += common/interface/modem/sim
CUS_REL_BASE_COMP += common/interface/sap
CUS_REL_BASE_COMP += common/interface/sap/drv
CUS_REL_BASE_COMP += common/interface/sap/md
CUS_REL_BASE_COMP += common/interface/sap/mw
CUS_REL_BASE_COMP += common/interface/sap/svc
CUS_REL_BASE_COMP += common/interface/service/asn1_common
CUS_REL_BASE_COMP += common/interface/service/config
CUS_REL_BASE_COMP += common/interface/service/dhl
CUS_REL_BASE_COMP += common/interface/service/hif
CUS_REL_BASE_COMP += common/interface/service/kal
CUS_REL_BASE_COMP += common/interface/service/nvram
CUS_REL_BASE_COMP += common/interface/service/qmu_bm
CUS_REL_BASE_COMP += common/interface/service/sst
CUS_REL_BASE_COMP += common/interface/service/stacklib
CUS_REL_BASE_COMP += common/interface/service/sys_svc
CUS_REL_BASE_COMP += common/modem/gl1/l1d_ext
CUS_REL_BASE_COMP += common/modem/interface/general
CUS_REL_BASE_COMP += common/modem/interface/l1/inner
CUS_REL_BASE_COMP += common/modem/interface/l1/mml1
CUS_REL_BASE_COMP += common/modem/sbp
CUS_REL_BASE_COMP += common/service/config/src/hal
CUS_REL_BASE_COMP += common/service/dhl/database
CUS_REL_BASE_COMP += common/service/kal/adaptation/include
CUS_REL_BASE_COMP += common/service/kal/common/include
CUS_REL_BASE_COMP += common/service/kal/mlib/include
CUS_REL_BASE_COMP += common/service/kal/nucleus/include
CUS_REL_BASE_COMP += common/service/nucleus_v2/inc
CUS_REL_BASE_COMP += common/service/sss/interface/inc
CUS_REL_BASE_COMP += common/service/sss/lib
CUS_REL_BASE_COMP += common/service/sst/include
CUS_REL_BASE_COMP += common/tools

# from pcore
CUS_REL_BASE_COMP += pcore/custom/driver/common
CUS_REL_BASE_COMP += pcore/custom/driver/drv/Drv_Tool
CUS_REL_BASE_COMP += pcore/custom/middleware/common
CUS_REL_BASE_COMP += pcore/custom/modem/common
CUS_REL_BASE_COMP += pcore/custom/modem/common/atci/src
CUS_REL_BASE_COMP += pcore/custom/modem/common/ps
CUS_REL_BASE_COMP += pcore/custom/service/flc2
CUS_REL_BASE_COMP += pcore/custom/service/fs
CUS_REL_BASE_COMP += pcore/custom/service/nvram
CUS_REL_BASE_COMP += pcore/custom/service/tst
CUS_REL_BASE_COMP += pcore/custom/system/Template
CUS_REL_BASE_COMP += pcore/driver/audio/lib/MTKGCC
CUS_REL_BASE_COMP += pcore/driver/audio/lib/MTKGCC_ARM9
CUS_REL_BASE_COMP += pcore/driver/audio/lib/MTKGCC_CR4
CUS_REL_BASE_COMP += pcore/driver/audio/lib/MTKINC
CUS_REL_BASE_COMP += pcore/driver/audio/src
CUS_REL_BASE_COMP += pcore/driver/audio/src/v1
CUS_REL_BASE_COMP += pcore/driver/audio/src/v1/afes
CUS_REL_BASE_COMP += pcore/driver/audio/src/v1/inc
CUS_REL_BASE_COMP += pcore/driver/audio/src32_inc
CUS_REL_BASE_COMP += pcore/driver/btmt/rf_desense
CUS_REL_BASE_COMP += pcore/driver/cipher/include
CUS_REL_BASE_COMP += pcore/driver/connectivity/sdio_device_boot/inc
CUS_REL_BASE_COMP += pcore/driver/connectivity/usb_class/include
CUS_REL_BASE_COMP += pcore/driver/connectivity/usb_driver/inc
CUS_REL_BASE_COMP += pcore/driver/connectivity/usb_driver/src
CUS_REL_BASE_COMP += pcore/driver/devdrv
CUS_REL_BASE_COMP += pcore/driver/devdrv/eint/inc
CUS_REL_BASE_COMP += pcore/driver/drv/include
CUS_REL_BASE_COMP += pcore/driver/drv/src
CUS_REL_BASE_COMP += pcore/driver/drv_def
CUS_REL_BASE_COMP += pcore/driver/peripheral/inc
CUS_REL_BASE_COMP += pcore/driver/regbase/inc
CUS_REL_BASE_COMP += pcore/driver/sib_drv/mtad/inc
CUS_REL_BASE_COMP += pcore/driver/sleep_drv/public/inc
CUS_REL_BASE_COMP += pcore/driver/sphevs
CUS_REL_BASE_COMP += pcore/driver/storage/flash/fdm/inc
CUS_REL_BASE_COMP += pcore/driver/storage/flash/mtd/inc
CUS_REL_BASE_COMP += pcore/driver/storage/mc/inc
CUS_REL_BASE_COMP += pcore/driver/storage/mc/src
CUS_REL_BASE_COMP += pcore/driver/sys_drv/emi/inc
CUS_REL_BASE_COMP += pcore/driver/sys_drv/emi/src
CUS_REL_BASE_COMP += pcore/driver/sys_drv/init/inc
CUS_REL_BASE_COMP += pcore/driver/sys_drv/init/src
CUS_REL_BASE_COMP += pcore/driver/tty/inc
CUS_REL_BASE_COMP += pcore/driver/tty/src
CUS_REL_BASE_COMP += pcore/interface/driver/audio
CUS_REL_BASE_COMP += pcore/interface/driver/ccismcore
CUS_REL_BASE_COMP += pcore/interface/driver/cipher/include
CUS_REL_BASE_COMP += pcore/interface/driver/cldmacore
CUS_REL_BASE_COMP += pcore/interface/driver/cmux
CUS_REL_BASE_COMP += pcore/interface/driver/connectivity/sdio_device
CUS_REL_BASE_COMP += pcore/interface/driver/connectivity/usb_driver
CUS_REL_BASE_COMP += pcore/interface/driver/devdrv/busmon
CUS_REL_BASE_COMP += pcore/interface/driver/devdrv/cirq
CUS_REL_BASE_COMP += pcore/interface/driver/devdrv/coresight
CUS_REL_BASE_COMP += pcore/interface/driver/devdrv/cpu
CUS_REL_BASE_COMP += pcore/interface/driver/devdrv/eint
CUS_REL_BASE_COMP += pcore/interface/driver/devdrv/emi
CUS_REL_BASE_COMP += pcore/interface/driver/devdrv/gdma
CUS_REL_BASE_COMP += pcore/interface/driver/devdrv/l1gdma
CUS_REL_BASE_COMP += pcore/interface/driver/devdrv/mdipc
CUS_REL_BASE_COMP += pcore/interface/driver/devdrv/rstctl
CUS_REL_BASE_COMP += pcore/interface/driver/devdrv/thermal
CUS_REL_BASE_COMP += pcore/interface/driver/drv_sw_def
CUS_REL_BASE_COMP += pcore/interface/driver/drvtest
CUS_REL_BASE_COMP += pcore/interface/driver/hif
CUS_REL_BASE_COMP += pcore/interface/driver/hif/hif_usbdev
CUS_REL_BASE_COMP += pcore/interface/driver/hwdrv
CUS_REL_BASE_COMP += pcore/interface/driver/peripheral
CUS_REL_BASE_COMP += pcore/interface/driver/sdiocore
CUS_REL_BASE_COMP += pcore/interface/driver/sib_drv/scc
CUS_REL_BASE_COMP += pcore/interface/driver/sleep_drv
CUS_REL_BASE_COMP += pcore/interface/driver/storage
CUS_REL_BASE_COMP += pcore/interface/driver/storage/mc
CUS_REL_BASE_COMP += pcore/interface/driver/storage/sim
CUS_REL_BASE_COMP += pcore/interface/driver/sys_drv
CUS_REL_BASE_COMP += pcore/interface/middleware/general
CUS_REL_BASE_COMP += pcore/interface/middleware/gps
CUS_REL_BASE_COMP += pcore/interface/middleware/hif
CUS_REL_BASE_COMP += pcore/interface/middleware/media
CUS_REL_BASE_COMP += pcore/interface/modem/general
CUS_REL_BASE_COMP += pcore/interface/modem/lte
CUS_REL_BASE_COMP += pcore/interface/modem/mcd
CUS_REL_BASE_COMP += pcore/interface/modem/mml1
CUS_REL_BASE_COMP += pcore/interface/modem/upcm
CUS_REL_BASE_COMP += pcore/interface/service/asn1_common
CUS_REL_BASE_COMP += pcore/interface/service/event_info
CUS_REL_BASE_COMP += pcore/interface/service/flc2
CUS_REL_BASE_COMP += pcore/interface/service/fota
CUS_REL_BASE_COMP += pcore/interface/service/fs
CUS_REL_BASE_COMP += pcore/interface/service/fsm
CUS_REL_BASE_COMP += pcore/interface/service/hif
CUS_REL_BASE_COMP += pcore/interface/service/nvram
CUS_REL_BASE_COMP += pcore/interface/service/qmu_bm
CUS_REL_BASE_COMP += pcore/interface/service/sst
CUS_REL_BASE_COMP += pcore/interface/service/sys_svc
CUS_REL_BASE_COMP += pcore/middleware/hif/interface
CUS_REL_BASE_COMP += pcore/middleware/hif/ipcore/include
CUS_REL_BASE_COMP += pcore/middleware/hif/ipcore/src
CUS_REL_BASE_COMP += pcore/middleware/kpalv/include
CUS_REL_BASE_COMP += pcore/middleware/kpalv/src
CUS_REL_BASE_COMP += pcore/interface/middleware/kpalv
CUS_REL_BASE_COMP += pcore/middleware/hif/uartcore/src
CUS_REL_BASE_COMP += pcore/middleware/hif/usbcore/include
CUS_REL_BASE_COMP += pcore/middleware/hif/usbcore/src
CUS_REL_BASE_COMP += pcore/middleware/hif/usbidle/include
CUS_REL_BASE_COMP += pcore/middleware/hif/usbidle/src
CUS_REL_BASE_COMP += pcore/middleware/media/audio/include
CUS_REL_BASE_COMP += pcore/middleware/media/audio/src
CUS_REL_BASE_COMP += pcore/middleware/media/common/include
CUS_REL_BASE_COMP += pcore/middleware/media/common/src
CUS_REL_BASE_COMP += pcore/middleware/meta/ft/inc
CUS_REL_BASE_COMP += pcore/middleware/meta/ft/src
CUS_REL_BASE_COMP += pcore/middleware/meta/ftc
CUS_REL_BASE_COMP += pcore/modem/common/kdf/lib
CUS_REL_BASE_COMP += pcore/modem/dsp_bin/common
CUS_REL_BASE_COMP += pcore/modem/el1/el1d_ext
CUS_REL_BASE_COMP += pcore/modem/ephy/ephy_ext
CUS_REL_BASE_COMP += pcore/modem/gl1/l1d_ext
CUS_REL_BASE_COMP += pcore/modem/interface/asn/asn1lib/include
CUS_REL_BASE_COMP += pcore/modem/interface/asn/rr/include
CUS_REL_BASE_COMP += pcore/modem/interface/general
CUS_REL_BASE_COMP += pcore/modem/interface/ims
CUS_REL_BASE_COMP += pcore/modem/interface/l1/gsm/internal
CUS_REL_BASE_COMP += pcore/modem/interface/l1/mml1/internal
CUS_REL_BASE_COMP += pcore/modem/interface/l4
CUS_REL_BASE_COMP += pcore/modem/interface/l4misc
CUS_REL_BASE_COMP += pcore/modem/interface/lte
CUS_REL_BASE_COMP += pcore/modem/interface/mcd/include
CUS_REL_BASE_COMP += pcore/modem/interface/upcm
CUS_REL_BASE_COMP += pcore/modem/l4/atci/include
CUS_REL_BASE_COMP += pcore/modem/l4/csm/cc/include
CUS_REL_BASE_COMP += pcore/modem/l4/csm/ss/asn1/gen/include
CUS_REL_BASE_COMP += pcore/modem/l4/csm/ss/include
CUS_REL_BASE_COMP += pcore/modem/l4/dt/include
CUS_REL_BASE_COMP += pcore/modem/l4/include
CUS_REL_BASE_COMP += pcore/modem/l4/l4a/include
CUS_REL_BASE_COMP += pcore/modem/l4/l4c/include/common
CUS_REL_BASE_COMP += pcore/modem/l4/l4c/include/proc
CUS_REL_BASE_COMP += pcore/modem/l4/mbci/include
CUS_REL_BASE_COMP += pcore/modem/l4/phb/include
CUS_REL_BASE_COMP += pcore/modem/l4/phb/src
CUS_REL_BASE_COMP += pcore/modem/l4/rac/common/include
CUS_REL_BASE_COMP += pcore/modem/l4/rac/erac/include
CUS_REL_BASE_COMP += pcore/modem/l4/rac/ugrac/include
CUS_REL_BASE_COMP += pcore/modem/l4/smsal/include
CUS_REL_BASE_COMP += pcore/modem/l4/smslib/include
CUS_REL_BASE_COMP += pcore/modem/l4/smu/include
CUS_REL_BASE_COMP += pcore/modem/l4/tcm/etcm/include
CUS_REL_BASE_COMP += pcore/modem/l4/tcm/rat_tcm/inc
CUS_REL_BASE_COMP += pcore/modem/l4/uem/include
CUS_REL_BASE_COMP += pcore/modem/l4/uem/src
CUS_REL_BASE_COMP += pcore/modem/mml1/mml1_rf_ext
CUS_REL_BASE_COMP += pcore/modem/sim/include
CUS_REL_BASE_COMP += pcore/modem/ul1/ul1d_ext
CUS_REL_BASE_COMP += pcore/service/dhl/database
CUS_REL_BASE_COMP += pcore/service/fs/common/include
CUS_REL_BASE_COMP += pcore/service/fs/fat/include
CUS_REL_BASE_COMP += pcore/service/fs/ccci_fs/src
CUS_REL_BASE_COMP += pcore/service/hif/hmu/include
CUS_REL_BASE_COMP += pcore/service/hif/hmu/src
CUS_REL_BASE_COMP += pcore/service/hif/interface
CUS_REL_BASE_COMP += pcore/service/nvram/include
CUS_REL_BASE_COMP += pcore/service/nvram/src
CUS_REL_BASE_COMP += pcore/service/ssf/inc
CUS_REL_BASE_COMP += pcore/service/sst/include
CUS_REL_BASE_COMP += pcore/service/sys_svc/compression/inc
CUS_REL_BASE_COMP += pcore/service/sys_svc/compression/src
CUS_REL_BASE_COMP += pcore/service/sys_svc/dcmgr/inc
CUS_REL_BASE_COMP += pcore/service/sys_svc/dp/inc
CUS_REL_BASE_COMP += pcore/service/sys_svc/dsp_loader/src
CUS_REL_BASE_COMP += pcore/service/sys_svc/dspfm_lte/inc
CUS_REL_BASE_COMP += pcore/service/sys_svc/dspfm_lte/src
CUS_REL_BASE_COMP += pcore/service/sys_svc/excep_hdlr/inc
CUS_REL_BASE_COMP += pcore/service/sys_svc/excep_hdlr/src
CUS_REL_BASE_COMP += pcore/service/sys_svc/ftl/src
CUS_REL_BASE_COMP += pcore/service/sys_svc/gfh/public
CUS_REL_BASE_COMP += pcore/service/sys_svc/profile/inc
CUS_REL_BASE_COMP += pcore/service/sys_svc/region/inc
CUS_REL_BASE_COMP += pcore/service/sys_svc/region/src
CUS_REL_BASE_COMP += pcore/tools

# from l1core
CUS_REL_BASE_COMP += l1core/custom/system/Template
CUS_REL_BASE_COMP += l1core/driver/audio/src/v1
CUS_REL_BASE_COMP += l1core/driver/audio/src/v1/inc
CUS_REL_BASE_COMP += l1core/driver/devdrv/bus/inc
CUS_REL_BASE_COMP += l1core/driver/devdrv/bus/src
CUS_REL_BASE_COMP += l1core/driver/devdrv/busmon/src
CUS_REL_BASE_COMP += l1core/driver/devdrv/cirq/inc
CUS_REL_BASE_COMP += l1core/driver/devdrv/cirq/src
CUS_REL_BASE_COMP += l1core/driver/devdrv/cmif/inc
CUS_REL_BASE_COMP += l1core/driver/devdrv/cmif/src
CUS_REL_BASE_COMP += l1core/driver/devdrv/common/inc
CUS_REL_BASE_COMP += l1core/driver/devdrv/common/src
CUS_REL_BASE_COMP += l1core/driver/devdrv/cs_sram_ctrl/inc
CUS_REL_BASE_COMP += l1core/driver/devdrv/cs_sram_ctrl/src
CUS_REL_BASE_COMP += l1core/driver/devdrv/csif/inc
CUS_REL_BASE_COMP += l1core/driver/devdrv/csif/src
CUS_REL_BASE_COMP += l1core/driver/devdrv/drv_def
CUS_REL_BASE_COMP += l1core/driver/devdrv/elm/inc
CUS_REL_BASE_COMP += l1core/driver/devdrv/elm/src
CUS_REL_BASE_COMP += l1core/driver/devdrv/gdma/inc
CUS_REL_BASE_COMP += l1core/driver/devdrv/gdma/src
CUS_REL_BASE_COMP += l1core/driver/devdrv/idc/inc
CUS_REL_BASE_COMP += l1core/driver/devdrv/idc/src
CUS_REL_BASE_COMP += l1core/driver/devdrv/mdipc/inc
CUS_REL_BASE_COMP += l1core/driver/devdrv/mdipc/src
CUS_REL_BASE_COMP += l1core/driver/devdrv/pdn/inc
CUS_REL_BASE_COMP += l1core/driver/devdrv/pdn/src
CUS_REL_BASE_COMP += l1core/driver/devdrv/pll
CUS_REL_BASE_COMP += l1core/driver/devdrv/pll/inc
CUS_REL_BASE_COMP += l1core/driver/devdrv/pmic/inc
CUS_REL_BASE_COMP += l1core/driver/devdrv/pmic/src
CUS_REL_BASE_COMP += l1core/driver/devdrv/pmic_wrap/inc
CUS_REL_BASE_COMP += l1core/driver/devdrv/pmic_wrap/src
CUS_REL_BASE_COMP += l1core/driver/devdrv/rstctl/inc
CUS_REL_BASE_COMP += l1core/driver/devdrv/rstctl/src
CUS_REL_BASE_COMP += l1core/driver/devdrv/trace
CUS_REL_BASE_COMP += l1core/driver/devdrv/uart
CUS_REL_BASE_COMP += l1core/driver/devdrv/uart/inc
CUS_REL_BASE_COMP += l1core/driver/drv_def
CUS_REL_BASE_COMP += l1core/driver/peripheral
CUS_REL_BASE_COMP += l1core/driver/peripheral/inc
CUS_REL_BASE_COMP += l1core/driver/regbase/inc
CUS_REL_BASE_COMP += l1core/driver/sib_drv/pcc/inc
CUS_REL_BASE_COMP += l1core/driver/sleep_drv/public/inc
CUS_REL_BASE_COMP += l1core/driver/sys_drv/init/inc
CUS_REL_BASE_COMP += l1core/driver/sys_drv/init/src
CUS_REL_BASE_COMP += l1core/interface/driver/devdrv/busmon
CUS_REL_BASE_COMP += l1core/interface/driver/devdrv/cirq
CUS_REL_BASE_COMP += l1core/interface/driver/devdrv/cpu
CUS_REL_BASE_COMP += l1core/interface/driver/devdrv/cs_sram_ctrl
CUS_REL_BASE_COMP += l1core/interface/driver/devdrv/csif
CUS_REL_BASE_COMP += l1core/interface/driver/devdrv/gdma
CUS_REL_BASE_COMP += l1core/interface/driver/devdrv/mdipc
CUS_REL_BASE_COMP += l1core/interface/driver/devdrv/rstctl
CUS_REL_BASE_COMP += l1core/interface/driver/drvtest
CUS_REL_BASE_COMP += l1core/interface/driver/peripheral
CUS_REL_BASE_COMP += l1core/interface/driver/sib_drv/scc
CUS_REL_BASE_COMP += l1core/interface/driver/sleep_drv
CUS_REL_BASE_COMP += l1core/interface/modem/mml1
CUS_REL_BASE_COMP += l1core/interface/service/event_info
CUS_REL_BASE_COMP += l1core/interface/service/sst
CUS_REL_BASE_COMP += l1core/interface/service/sys_svc
CUS_REL_BASE_COMP += l1core/modem/gl1/l1d_ext
CUS_REL_BASE_COMP += l1core/modem/interface/l1/gsm/internal
CUS_REL_BASE_COMP += l1core/modem/interface/l1/mml1
CUS_REL_BASE_COMP += l1core/modem/ul1/ul1d_ext
CUS_REL_BASE_COMP += l1core/service/dhl/database
CUS_REL_BASE_COMP += l1core/service/dhl/database/msglog_db
CUS_REL_BASE_COMP += l1core/service/sst/include
CUS_REL_BASE_COMP += l1core/service/sys_svc/excep_hdlr/inc
CUS_REL_BASE_COMP += l1core/service/sys_svc/excep_hdlr/src
CUS_REL_BASE_COMP += l1core/service/sys_svc/region/inc
CUS_REL_BASE_COMP += l1core/service/sys_svc/region/src
CUS_REL_BASE_COMP += l1core/tools

#CUS_REL_BASE_COMP += pcore/custom/modem/tl1_rf/MT6755_EVB1S1_MT6176_UMTS_TDD
#CUS_REL_BASE_COMP += pcore/custom/modem/ul1_rf/MT6755_UMTS_FDD_MT6176
#CUS_REL_BASE_COMP += pcore/custom/modem/mml1_rf/MT6755_MMRF
#CUS_REL_BASE_COMP += pcore/custom/modem/l1_rf/MT6755_2G_MT6176
#CUS_REL_BASE_COMP += pcore/custom/modem/el1_rf/MT6755_LTE_MT6176

# common
CUS_REL_FILES_LIST :=
CUS_REL_FILES_LIST += m
CUS_REL_FILES_LIST += make.pl
CUS_REL_FILES_LIST += make.sh
CUS_REL_FILES_LIST += make/common/Comp.mak
CUS_REL_FILES_LIST += make/common/compiler.mak
CUS_REL_FILES_LIST += make/common/compiler_cfg.mak
CUS_REL_FILES_LIST += make/common/Option.mak
CUS_REL_FILES_LIST += make/common/Extra_dep.mak
CUS_REL_FILES_LIST += make/common/hif_main.mak
CUS_REL_FILES_LIST += make/common/LTE_DEF.mak
CUS_REL_FILES_LIST += make/common/OLD_FEATURES.mak
CUS_REL_FILES_LIST += make/common/checkvalue.mak
CUS_REL_FILES_LIST += make/common/USER_SPECIFIC.mak
CUS_REL_FILES_LIST += make/common/cmd_cfg.mak
CUS_REL_FILES_LIST += make/common/module_check.mak
CUS_REL_FILES_LIST += make/common/rel/REL_COMP_COMMON.mak
CUS_REL_FILES_LIST += make/common/rel/REL_COMP_CR_COMMON.mak
CUS_REL_FILES_LIST += make/common/rel/REL_COMP_CR_BASIC.mak
CUS_REL_FILES_LIST += make/common/rel/REL_CR_BASIC.mak
CUS_REL_FILES_LIST += make/common/rel/REL_CR_COMMON.mak
CUS_REL_FILES_LIST += make/common/smart_phone_option.mak
# pcore
CUS_REL_FILES_LIST += make/pcore/build.mak
CUS_REL_FILES_LIST += make/pcore/buildConfig.mak
CUS_REL_FILES_LIST += make/pcore/Codegen.mak
CUS_REL_FILES_LIST += make/pcore/Option.mak
CUS_REL_FILES_LIST += make/pcore/standalone_action.mak
CUS_REL_FILES_LIST += make/pcore/module/driver/driver_config.mak
CUS_REL_FILES_LIST += make/pcore/module/middleware/middleware_config.mak
CUS_REL_FILES_LIST += make/pcore/module/modem/modem_config.mak
CUS_REL_FILES_LIST += make/pcore/module/service/service_config.mak
CUS_REL_FILES_LIST += make/pcore/xgenInc.mak
# l1core
CUS_REL_FILES_LIST += l1core/make.pl
CUS_REL_FILES_LIST += make/l1core/build.mak
CUS_REL_FILES_LIST += make/l1core/buildConfig.mak
CUS_REL_FILES_LIST += make/l1core/Codegen.mak
CUS_REL_FILES_LIST += make/l1core/Option.mak
CUS_REL_FILES_LIST += make/l1core/standalone_action.mak
CUS_REL_FILES_LIST += make/l1core/module/driver/driver_config.mak
CUS_REL_FILES_LIST += make/l1core/module/middleware/middleware_config.mak
CUS_REL_FILES_LIST += make/l1core/module/modem/modem_config.mak
CUS_REL_FILES_LIST += make/l1core/module/service/service_config.mak
CUS_REL_FILES_LIST += make/l1core/xgen/xgen.mak

# not sure
CUS_REL_FILES_LIST += make/pcore/Custom.bld
CUS_REL_FILES_LIST += make/l1core/Custom.bld



# special case
CUS_REL_CUSTOM_FEATURE := BOARD_VER_FLAVOR RF_MODULE UMTS_RF_MODULE UMTS_TDD128_RF_MODULE LTE_RF_MODULE MM_RF_MODULE PLATFORM
CUS_REL_CUSTOM_BOARD_VER_FLAVOR := pcore/custom/driver/audio
CUS_REL_CUSTOM_BOARD_VER_FLAVOR += pcore/custom/driver/drv/gps
CUS_REL_CUSTOM_BOARD_VER_FLAVOR += pcore/custom/driver/drv/misc_drv
CUS_REL_CUSTOM_BOARD_VER_FLAVOR += pcore/custom/driver/drv_gen
CUS_REL_CUSTOM_BOARD_VER_FLAVOR += pcore/custom/middleware/meta
CUS_REL_CUSTOM_BOARD_VER_FLAVOR += pcore/custom/modem/ps
CUS_REL_CUSTOM_BOARD_VER_FLAVOR += pcore/custom/system
CUS_REL_CUSTOM_BOARD_VER_FLAVOR += l1core/custom/system
CUS_REL_CUSTOM_RF_MODULE        := pcore/custom/modem/l1_rf
CUS_REL_CUSTOM_UMTS_RF_MODULE   := pcore/custom/modem/ul1_rf
CUS_REL_CUSTOM_UMTS_TDD128_RF_MODULE := pcore/custom/modem/tl1_rf
CUS_REL_CUSTOM_LTE_RF_MODULE := pcore/custom/modem/el1_rf
CUS_REL_CUSTOM_MM_RF_MODULE := pcore/custom/modem/mml1_rf
CUS_REL_CUSTOM_PLATFORM := pcore/custom/driver/audio/_Default_BB
CUS_REL_CUSTOM_PLATFORM += pcore/custom/driver/drv/misc_drv/_Default_BB

NON_REL_DIRS_LIST :=
NON_REL_DIRS_LIST += common/tools/GCC
NON_REL_DIRS_LIST += common/tools/MinGW
NON_REL_DIRS_LIST += common/tools/MSYS
NON_REL_DIRS_LIST += common/tools/DwarfUtility
NON_REL_DIRS_LIST += common/interface/modem/secured
NON_REL_DIRS_LIST += pcore/tools/MinGW
NON_REL_DIRS_LIST += pcore/tools/MSYS
NON_REL_DIRS_LIST += pcore/tools/NVRAMStatistic/lid
NON_REL_DIRS_LIST += pcore/tools/DwarfUtility
NON_REL_DIRS_LIST += pcore/interface/modem/secured
NON_REL_DIRS_LIST += l1core/tools/MinGW
NON_REL_DIRS_LIST += l1core/tools/MSYS
NON_REL_DIRS_LIST += l1core/tools/DwarfUtility
NON_REL_DIRS_LIST += l1core/interface/modem/secured

NON_REL_FILES_LIST :=
NON_REL_FILES_LIST += pcore/tools/MemoryDeviceList/MemoryDeviceList_*Internal.xls
NON_REL_FILES_LIST += l1core/tools/MemoryDeviceList/MemoryDeviceList_*Internal.xls

