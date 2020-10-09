#ifndef __GDMA_REG_H__
#define __GDMA_REG_H__

#include <reg_base.h>
#include <irqid.h>

/* Register Address Definition */
#define MDGDMA_BASE          (BASE_ADDR_MDGDMA)

#define GDMA_CODA_VERSION    (MDGDMA_BASE)

/* n = 1~4 */
#define GDMA_FDCSR(n)               (MDGDMA_BASE + 0x10U + (4*(n/2)))
    #define FDMA_STAT(n)            (0x1 << ((n % 2) * 16))
    #define FDMA_CS_EN(n)           (0x1 << (8 + (n % 2) * 16))
    #define FDMA_BD_CS_EN(n)        (0x1 << (11 + (n % 2) * 16))
    #define FDMA_MODE_LINKLIST(n)   (0x0 << (9 + (n % 2) * 16))
    #define FDMA_MODE_BASIC(n)      (0x1 << (9 + (n % 2) * 16))
    #define FDMA_MODE_DESCRPT(n)    (0x2 << (9 + (n % 2) * 16))
    #define FDMA_CS16B_EN           (0x1 << 31)

#define GDMA_CH_REG_OFFSET          0x20
#define GDMA_FDCR(n)                (MDGDMA_BASE + 0x20U + (n*GDMA_CH_REG_OFFSET))
    #define FDMA_START              (0x1 << 0)
    #define FDMA_RESUME             (0x1 << 1)
    #define FDMA_STOP               (0x1 << 2)

    #define BST_SIZE_OFFSET         13    
    #define BST_SIZE_64             (6 << BST_SIZE_OFFSET)
    #define BST_SIZE_32             (5 << BST_SIZE_OFFSET)
    #define BST_SIZE_16             (4 << BST_SIZE_OFFSET)
    #define BST_SIZE_8              (3 << BST_SIZE_OFFSET)
    #define BST_SIZE_4              (2 << BST_SIZE_OFFSET)

    #define DA_FIXED                (1 << 9)
    #define SA_FIXED                (1 << 8)

    #define DST_BUS_WIDTH_OFFSET    6
    #define DST_BUS_WIDTH_4         (2 << DST_BUS_WIDTH_OFFSET)
    #define DST_BUS_WIDTH_2         (1 << DST_BUS_WIDTH_OFFSET)
    #define DST_BUS_WIDTH_1         (0 << DST_BUS_WIDTH_OFFSET)
    #define DST_BUS_WIDTH(n)        ((n) << DST_BUS_WIDTH_OFFSET)

    #define SRC_BUS_WIDTH_OFFSET    4
    #define SRC_BUS_WIDTH_4         (2 << SRC_BUS_WIDTH_OFFSET)
    #define SRC_BUS_WIDTH_2         (1 << SRC_BUS_WIDTH_OFFSET)
    #define SRC_BUS_WIDTH_1         (0 << SRC_BUS_WIDTH_OFFSET)
    #define SRC_BUS_WIDTH(n)        ((n) << SRC_BUS_WIDTH_OFFSET)

#define GDMA_FDSAR(n)               (MDGDMA_BASE + 0x24U + (n*GDMA_CH_REG_OFFSET))
#define GDMA_FDDAR(n)               (MDGDMA_BASE + 0x28U + (n*GDMA_CH_REG_OFFSET))
#define GDMA_FDSCPR(n)              (MDGDMA_BASE + 0x30U + (n*GDMA_CH_REG_OFFSET))
#define GDMA_FDDCPR(n)              (MDGDMA_BASE + 0x34U + (n*GDMA_CH_REG_OFFSET))
#define GDMA_SIZE(n)                (MDGDMA_BASE + 0x38U + (n*GDMA_CH_REG_OFFSET))

#define GDMA_GCTL                   (MDGDMA_BASE + 0x400U)
    #define ARB_NEW_PROM_BEHAV      (1 << 8)
    #define ARB_WIN_SIZE(n)         ((n) << 4)

#define GDMA_GPMTR(n)               (MDGDMA_BASE + 0x410U + (n*4))

#define GDMA_GISAR0                 (MDGDMA_BASE + 0x600U)
    #define FDMA_SRC_DONE(n)        (0x1 << (n + 0))
    #define FDMA_DST_DONE(n)        (0x1 << (n + 4))
    #define FDMA_QE_SRC_DONE(n)     (0x1 << (n + 8))
    #define FDMA_QE_DST_INT(n)      (0x1 << (n + 12))
    #define FDMA_LEN_ERR_INT(n)     (0x1 << (n + 16))
    #define FDMA_ALO_LEN_ERR_INT(n) (0x1 << (n + 20))
    #define FDMA_BD_CSERR_INT(n)    (0x1 << (n + 24))
    #define FDMA_GPD_CSERR_INT(n)   (0x1 << (n + 28))
#define GDMA_GISAR1                 (MDGDMA_BASE + 0x604U)
    #define FDMA_BD_DAT_CSERR(n)    (0x1 << (n + 0))

#define GDMA_GIMRK0                 (MDGDMA_BASE + 0x620U)
#define GDMA_GIMRK1                 (MDGDMA_BASE + 0x624U)
#define GDMA_AXI_CON                (MDGDMA_BASE + 0x800U)
    #define PF_ID(n)                    (((n) & 0x3) << 30)
    #define AHB2AXI_ERR_RW              (1 << 29)
    #define AHB2AXI_ERR_UNALIGN         (1 << 28)
    #define OT_DIS                      (1 << 27)
    #define RCHAN_SEL(n)                (((n) & 0x7) << 24)
    #define PF_EN_UPDATED               (1 << 23)
    #define PF_HIT_THRES(n)             (((n) & 0x7) << 20)
    #define SINGLE_USE_PF               (1 << 19)
    #define PF_LEN_SEL                  (1 << 18)
    #define PF_COUNT_EN                 (1 << 17)
    #define PF_ENABLE                   (1 << 16)
    #define CG_DISABLE                  (1 << 15)
    #define AHB2AXI_FIFO_THRES(n)       (((n) & 0x7) << 12)
    #define AHB2AXI_MERGE_EN            (1 << 11)
    #define AHB2AXI_BUFFERABLE_EN       (1 << 10)
    #define AHB_ID(n)                   (((n) & 0x3) << 8)
    #define DEBUG_FLAG(n)               ((n) & 0xF)
#define GDMA_UNALIGN_ADDR           (MDGDMA_BASE + 0x828U)
#define GDMA_IDLE                   (MDGDMA_BASE + 0x82CU)
    #define AXI_ALL_IDLE            (1 << 7)
    #define AXI_M2S1_IDLE           (1 << 3)
    #define AXI_M1S2_IDLE           (1 << 2)
    #define AHB2AXI_IDLE            (1 << 1)
    #define GDMA_AHB_IDLE           (1 << 0)

#define GDMA_INTR_ID                IRQ_MDGDMA0_CODE

#endif /* end of __GDMA_REG_H__ */
