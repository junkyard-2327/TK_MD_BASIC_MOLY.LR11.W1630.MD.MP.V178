#ifndef __REG_BASE_MT6755_H__
#define __REG_BASE_MT6755_H__

/* From Designer's project.h*/

//Generate 2 dummy reg addr for SIM driver and RGU driver case switch coding style
#define COSIM_DUMMY_BASE        (0x80FE0000)
#define COSIM_DUMMY_BASE_2      (0x80FE0400)

#if !defined(_SIMULATION)
#define REG_BASE(reg_base)      (reg_base)
#define REG_BASE_2(reg_base)    (reg_base)
#else
#define REG_BASE(reg_base)      (COSIM_DUMMY_BASE)
#define REG_BASE_2(reg_base)    (COSIM_DUMMY_BASE_2)
#endif


/*================== Begin of designer's project.h =========================*/

//MD-side Strongly-ordered registers
#define BASE_MADDR_MDCFGCTL             REG_BASE(0xF0000000)
#define BASE_MADDR_MDUART0              REG_BASE(0xF0010000)
#define BASE_MADDR_MDGDMA               REG_BASE(0xF0020000)
#define BASE_MADDR_MDGPTM               REG_BASE(0xF0030000)
#define BASE_MADDR_USIM1                REG_BASE(0xF0040000)
#define BASE_MADDR_USIM2                REG_BASE_2(0xF0050000)
#define BASE_MADDR_MDPERIMISC           REG_BASE(0xF0060000)
#define BASE_MADDR_MDCIRQ               REG_BASE(0xF0070000)
#define BASE_MADDR_DBGSYS_2             REG_BASE(0xF0080000)
#define BASE_MADDR_DBGSYS_1             REG_BASE(0xF00A0000)
#define BASE_MADDR_MDCTI                REG_BASE(0xF00A8000)
#define BASE_MADDR_MDDBGMON             REG_BASE(0xF00B0000)
#define BASE_MADDR_MDPERI_CLKCTL        REG_BASE(0xF00C0000)
#define BASE_MADDR_MDTOPSM              REG_BASE(0xF00D0000)
#define BASE_MADDR_MDOSTIMER            REG_BASE(0xF00E0000)
#define BASE_MADDR_MDRGU                REG_BASE_2(0xF00F0000)
#define BASE_MADDR_I2C                  REG_BASE(0xF0100000)
#define BASE_MADDR_MDEINT               REG_BASE(0xF0110000)
#define BASE_MADDR_MDSYS_CLKCTL         REG_BASE(0xF0120000)
#define BASE_MADDR_MDTOP_GLBCON         REG_BASE(0xF0130000)
#define BASE_MADDR_MDTOP_PLLMIXED       REG_BASE(0xF0140000)
#define BASE_MADDR_MDTOP_CLKSW          REG_BASE(0xF0150000)
#define BASE_MADDR_ARM7_OSTIMER         REG_BASE(0xF0160000)
#define BASE_MADDR_MD_LITE_GPTIMER      REG_BASE(0xF0170000)
#define BASE_MADDR_PS2ARM7_PCCIF        REG_BASE(0xF0180000)
#define BASE_MADDR_ARM72PS_PCCIF        REG_BASE(0xF0190000)
#define BASE_MADDR_MDPERI_MBIST         REG_BASE(0xF01A0000)
#define BASE_MADDR_SDF_TOP              REG_BASE(0xF01B0000)
#define BASE_MADDR_PSMCU_MISC_REG       REG_BASE(0xF0200000)
#define BASE_MADDR_PSMCU_BUSMON         REG_BASE(0xF0210000)
#define BASE_MADDR_PSMCU_ETM_PCMON      REG_BASE(0xF0220000)
#define BASE_MADDR_MDCAIF_PSEL          REG_BASE(0xF0230000)
#define BASE_MADDR_PSMCUSYS_MBISTG      REG_BASE(0xF0240000)
#define BASE_MADDR_ELM_TOPRESERVED      REG_BASE(0xF0250000)
#define BASE_MADDR_MDABM                REG_BASE(0xF0260000)
#define BASE_MADDR_IPSEC                REG_BASE(0xF0310000)
#define BASE_MADDR_MDINFRABUSMON        REG_BASE(0xF0320000)
#define BASE_MADDR_MDUART1              REG_BASE(0xF0330000)
#define BASE_MADDR_MDUART2              REG_BASE(0xF0340000)
#define BASE_MADDR_MDINFRASYS_MBIST_CFG REG_BASE(0xF0350000)
#define BASE_MADDR_MDSYS_MBIST_CFG      REG_BASE(0xF0360000)
#define BASE_MADDR_CA7MDM               REG_BASE(0xF0370000)
#define BASE_MADDR_L1MDM                REG_BASE(0xF0380000)
#define BASE_MADDR_MDM                  REG_BASE(0xF0390000)
#define BASE_MADDR_MDSMICFG             REG_BASE(0xF03A0000)
#define BASE_MADDR_MDINFRAMISC          REG_BASE(0xF03B0000)
#define BASE_MADDR_MDBUSRECORDER        REG_BASE(0xF03C0000)
#define BASE_MADDR_PPC                  REG_BASE(0xF03D0000)
#define BASE_MADDR_LTEL2SYS             REG_BASE(0xF0800000)
#define BASE_MADDR_L2ULSBDMA            REG_BASE(0xF0800000)
#define BASE_MADDR_L2ULHBDMA            REG_BASE(0xF0810000)
#define BASE_MADDR_L2DLSBDMA            REG_BASE(0xF0820000)
#define BASE_MADDR_L2DLHBDMA            REG_BASE(0xF0830000)
#define BASE_MADDR_L2MBIST              REG_BASE(0xF0840000)
#define BASE_MADDR_L2PSEUPHY            REG_BASE(0xF0850000)
#define BASE_MADDR_L2HWLOG              REG_BASE(0xF0854000)
#define BASE_MADDR_L2ULLOGDMA           REG_BASE(0xF0858000)
#define BASE_MADDR_L2DLLOGDMA           REG_BASE(0xF085C000)
#define BASE_MADDR_L2SOINDMA            REG_BASE(0xF0860000)
#define BASE_MADDR_L2SOOUTDMA           REG_BASE(0xF0870000)
#define BASE_MADDR_L2ULLMAC             REG_BASE(0xF0880000)
#define BASE_MADDR_L2DLLMAC             REG_BASE(0xF0890000)
#define BASE_MADDR_L2CALMAC             REG_BASE(0xF0898000)
#define BASE_MADDR_L2ULFIFOMNG          REG_BASE(0xF08A0000)
#define BASE_MADDR_L2DLFIFOMNG          REG_BASE(0xF08A4000)
#define BASE_MADDR_L2SOFIFOMNG          REG_BASE(0xF08A8000)
#define BASE_MADDR_L2SEC                REG_BASE(0xF08B0000)
#define BASE_MADDR_L2ULSECCTL           REG_BASE(0xF08B4000)
#define BASE_MADDR_L2DLSECCTL           REG_BASE(0xF08B8000)
#define BASE_MADDR_L2SOSECCTL           REG_BASE(0xF08BC000)
#define BASE_MADDR_L2MISC               REG_BASE(0xF08C0000)
#define BASE_MADDR_L2DBGMON             REG_BASE(0xF08D0000)
#define BASE_MADDR_L2ULBUFMNG           REG_BASE(0xF08E0000)
#define BASE_MADDR_L2DLBUFMNG           REG_BASE(0xF08F0000)
#define BASE_MADDR_HSPAL2               REG_BASE(0xF0900000)
#define BASE_MADDR_HSPAL2_MBIST         REG_BASE(0xF0900000)
#define BASE_MADDR_HSPAL2_CONFG         REG_BASE(0xF0910000)
#define BASE_MADDR_HSPAL2_UPA           REG_BASE(0xF0920000)
#define BASE_MADDR_HSPAL2_DPA_MAC       REG_BASE(0xF0930000)
#define BASE_MADDR_HSPAL2_DPA_RLC       REG_BASE(0xF0940000)
#define BASE_MADDR_PSPERI               REG_BASE(0xF0A00000)
#define BASE_MADDR_PS_PERI_CONFG        REG_BASE(0xF0A00000)
#define BASE_MADDR_FCS                  REG_BASE(0xF0A10000)
#define BASE_MADDR_GCU                  REG_BASE(0xF0A20000)
#define BASE_MADDR_BYC_ACC              REG_BASE(0xF0A30000)
#define BASE_MADDR_UEA_UIA_1            REG_BASE(0xF0A40000)
#define BASE_MADDR_UEA_UIA_0            REG_BASE(0xF0A50000)
#define BASE_MADDR_PCORE_FMA            REG_BASE(0xF1000000)
#define BASE_MADDR_HSPAL2_UPA_SRAM      REG_BASE(0xF8400000)
#define BASE_MADDR_MD32_BRP             REG_BASE(0xF9000000)
#define BASE_MADDR_MD32_DFE             REG_BASE(0xF7800000)
#define BASE_MADDR_MD32_RAKE            REG_BASE(0xF9800000)
#define BASE_MADDR_PS_CTI               REG_BASE(0xF00A8000)
#define BASE_MADDR_L1_CTI               REG_BASE(0xF009B000)
#define BASE_MADDR_MD_CTI               REG_BASE(0xF009C000)

