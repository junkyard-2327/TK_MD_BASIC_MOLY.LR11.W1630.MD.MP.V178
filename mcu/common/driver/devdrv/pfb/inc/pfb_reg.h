#ifndef __PFB_REG_H__
#define __PFB_REG_H__

#include <reg_base.h>

    #ifdef __PCORE__
        #define BASE_MADDR_MDMCUMISC    (BASE_MADDR_PSMCU_MISC_REG)
        #define MD_MCU2EMI_CON0         (BASE_MADDR_MDMCUMISC + 0x0C)
        #define MD_MCU2EMI_STATUS0      (BASE_MADDR_MDMCUMISC + 0x10)
        #define MD_PFBUFFER_STATUS0     (BASE_MADDR_MDMCUMISC + 0x14)
        #define MD_PFBUFFER_STATUS1     (BASE_MADDR_MDMCUMISC + 0x18)
        #define MD_PFBUFFER_STATUS2     (BASE_MADDR_MDMCUMISC + 0x1C)
        #define MD_PFBUFFER_STATUS3     (BASE_MADDR_MDMCUMISC + 0x20)
        #define MD_PFBUFFER_STATUS4     (BASE_MADDR_MDMCUMISC + 0x24)
        #define MD_PFBUFFER_STATUS5     (BASE_MADDR_MDMCUMISC + 0x28)
        #define MD_PFBUFFER_STATUS6     (BASE_MADDR_MDMCUMISC + 0x2C)
    #else // __L1CORE__
        #define MD_MCU2EMI_CON0         (L1_BASE_MADDR_MDL1_CONF + 0x20C)
        #define MD_MCU2EMI_STATUS0      (L1_BASE_MADDR_MDL1_CONF + 0x540)
        #define MD_PFBUFFER_STATUS0     (L1_BASE_MADDR_MDL1_BUS_CONFG + 0x510)
        #define MD_PFBUFFER_STATUS1     (L1_BASE_MADDR_MDL1_BUS_CONFG + 0x514)
        #define MD_PFBUFFER_STATUS2     (L1_BASE_MADDR_MDL1_BUS_CONFG + 0x518)
        #define MD_PFBUFFER_STATUS3     (L1_BASE_MADDR_MDL1_BUS_CONFG + 0x51C)
        #define MD_PFBUFFER_STATUS4     (L1_BASE_MADDR_MDL1_CONF + 0x224)
        #define MD_PFBUFFER_STATUS5     (L1_BASE_MADDR_MDL1_CONF + 0x228)
        #define MD_PFBUFFER_STATUS6     (L1_BASE_MADDR_MDL1_CONF + 0x22C)
    #endif  // __PCORE__

    #define REG_PFB_CTRL                MD_MCU2EMI_CON0
    #define REG_PFB_STATUS              MD_MCU2EMI_STATUS0
    #define REG_PFB_CM_TOTAL_CNT        MD_PFBUFFER_STATUS0
    #define REG_PFB_PF_TOTAL_CNT        MD_PFBUFFER_STATUS1
    #define REG_PFB_HIT_CNT             MD_PFBUFFER_STATUS2
    #define REG_PFB_CON_HIT_CNT         MD_PFBUFFER_STATUS3
    #define REG_PFB_CM_LAST_ADDR        MD_PFBUFFER_STATUS4
    #define REG_PFB_LAST_ADDR_BYPASS    MD_PFBUFFER_STATUS5
    #define REG_PFB_LAST_ADDR_PREFECTCH MD_PFBUFFER_STATUS6

    // REG_PFB_CTRL
    #define PFB_EN                  (1 << 0)
    #define PFB_CNT_ENABLE          (1 << 1)
    #define PFB_PF_LENGTH_EQ4       (1 << 2)
    #define PFB_PF_LENGTH_SEL_BIT   (3)
        #define PFB_PF_LEN_SEL_MASK (0x1 << PFB_PF_LENGTH_SEL_BIT)
        #define PFB_PF_LEN_SEL_32B  (0)
        #define PFB_PF_LEN_SEL_64B  (1 << PFB_PF_LENGTH_SEL_BIT)
    #define PFB_PF_ARID             (0x1 << 4)
    /*
     * TK6291 (L1Core Only)
     *     We have to set this bit or PFB counter get nothing.
     *     Need to trigger a raising edge signal of this bit.
     */
    #define PFB_PF_LAT_CNT          (1 << 29)

    // REG_PFB_STATUS
    #define PFB_UPDATE_STATUS       (1 << 0)
    #define PFB_CM_IDLE             (1 << 1)
    #define PFB_PF_IDLE             (1 << 2)

#endif /* __PFB_REG_H__ */
