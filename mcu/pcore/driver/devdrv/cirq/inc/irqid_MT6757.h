#ifndef __MT6757_IRQID_H__
#define __MT6757_IRQID_H__
/* AP IRQID LIST */
/*begin of MD PS core IRQID LIST*/

/* MD2PSCIRQ*/

#define PS_IRQID_OST          (0)
#define PS_IRQID_FRC          (1)
#define PS_IRQID_LMAC_RAR     (2)
#define PS_IRQID_LMAC_EAR     (3)
#define PS_IRQID_MDWDT        (4)
#define PS_IRQID_NFI          (5)
#define PS_IRQID_L2COPRO      (6)
#define PS_IRQID_GPTM1        (7)
#define PS_IRQID_GPTM2        (8)
#define PS_IRQID_GPTM3        (9)
#define PS_IRQID_GPTM4        (10)
#define PS_IRQID_GPTM5        (11)
#define PS_IRQID_GPTM6        (12)
#define PS_IRQID_UART_MD      (13)
#define PS_IRQID_UART_SH0     (14)
#define PS_IRQID_BUSMON       (15)
#define PS_IRQID_I2C_0        (16)
#define PS_IRQID_USIM0        (17)
#define PS_IRQID_USIM1        (18)
#define PS_IRQID_UART_SH1     (19)
#define PS_IRQID_MDGDMA0      (20)
#define PS_IRQID_MDGDMA1      (21)
#define PS_IRQID_MDGDMA2      (22)
#define PS_IRQID_MDGDMA3      (23)
#define PS_IRQID_EINT0        (24)
#define PS_IRQID_EINT1        (25)
#define PS_IRQID_EINT2        (26)
#define PS_IRQID_EINT3        (27)
#define PS_IRQID_EINT_SHARE   (28)
#define PS_IRQID_BUS_ERR      (29)
#define PS_IRQID_TOPSM        (30)
#define PS_IRQID_DEM_TRIG_INT (31) 

#define PS_IRQID_RSV_0   (32)
#define PS_IRQID_RSV_1   (33)
#define PS_IRQID_RSV_2   (34)
#define PS_IRQID_RSV_3   (35)
#define PS_IRQID_RSV_4   (36)
#define PS_IRQID_RSV_5   (37)
#define PS_IRQID_RSV_6   (38)
#define PS_IRQID_RSV_7   (39)

#define PS_IRQID_ARM7_WDT_INT (40)
#define PS_IRQID_PERFCNT      (41)
#define PS_IRQID_PMU          (42)  
#define PS_IRQID_ECT          (43)

#define PS_IRQID_PS_L1_WDT_INT     (44)
#define PS_IRQID_PS_ARM7_WDT_INT   (45)
#define PS_IRQID_CLDMA             (46)
#define PS_IRQID_ADOE              (47)
#define PS_IRQID_MDLITE_GPTM       (48)

/*AP2PSCIRQ*/
#define PS_IRQID_APWDT        (50)  
#define PS_IRQID_SPI          (53)
#define PS_IRQID_USB2_0       (54)
#define PS_IRQID_USB3         (55)
#define PS_IRQID_SDIO         (56)
#define PS_IRQID_MSDC0        (57)
#define PS_IRQID_EHPI0        (58)
#define PS_IRQID_RTC          (59)
#define PS_IRQID_SOE          (60)
#define PS_IRQID_MSDC1        (61)
#define PS_IRQID_PFC_INT_LV   (62)
#define PS_IRQID_AUXACD       (63)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
#define PS_IRQID_LED          (64) 
#define PS_IRQID_BT_CVSD      (65) 

/*Modeml1sys2PSCIRQ*/
#define PS_IRQID_DSP_L1DMA                (70)
#define PS_IRQID_SHARE_D12MINT2           (71)
#define PS_IRQID_LTE_TIMER_EMAC_SF_TICK   (72)
#define PS_IRQID_IRDBG_MCU_INT_B          (73)
#define PS_IRQID_MODEMSYS_TRACE           (74)
#define PS_IRQID_L1_ADOE_INT 			  (75)
#define PS_IRQID_BC_IRQ_B  				  (80)
#define PS_IRQID_IRQID_UEA_UIA_IRQ_B      (81)
#define PS_IRQID_IRQID_UPA_ACC_IRQ_B      (82)
#define PS_IRQID_IRQID_DPA_ACC_IRQ_B      (83)

/*PCCIRQ2PSCIRQ*/
#define PS_IRQID_CCIRQ_12P_0    (85)
#define PS_IRQID_CCIRQ_12P_1    (86)
#define PS_IRQID_CCIRQ_12P_2    (87)
#define PS_IRQID_CCIRQ_12P_3    (88)
#define PS_IRQID_CCIRQ_12P_4    (89)
#define PS_IRQID_CCIRQ_12P_5    (90)
#define PS_IRQID_CCIRQ_12P_6    (91)
#define PS_IRQID_CCIRQ_12P_7    (92)
#define PS_IRQID_CCIRQ_12P_8    (93)
#define PS_IRQID_CCIRQ_12P_9    (94)
#define PS_IRQID_CCIRQ_12P_10   (95)
#define PS_IRQID_CCIRQ_12P_11   (96)
#define PS_IRQID_CCIRQ_12P_12   (97)
#define PS_IRQID_CCIRQ_12P_13   (98)
#define PS_IRQID_CCIRQ_12P_14   (99)
#define PS_IRQID_CCIRQ_12P_15   (100)

/*PCCIRQ2PSCIRQ*/
#define PS_IRQID_PCCIF_AP_IRQ              (105)
#define PS_IRQID_PCCIF_ARM7_IRQ            (107)

/* CCIRQ: C2K to PSCORE */
#define PS_IRQID_C2K_PS_INT0    (108)
#define PS_IRQID_C2K_PS_INT1    (109)
#define PS_IRQID_C2K_PS_INT2    (110)
#define PS_IRQID_C2K_PS_INT3    (111)

/*MDGLBCON*/
#define PS_IRQID_SOE_INT                   (116)
#define PS_IRQID_LDO_LV_ADJ                (117)
#define PS_IRQID_TRACE_INT                 (118)
#define PS_IRQID_SPM2MD_DVFS_MDPERISYS     (119)
#define PS_IRQID_MD2MD_CCIF_MD1_0          (120)
#define PS_IRQID_MD2MD_CCIF_MD1_1          (121)
#define PS_IRQID_MD2MD_CCIF_MD1_2          (122)
#define PS_IRQID_MD2MD_CCIF_MD1_3          (123)
#define PS_IRQID_PSMCUPLL_FRQ_ADJ_RDY      (124)
#define PS_IRQID_DCXO_RDY_WO_ACK_IRQ       (125)
#define PS_IRQID_PLL_REQ_WO_DCXO_IRQ       (126)
#define PS_IRQID_TOP_PLL_DSNS_IRQ          (127)
/*end of MD PS core IRQID LIST*/


#endif /*end of __MT6757_IRQID_H__*/