//AP-side Strongly-Order registers
#define BASE_MADDR_TOP_LEVEL_CLOCK_GENERATOR REG_BASE(0xC0000000) 
#define BASE_MADDR_INFRASYS_CONFIG_REGS      REG_BASE(0xC0001000) 
#define BASE_MADDR_GPIO                      REG_BASE(0xC0005000) 
#define BASE_MADDR_TOP_LEVEL_SLP_MANAGER     REG_BASE(0xC0006000) 
#define BASE_MADDR_TOP_RGU                   REG_BASE(0xC0007000)
#define BASE_MADDR_AO_SEJ                    REG_BASE(0xC000A000)
#define BASE_MADDR_PMIC_WRAP                 REG_BASE(0xC000D000) 
#define BASE_MADDR_APCLDMAIN_AO              REG_BASE(0xC0014800) 
#define BASE_MADDR_APCLDMAOUT_AO             REG_BASE(0xC0014A00) 
#define BASE_MADDR_APCLDMAMISC_AO            REG_BASE(0xC0014C00) 
#define BASE_MADDR_MDCLDMAIN_AO              REG_BASE(0xC0015800) 
#define BASE_MADDR_MDCLDMAOUT_AO             REG_BASE(0xC0015A00) 
#define BASE_MADDR_MDCLDMAMISC_AO            REG_BASE(0xC0015C00)
#define BASE_MADDR_AES_TOP0                  REG_BASE(0xC0016000)
#define BASE_MADDR_EMI_BUS_INTERFACE         REG_BASE(0xC0203000)
#define BASE_MADDR_EFUSE                     REG_BASE(0xC0206000)
#define BASE_MADDR_CCIF0_AP                  REG_BASE(0xC0209000) 
#define BASE_MADDR_CCIF0_MD                  REG_BASE(0xC020A000) 
#define BASE_MADDR_PS_C2K_CCIRQ              REG_BASE(0xC0211000)
#define BASE_MADDR_L1_C2K_CCIRQ              REG_BASE(0xC0211400)
#define BASE_MADDR_C2K_PS_CCIRQ              REG_BASE(0xC0213000)
#define BASE_MADDR_C2K_L1_CCIRQ              REG_BASE(0xC0213400)
#define BASE_MADDR_APCLDMAIN                 REG_BASE(0xC021B000) 
#define BASE_MADDR_APCLDMAOUT                REG_BASE(0xC021B200) 
#define BASE_MADDR_APCLDMAMISC               REG_BASE(0xC021B400) 
#define BASE_MADDR_MDCLDMAIN                 REG_BASE(0xC021C000) 
#define BASE_MADDR_MDCLDMAOUT                REG_BASE(0xC021C200) 
#define BASE_MADDR_MDCLDMAMISC               REG_BASE(0xC021C400) 
#define BASE_MADDR_APINFRA_MD_SMI			 REG_BASE(0xC021D000)

