#ifndef __PCM_REG_H__
#define __PCM_REG_H__

#include <reg_base.h>
#include <intrCtrl.h>


/* Register Address Definition */
#define PCMON_BASE                  (BASE_MADDR_MDPCMON)
#if defined(__PCORE__)
#define L1_PCMON_BASE               (L1_BASE_MADDR_MDPCMON)
#endif // __PCORE__

#define PCMON_CTRL_0                (PCMON_BASE + 0x0U)
#define PCMON_DEV_CTRL_0            ((PCMON_CTRL_0 & ~MDSYS_PERI_ACC_TYPE_MASK) | MDSYS_PERI_DEVICE_TYPE)
    #define PCMON_ETM_ENABLE            (1U<<31)
    #define PCMON_EVT_MASK_PCMON        (1U<<17)
    #define PCMON_EVT_MASK_RMPU         (1U<<16)
    #define PCMON_EVT_MASK_RGU          (1U<<15)
    #define PCMON_EVT_MASK_BUS_L1       (1U<<14)
    #define PCMON_EVT_MASK_BUS_PS       (1U<<13)
    #define PCMON_EVT_MASK_BUS_AP       (1U<<12)
    #define PCMON_EVT_MASK_CTI          (1U<<11)
    #define PCMON_EVT_MASK_BUSMON_L1    (1U<<10)
    #define PCMON_EVT_MASK_BUSMON_PS    (1U<<9)
    #define PCMON_EVT_MASK_BUSMON_AP    (1U<<8)
    #define PCMON_DIFF_MASK             (0x7F)
    #define PCMON_DIFF(n)               (((n)&(PCMON_DIFF_MASK))<<0)
#define L1PCMON_CTRL_1              (L1_PCMON_BASE + 0x4U)
#define PCMON_CTRL_1                (PCMON_BASE + 0x4U)
    #define PCMON_STOP                  (1U<<31)
    #define PCMON_RESTART               (1U<<0)
#define PCMON_DA_BASE               (PCMON_BASE + 0x8U)
#define PCMON_DA_MASK               (PCMON_BASE + 0xCU)
#define L1PCMON_RECORD_STATUS       (L1_PCMON_BASE + 0x10U)
#define PCMON_RECORD_STATUS         (PCMON_BASE + 0x10U)
    #define PCMON_RGU_STATUS            (1U<<31)
    #define PCMON_IS_STOPPED            (1U<<30)
    #define PCMON_TRIG_PCMON            (1U<<25)
    #define PCMON_TRIG_RMPU             (1U<<24)
    #define PCMON_TRIG_RGU              (1U<<23)
    #define PCMON_TRIG_BUS_L1           (1U<<22)
    #define PCMON_TRIG_BUS_PS           (1U<<21)
    #define PCMON_TRIG_BUS_AP           (1U<<20)
    #define PCMON_TRIG_CTI              (1U<<19)
    #define PCMON_TRIG_BUSMON_L1        (1U<<18)
    #define PCMON_TRIG_BUSMON_PS        (1U<<17)
    #define PCMON_TRIG_BUSMON_AP        (1U<<16)
    #define PCMON_DA_WRAP               (1U<<15)
    #define PCMON_DA_COUNT_SHIFT        (8)
    #define PCMON_DA_COUNT_MASK         (0x1F)
    #define PCMON_IA_WRAP               (1U<<7)
    #define PCMON_IA_COUNT_SHIFT        (0)
    #define PCMON_IA_COUNT_MASK         (0x1F)
#define PCMON_DUMMY                 (PCMON_BASE + 0xFCU)
#define PCMON_TAG_START             (PCMON_BASE + 0x300U)
    #define PCMON_TAG_MARK              (1U<<31)
    #define PCMON_TAG_IDX_SHIFT         (16)
    #define PCMON_TAG_IDX_MASK          (0x1F)
    #define PCMON_TAG_DA_REC_CNT_SHIFT  (8)
    #define PCMON_TAG_DA_REC_CNT_MASK   (0x1F)
    #define PCMON_TAG_DA_CNT_SHIFT      (0)
    #define PCMON_TAG_DA_CNT_MASK       (0x1F)

/* n = 0~63 */
#define PCMON_PC_(n)                (PCMON_BASE + ((n))*0x8U + 0x100U)
#define PCMON_CID_(n)               (PCMON_BASE + ((n))*0x8U + 0x104U)

#define L1PCMON_PC_(n)              (L1_PCMON_BASE + ((n))*0x8U + 0x100U)
#define L1PCMON_CID_(n)             (L1_PCMON_BASE + ((n))*0x8U + 0x104U)
/* n = 0 ~ 31 */
#define PCMON_IADA_TAG(n)           (PCMON_BASE + ((n))*0x4U + 0x300U)
#define PCMON_IADA_PC(n)            (PCMON_BASE + ((n))*0x8U + 0x400U)
#define PCMON_IADA_DA(n)            (PCMON_BASE + ((n))*0x8U + 0x404U)

#define L1PCMON_IADA_TAG(n)         (L1_PCMON_BASE + ((n))*0x4U + 0x300U)
#define L1PCMON_IADA_PC(n)          (L1_PCMON_BASE + ((n))*0x8U + 0x400U)
#define L1PCMON_IADA_DA(n)          (L1_PCMON_BASE + ((n))*0x8U + 0x404U)

#define PCMON_TOTAL_RECORD_COUNT    (32)

#endif /* end of __PCM_REG_H__ */