#define BASE_MADDR_EMI_MPU_REG               REG_BASE(0xC0226000)
#define BASE_MADDR_AUDIO                     REG_BASE(0xC1220000) 
#define BASE_MADDR_U3MAC0                    REG_BASE(0xC1270000) 
#define BASE_MADDR_U3MAC1                    REG_BASE(0xC1280000) 
#define BASE_MADDR_U3PHY0                    REG_BASE(0xC1290000)
#define BASE_MADDR_WCN_AHB_SLAVE             REG_BASE(0xC8000000) 


#define L1_BASE_MADDR_L12PS_CCIRQ       REG_BASE(0xF6030000)
#define L1_BASE_MADDR_PS2L1_CCIRQ       REG_BASE(0xF6040000)

#define L1_BASE_MADDR_TDMA_SLP          REG_BASE(0xF60B0000)
#define L1_BASE_MADDR_MDL1_CONF         REG_BASE(0xF60F0000)
#define L1_BASE_MADDR_L1MCU_SMI_CONFIG  REG_BASE(0xF68A0000)
#define L1_BASE_MADDR_MDL1_BUS_CONFG    REG_BASE(0xF68B0000)
#define L1_BASE_MADDR_CM_IDMA           REG_BASE(0xF7000000)
#define L1_BASE_MADDR_PM_IDMA           REG_BASE(0xF7100000)
#define L1_BASE_MADDR_DM_IDMA           REG_BASE(0xF7200000)
#define L1_BASE_MADDR_SHORTMODE_IDMA    REG_BASE(0xF7300000)
#define L1_BASE_MADDR_AHB2DSPIO         REG_BASE(0xF7400000)
#define L1_BASE_MADDR_MD2G_CONFG        REG_BASE(0xF7700000)
#define L1_BASE_MADDR_MD2G_MBIST_CONFG  REG_BASE(0xF7710000)
#define L1_BASE_MADDR_TDMA_BASE         REG_BASE(0xF7720000)
#define L1_BASE_MADDR_APC               REG_BASE(0xF7730000)
#define L1_BASE_MADDR_CSD_ACC           REG_BASE(0xF7770000)
#define L1_BASE_MADDR_MD2G_BSI_BASE     REG_BASE(0xF7780000)
#define L1_BASE_MADDR_MD2G_BPI_BASE     REG_BASE(0xF7790000)
#define L1_BASE_MADDR_SHARE_D1          REG_BASE(0xF77A0000)
#define L1_BASE_MADDR_IRDMA             REG_BASE(0xF77B0000)
#define L1_BASE_MADDR_PATCH             REG_BASE(0xF77C0000)
#define L1_BASE_MADDR_AFE               REG_BASE(0xF77D0000)
#define L1_BASE_MADDR_BFE               REG_BASE(0xF77E0000)
#define L1_BASE_MADDR_MD2G_MEM_CONFG    REG_BASE(0xF77F0000)
#define L1_BASE_MADDR_L1MCU_CONF        REG_BASE(0xF6800000)
#define L1_BASE_MADDR_GDMA              REG_BASE(0xF6820000)

//This is a temp solution for FMA mirror register fail problem
#define L1_BASE_MADDR_TOPSM             REG_BASE(0xF6070000)


//MD Register base STRONGLY-ORDERED type support and rename for User's request
#define BASE_MADDR_TOP_DCM      (BASE_MADDR_MD_GLBCON_TOP_DCM)
#define MDMCU_BUSMON_BASE       (BASE_MADDR_PSMCU_BUSMON)
#define BASE_MADDR_MDPCMON      (BASE_MADDR_PSMCU_ETM_PCMON)
#define BASE_MADDR_MDASM        (BASE_MADDR_MDABM)
#define MD_INFRA_BUSMON_BASE    (BASE_MADDR_MDINFRABUSMON)
#define CONFIG_base             (BASE_MADDR_MDCFGCTL)
#define SIM0_base               (BASE_MADDR_USIM1)
#define SIM1_base               (BASE_MADDR_USIM2)
#define UART1_base              (BASE_MADDR_MDUART0)
#define UART2_base              (BASE_MADDR_MDUART1)
#define UART3_base              (BASE_MADDR_MDUART2)
#define HSPASYS_CONFIG3_base    (BASE_MADDR_HSPAL2_CONFG)
#define UPA_base                (BASE_MADDR_HSPAL2_UPA)
#define HSUPA_base              (BASE_MADDR_HSPAL2_UPA)
#define UPA_SRAM_base           (BASE_MADDR_HSPAL2_UPA_SRAM)
#define DPA_MAC_base            (BASE_MADDR_HSPAL2_DPA_MAC)
#define DPA_RLC_base            (BASE_MADDR_HSPAL2_DPA_RLC)
#define IDMA_base               (L1_BASE_MADDR_CM_IDMA)
#define DPRAM_CPU_base          (L1_BASE_MADDR_DM_IDMA)
#define FCS2G_base              (BASE_MADDR_FCS)
#define F9_base                 (BASE_MADDR_UEA_UIA_1)
#define F8_DL_base              (BASE_MADDR_UEA_UIA_1)
#define F8_UL_base              (BASE_MADDR_UEA_UIA_0)
#define SHAREG2_base            (L1_BASE_MADDR_SHARE_D1)
#define PATCH_base              (L1_BASE_MADDR_PATCH)
#define HSPAL2SYS_CONFIG_base   (BASE_MADDR_HSPAL2_CONFG)
#define MDCONFIG_base           (BASE_MADDR_PS_PERI_CONFG)
#define DPA_BC_base             (BASE_MADDR_BYC_ACC)
#define GCU2G_base              (BASE_MADDR_GCU)
#define EFUSE_base              (BASE_MADDR_EFUSE)
#define PS_CONFIG_base          (CONFIG_base)




//AP Register base STRONGLY-ORDERED type support and rename for User's request
//#define BASE_ADDR_APMCU_GIC     (BASE_MADDR_APMCU_GIC)
//#define BASE_ADDR_APMCUAPB      (BASE_MADDR_APMCUAPB)



//MD Register base DEVICE type support and rename for User's request
#define BASE_ADDR_MDCIRQ        ((BASE_MADDR_MDCIRQ             & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_TOP_DCM       ((BASE_MADDR_MD_GLBCON_TOP_DCM  & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_MDPCMON       ((BASE_MADDR_PSMCU_ETM_PCMON    & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_MDASM         ((BASE_MADDR_MDABM              & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_MDTOPSM       ((BASE_MADDR_MDTOPSM            & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_MDGDMA        ((BASE_MADDR_MDGDMA             & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_MDGPTM        ((BASE_MADDR_MDGPTM             & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_ARM7_OSTIMER  ((BASE_MADDR_ARM7_OSTIMER       & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_L1MCU_CONF    ((L1_BASE_MADDR_L1MCU_CONF      & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_L1MDGDMA      ((L1_BASE_MADDR_GDMA            & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)

#define BASE_ADDR_LTEL2SYS      ((BASE_MADDR_LTEL2SYS           & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_L2ULSBDMA     ((BASE_MADDR_L2ULSBDMA          & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_L2ULHBDMA     ((BASE_MADDR_L2ULHBDMA          & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_L2DLSBDMA     ((BASE_MADDR_L2DLSBDMA          & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_L2DLHBDMA     ((BASE_MADDR_L2DLHBDMA          & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_L2MBIST       ((BASE_MADDR_L2MBIST            & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_L2PSEUPHY     ((BASE_MADDR_L2PSEUPHY          & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_L2HWLOG       ((BASE_MADDR_L2HWLOG            & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_L2SOINDMA     ((BASE_MADDR_L2SOINDMA          & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_L2SOOUTDMA    ((BASE_MADDR_L2SOOUTDMA         & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_L2ULLMAC      ((BASE_MADDR_L2ULLMAC           & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_L2DLLMAC      ((BASE_MADDR_L2DLLMAC           & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_L2CALMAC      ((BASE_MADDR_L2CALMAC           & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_L2ULFIFOMNG   ((BASE_MADDR_L2ULFIFOMNG        & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_L2DLFIFOMNG   ((BASE_MADDR_L2DLFIFOMNG        & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_L2SOFIFOMNG   ((BASE_MADDR_L2SOFIFOMNG        & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_L2SEC         ((BASE_MADDR_L2SEC              & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_L2ULSECCTL    ((BASE_MADDR_L2ULSECCTL         & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_L2DLSECCTL    ((BASE_MADDR_L2DLSECCTL         & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_L2SOSECCTL    ((BASE_MADDR_L2SOSECCTL         & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_L2MISC        ((BASE_MADDR_L2MISC             & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_L2DBGMON      ((BASE_MADDR_L2DBGMON           & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_L2ULBUFMNG    ((BASE_MADDR_L2ULBUFMNG         & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_L2DLBUFMNG    ((BASE_MADDR_L2DLBUFMNG         & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_L2ULLOGDMA    ((BASE_MADDR_L2ULLOGDMA         & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
#define BASE_ADDR_L2DLLOGDMA    ((BASE_MADDR_L2DLLOGDMA         & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)

//AP Register base DEVICE type support and rename for User's request
//#define BASE_ADDR_SPI           ((BASE_MADDR_SPI                & ~MDSYS_PERI_ACC_TYPE_MASK) | APSYS_PERI_DEVICE_TYPE)
//#define BASE_ADDR_HIF           ((BASE_MADDR_HIF                & ~MDSYS_PERI_ACC_TYPE_MASK) | APSYS_PERI_DEVICE_TYPE)
//#define BASE_ADDR_APUART1       ((BASE_MADDR_APUART1            & ~MDSYS_PERI_ACC_TYPE_MASK) | APSYS_PERI_DEVICE_TYPE)
//#define BASE_ADDR_APUART2       ((BASE_MADDR_APUART2            & ~MDSYS_PERI_ACC_TYPE_MASK) | APSYS_PERI_DEVICE_TYPE)
//#define BASE_ADDR_EMI           ((BASE_MADDR_EMI                & ~MDSYS_PERI_ACC_TYPE_MASK) | APSYS_PERI_DEVICE_TYPE)
//#define BASE_ADDR_DRAMC         ((BASE_MADDR_DRAMC              & ~MDSYS_PERI_ACC_TYPE_MASK) | APSYS_PERI_DEVICE_TYPE)
//#define BASE_ADDR_DDRPHY        ((BASE_MADDR_DDRPHY             & ~MDSYS_PERI_ACC_TYPE_MASK) | APSYS_PERI_DEVICE_TYPE)
//#define BASE_ADDR_MEMSYSMISC    ((BASE_MADDR_MEMSYSMISC         & ~MDSYS_PERI_ACC_TYPE_MASK) | APSYS_PERI_DEVICE_TYPE)
//#define BASE_ADDR_MEMSYSMISC_AO ((BASE_MADDR_MEMSYSMISC_AO      & ~MDSYS_PERI_ACC_TYPE_MASK) | APSYS_PERI_DEVICE_TYPE)
//#define BASE_ADDR_NLI_ARB       ((BASE_MADDR_NLI_sARB            & ~MDSYS_PERI_ACC_TYPE_MASK) | APSYS_PERI_DEVICE_TYPE)
//#define BASE_ADDR_APUART0       ((BASE_MADDR_APUART0            & ~MDSYS_PERI_ACC_TYPE_MASK) | APSYS_PERI_DEVICE_TYPE)
//#define BASE_ADDR_APGPTM        ((BASE_MADDR_APGPTM             & ~MDSYS_PERI_ACC_TYPE_MASK) | APSYS_PERI_DEVICE_TYPE)
//#define BASE_ADDR_SDIO        	((BASE_MADDR_SDIO               & ~MDSYS_PERI_ACC_TYPE_MASK) | APSYS_PERI_DEVICE_TYPE)


#define MDSYS_PERI_ACC_TYPE_MASK    (0xF0000000)
#define MDSYS_PERI_NORMAL_TYPE      (0x60000000)
#define MDSYS_PERI_DEVICE_TYPE      (0x80000000)
#define MDSYS_PERI_SO_TYPE          (0xF0000000)
#define APSYS_PERI_DEVICE_TYPE      (0x90000000)


//PM
#define L1_BASE_MADDR_ICC_DSPPM                 REG_BASE(0xFE800000)
#define L1_BASE_MADDR_IMC_DSPPM                 REG_BASE(0xFD800000)
#define L1_BASE_MADDR_MPC_DSPPM                 REG_BASE(0xFD000000)
//ICM
#define L1_BASE_MADDR_ICC_DSPICM                REG_BASE(0xFEC00000)
#define L1_BASE_MADDR_IMC_DSPICM                REG_BASE(0xFDC00000)
#define L1_BASE_MADDR_MPC_DSPICM                REG_BASE(0xFD400000)
//CRF
#define L1_BASE_MADDR_ICC_C2CRF                 REG_BASE(0xFEE00000)
#define L1_BASE_MADDR_IMC_C2CRF                 REG_BASE(0xFDE00000)
#define L1_BASE_MADDR_MPC_C2CRF                 REG_BASE(0xFD600000)
//CSIF
#define L1_BASE_MADDR_ICC_L1CSIF                REG_BASE(0xFEE80000)
#define L1_BASE_MADDR_IMC_L1CSIF                REG_BASE(0xFDE80000)
#define L1_BASE_MADDR_MPC_L1CSIF                REG_BASE(0xFD680000)
//DSPBT
#define L1_BASE_MADDR_ICC_DSPBTDMA              REG_BASE(0xFEF20000)
#define L1_BASE_MADDR_IMC_DSPBTDMA              REG_BASE(0xFDF20000)
#define L1_BASE_MADDR_MPC_DSPBTDMA              REG_BASE(0xFD720000)
//SRAM CTRL
#define L1_BASE_MADDR_IMCSYS_SRAMCTL_CFG        REG_BASE(0xFDF14000)
#define L1_BASE_MADDR_ICCSYS_SRAMCTL_CFG        REG_BASE(0xFEF14000)
#define L1_BASE_MADDR_MPCSYS_SRAMCTL_CFG        REG_BASE(0xFD714000)
#define L1_BASE_MADDR_MMUSYS_SRAMCTL_CFG        REG_BASE(0xFE714000)
#define L1_BASE_MADDR_CSSYS_SRAMCTL_CFG         REG_BASE(0xFCF14000)
// PCMON
#define L1_BASE_MADDR_MDPCMON                   REG_BASE(0xF6880000)

//MPCSYS
#define L1_BASE_MADDR_MPC_MPC2IMC_SSIF          REG_BASE(0xFD418000)
#define L1_BASE_MADDR_MPC_L1CSIF_MEM            REG_BASE(0xFD680000)
#define L1_BASE_MADDR_MPC_L1CSIF_REG            REG_BASE(0xFD6C0000)

//IMCSYS
#define L1_BASE_MADDR_IMC_IMC2ICC_SSIF          REG_BASE(0xFDC1E000)
#define L1_BASE_MADDR_IMC_IMC2MPC_SSIF          REG_BASE(0xFDC26000)
#define L1_BASE_MADDR_IMC_IMC2BRP_MSIF          REG_BASE(0xFDC2E000)
#define L1_BASE_MADDR_IMC_L1CSIF_MEM            REG_BASE(0xFDE80000)
#define L1_BASE_MADDR_IMC_L1CSIF_REG            REG_BASE(0xFDEC0000)

//ICCSYS
#define L1_BASE_MADDR_ICC_ICC2IMC_SSIF          REG_BASE(0xFEC1E000)
#define L1_BASE_MADDR_ICC_L1CSIF_MEM            REG_BASE(0xFEE80000)
#define L1_BASE_MADDR_ICC_L1CSIF_REG            REG_BASE(0xFEEC0000)

#endif /* end of __REG_BASE_MT6755_H__ */
