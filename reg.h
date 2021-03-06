#ifndef REG_H
#define REG_H

//REG OPERATIONS

#define UINT32_1 ((uint32_t)1)

#define REG(addr) (*((volatile uint32_t *)(addr)))

#define CLEAR_MASK(highest_bit, lowest_bit) (((highest_bit) - (lowest_bit)) >= 31 ? (uint32_t)0xFFFFFFFF : ~(((UINT32_1 << ((highest_bit) - (lowest_bit) + 1)) - 1) << (lowest_bit)))
#define WRITE_BITS(addr, highest_bit, lowest_bit, data) (REG(addr) = (REG(addr) & CLEAR_MASK(highest_bit, lowest_bit)) | ((uint32_t)(data) << (lowest_bit)))

#define SET_BIT(addr, bit) (REG(addr) |= UINT32_1 << (bit))
#define CLEAR_BIT(addr, bit) (REG(addr) &= ~(UINT32_1 << (bit)))

#define READ_BIT(addr, bit) ((REG(addr) >> (bit)) & UINT32_1)

#define TIM4_BASE 0x40000800
#define TIMx_CR1_OFFSET 0x00
#define TIMx_CKD_1_BIT 9
#define TIMx_CKD_0_BIT 8
#define TIMx_ARPE 7
#define TIMx_CMS_1_BIT 6
#define TIMx_CMS_0_BIT 5
#define TIMx_DIR 4
#define TIMx_OPM 3
#define TIMx_URS 2
#define TIMx_UDIS 1
#define TIMx_CEN 0

#define TIMx_SR_OFFSET 0x10
#define TIMx_SR_UIF 0
#define TIMx_PSC_OFFSET 0x28
#define TIMx_PSC_15_BIT 15
#define TIMx_PSC_0_BIT 0
#define TIMx_ARR_OFFSET 0x2C
#define TIMx_ARR_15_BIT 15
#define TIMx_ARR_0_BIT 0


#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC_BASE 0x40012000
#define ADC_OFFSET(n) (0x100*(n-1))

#define ADC_SR_OFFSET 0x0
#define ADC_EOC 1

#define ADC_CR1_OFFSET 0x04
#define ADC_CR1_RES_1_BIT 25
#define ADC_CR1_RES_0_BIT 24
#define ADC_CR1_SCAN 8

#define ADC_CR2_OFFSET 0x08
#define ADC_CR2_SWSTART 30
#define ADC_CR2_EXTEN_1_BIT 29
#define ADC_CR2_EXTEN_0_BIT 28
#define ADC_CR2_ALIGN 11
#define ADC_CR2_CONT 1
#define ADC_CR2_ADON 0

#define ADC_SMPR2_OFFSET 0x10
#define ADC_SMPR2_SMPn_2_BIT(n) (3*n+2)
#define ADC_SMPR2_SMPn_0_BIT(n) (3*n)

#define ADC_SQR1_OFFSET 0x2C
#define ADC_SQR1_L_3_BIT 23
#define ADC_SQR1_L_0_BIT 20

#define ADC_SQR3_OFFSET 0x34
#define ADC_SQR3_SQ1_4_BIT 4
#define ADC_SQR3_SQ1_0_BIT 0

#define ADC_DR_OFFSET 0x4C

#define ADC_COMMOM_OFFSET 0x300
#define ADC_COMMOM_CCR_OFFSET 0x04
#define ADC_ADCPRE_1_BIT 17
#define ADC_ADCPRE_0_BIT 16
#define ADC_DMA_1_BIT 15
#define ADC_DMA_0_BIT 14
#define ADC_DELAY_3_BIT 11
#define ADC_DELAY_0_BIT 8
#define ADC_MULTI_4_BIT 4
#define ADC_MULTI_0_BIT 0

#define ADC_COMMOM_CDR 0x08

#define DAC_BASE 0x40007400
#define DAC_CR_OFFSET 0x00
#define DAC_CR_DMAUDRIE1 13
#define DAC_CR_DMAEN1 12
#define DAC_CR_MAMP1_3_BIT 11
#define DAC_CR_MAMP1_0_BIT 8
#define DAC_CR_WAVE1_1_BIT 7
#define DAC_CR_WAVE1_0_BIT 6
#define DAC_CR_TSEL1_2_BIT 5
#define DAC_CR_TSEL1_0_BIT 3
#define DAC_CR_TEN1 2
#define DAC_CR_BOFF1 1
#define DAC_CR_EN1 0
#define DAC_SWTRIGR_OFFSET 0x04
#define DAC_SWTRIGR_SWTRIG1 0
#define DAC_DHR12R1_OFFSET 0x08
#define DAC_DHR12R1_DACC1DHR_11_BIT 11
#define DAC_DHR12R1_DACC1DHR_0_BIT 0
#define DAC_DHR8R1_OFFSET 0x10
#define DAC_DHR8R1_DACC1DHR_7_BIT 7
#define DAC_DHR8R1_DACC1DHR_0_BIT 0

#define AIRCR_BASE 0xE000ED0C
#define NVIC_AIRCR_RESET_VALUE 0x05FA0000
#define NVIC_PRIORITYGROUP_4 0x300

#define ETHERNET_MAC_BASE 0x40028000

#define ETH_MACCR_OFFSET 0x0000
#define WD 23
#define JD 22
#define IFG_2_BIT 19
#define IFG_0_BIT 17
#define CSD 16
#define FES 14
#define ROD 13
#define LM 12
#define DM 11
#define IPCO 10
#define RD 9
#define APCS 7
#define BL_1_BIT 6
#define BL_0_BIT 5
#define DC 4

#define ETH_MACFFR_OFFSET  0x0004
#define RA 31
#define SAF 9
#define PCF_1_BIT 7
#define PCF_0_BIT 6
#define BFD 5
#define DAIF 3
#define HM 2
#define HU 1
#define PM 0

#define ETH_MACHTHR_OFFSET 0x0008
#define ETH_MACHTLR_OFFSET 0x000C

#define ETH_MACMIIAR_OFFSET 0x0010
#define PA_4_BIT 15
#define PA_0_BIT 11
#define MR_4_BIT 10
#define MR_0_BIT 6
#define CR_2_BIT 4
#define CR_0_BIT 2
#define MW 1
#define MB 0

#define ETH_MACVLANTR_OFFSET 0x001C
#define VLANTC 16
#define VLANTI_15_BIT 15
#define VLANTI_0_BIT 0

#define ETH_MACFCR_OFFSET 0x0018
#define PT_15_BIT 31
#define PT_0_BIT 16
#define ZQPD 7
#define PLTPT_1_BIT 5
#define PLTPT_0_BIT 4
#define UPFD 3
#define RFCE 2
#define TFCE 1


#define ETH_DMABMR_OFFSET 0x1000
#define AAB 25
#define USP 23
#define RDP_5_BIT 22
#define RDP_0_BIT 17
#define FB 16
#define PBL_5_BIT 13
#define PBL_0_BIT 8
#define DSL_5_BIT 6
#define DSL_0_BIT 2
#define DA 1
#define SR 0

#define ETH_DMAOMR_OFFSET 0x1018
#define DTCEFD 26
#define RSF 25
#define DFRF 24
#define TSF 21
#define TTC_2_BIT 16
#define TTC_0_BIT 14
#define FEF 7
#define RTC_1_BIT 4
#define RTC_0_BIT 3
#define OSF 2

//FLASH
#define FLASH_BASE 0x40023C00

#define FLASH_ACR_OFFSET 0x00
#define PRFTEN_BIT 8
#define LATENCY_2_BIT 2
#define LATENCY_0_BIT 0

//RCC
#define RCC_BASE 0x40023800

#define RCC_CR_OFFSET 0x00
#define PLLRDY_BIT 25
#define PLLON_BIT 24
#define HSERDY_BIT 17
#define HSEON_BIT 16

#define RCC_PLLCFGR_OFFSET 0x04
#define PLLSRC_BIT 22
#define PLLQ_3_BIT 27
#define PLLQ_0_BIT 24
#define PLLP_1_BIT 17
#define PLLP_0_BIT 16
#define PLLN_8_BIT 14
#define PLLN_0_BIT 6
#define PLLM_5_BIT 5
#define PLLM_0_BIT 0

#define RCC_CFGR_OFFSET 0x08
#define MCO2_1_BIT 31
#define MCO2_0_BIT 30

#define MCO2PRE_2_BIT 29
#define MCO2PRE_1_BIT 28
#define MCO2PRE_0_BIT 27

#define SWS_1_BIT 3
#define SWS_0_BIT 2

#define SW_1_BIT 1
#define SW_0_BIT 0

#define RCC_AHB1RSTR_OFFSET  0x10
#define ETHMACRST 25

#define RCC_AHB1ENR_OFFSET 0x30
#define GPIO_EN_BIT(port) (port)
#define ETHMACRXEN 27
#define ETHMACTXEN 26
#define ETHMACEN 25

#define RCC_APB1ENR_OFFSET 0x40
#define DACEN 29
#define I2C1EN 21
#define USART2EN 17
#define TIM4EN 2
#define TIM2EN 0

#define RCC_APB2ENR_OFFSET 0x44
#define SYSCFGEN_BIT 14
#define ADC1EN 8
#define USART6EN 5
#define USART1EN 4

//GPIO
#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2
#define GPIO_PORTD 3
#define GPIO_PORTE 4
#define GPIO_PORTF 5
#define GPIO_PORTG 6
#define GPIO_PORTH 7
#define GPIO_PORTI 8
#define GPIO_PORTJ 9
#define GPIO_PORTK 10

#define GPIO_BASE(port) (0x40020000 + 0x400 * (port))

#define GPIOx_MODER_OFFSET 0x00
#define MODERy_1_BIT(y) ((y)*2 + 1)
#define MODERy_0_BIT(y) ((y)*2)

#define GPIOx_OTYPER_OFFSET 0x04
#define OTy_BIT(y) (y)

#define GPIOx_OSPEEDR_OFFSET 0x08
#define OSPEEDRy_1_BIT(y) ((y)*2 + 1)
#define OSPEEDRy_0_BIT(y) ((y)*2)
#define GPIOx_IDR_OFFSET 0x10
#define GPIOx_PUPDR_OFFSET 0x0C
#define PUPDRy_1_BIT(y) ((y)*2 + 1)
#define PUPDRy_0_BIT(y) ((y)*2)
#define GPIOx_BSRR_OFFSET 0x18
#define BRy_BIT(y) ((y) + 16)
#define BSy_BIT(y) (y)
#define GPIOx_AFRL_OFFSET 0x20
#define AFRLy_3_BIT(y) ((y)*4 + 3)
#define AFRLy_0_BIT(y) ((y)*4)

//EXTI
#define EXTI_BASE 0x40013C00

#define EXTI_IMR_OFFSET 0x00

#define EXTI_RTSR_OFFSET 0x08

#define EXTI_FTSR_OFFSET 0x0C

#define EXTI_PR_OFFSET 0x14

//SYSCFG
#define SYSCFG_BASE 0x40013800

#define SYSCFG_PMC_OFFSET 0x04
#define MII_RMII_SEL_BIT 23

#define SYSCFG_EXTICR1_OFFSET 0x08

#define EXTI0_3_BIT 3
#define EXTI0_0_BIT 0

#define I2C1_BASE 0x40005400
#define I2C_CR1_OFFSET 0x00
#define I2C_CR2_OFFSET 0x04
#define I2C_OAR1_OFFSET 0x08
#define I2C_OAR2_OFFSET 0x0C
#define I2C_DR_OFFSET 0x10
#define I2C_SR1_OFFSET 0x14
#define I2C_SR2_OFFSET 0x18
#define I2C_CCR_OFFSET 0x1C
#define I2C_TRISE_OFFSET 0x20
#define I2C_FLTR_OFFSET 0x24
//USART1
#define USART1_BASE 0x40011000
#define USART2_BASE 0x40004400
#define USART6_BASE 0x40011400

#define USART_SR_OFFSET 0x00
#define TXE_BIT 7
#define TC_BIT 6
#define RXNE_BIT 5
#define ORE_BIT 3

#define USART_DR_OFFSET 0x04

#define USART_BRR_OFFSET 0x08
#define DIV_MANTISSA_11_BIT 15
#define DIV_MANTISSA_0_BIT 4
#define DIV_FRACTION_3_BIT 3
#define DIV_FRACTION_0_BIT 0

#define USART_CR1_OFFSET 0x0C
#define UE_BIT 13
#define RXNEIE_BIT 5
#define TE_BIT 3
#define RE_BIT 2

#define USART_ISR_OFFSET 0x1C
#define TXE_BIT 7
#define TC_BIT 6
#define RXNE_BIT 5
#define ORE_BIT 3

#define USART_RDR_OFFSET 0x04
#define USART_TDR_OFFSET 0x04



//MPU
#define MPU_BASE 0xE000ED90

#define MPU_CTRL_OFFSET 0x04
#define MPU_PRIVDEFENA_BIT 2
#define MPU_ENABLE_BIT 0

#define MPU_RBAR_OFFSET 0x0C
#define MPU_RBAR_VALUE(addr, region) (((uint32_t)(addr)) | (UINT32_1 << 4) | ((uint32_t)(region)))

#define MPU_RASR_OFFSET 0x10
#define MPU_RASR_VALUE(xn, ap, type, srd, size) (((uint32_t)(xn) << 28) | ((uint32_t)(ap) << 24) | ((uint32_t)(type) << 16) | ((uint32_t)(srd) << 8) | ((uint32_t)(size) << 1) | UINT32_1)
#define MPU_XN_DISABLE 0
#define MPU_XN_ENABLE 1
#define MPU_AP_NO_ACCESS 0b000
#define MPU_AP_PRIV_ACCESS 0b001
#define MPU_AP_NPRIV_RO 0b010
#define MPU_AP_FULL_ACCESS 0b011
#define MPU_AP_PRIV_RO 0b101
#define MPU_AP_RO 0b110
#define MPU_TYPE_FLASH 0b000010
#define MPU_TYPE_SRAM 0b000110
#define MPU_TYPE_EXRAM 0b000111
#define MPU_TYPE_PERIPHERALS 0b000101
#define MPU_REGION_SIZE_32B 0b00100
#define MPU_REGION_SIZE_64B 0b00101
#define MPU_REGION_SIZE_128B 0b00110
#define MPU_REGION_SIZE_256B 0b00111
#define MPU_REGION_SIZE_512B 0b01000
#define MPU_REGION_SIZE_1KB 0b01001
#define MPU_REGION_SIZE_2KB 0b01010
#define MPU_REGION_SIZE_4KB 0b01011
#define MPU_REGION_SIZE_8KB 0b01100
#define MPU_REGION_SIZE_16KB 0b01101
#define MPU_REGION_SIZE_32KB 0b01110
#define MPU_REGION_SIZE_64KB 0b01111
#define MPU_REGION_SIZE_128KB 0b10000
#define MPU_REGION_SIZE_256KB 0b10001
#define MPU_REGION_SIZE_512KB 0b10010
#define MPU_REGION_SIZE_1MB 0b10011
#define MPU_REGION_SIZE_2MB 0b10100
#define MPU_REGION_SIZE_4MB 0b10101
#define MPU_REGION_SIZE_8MB 0b10110
#define MPU_REGION_SIZE_16MB 0b10111
#define MPU_REGION_SIZE_32MB 0b11000
#define MPU_REGION_SIZE_64MB 0b11001
#define MPU_REGION_SIZE_128MB 0b11010
#define MPU_REGION_SIZE_256MB 0b11011
#define MPU_REGION_SIZE_512MB 0b11100
#define MPU_REGION_SIZE_1GB 0b11101
#define MPU_REGION_SIZE_2GB 0b11110
#define MPU_REGION_SIZE_4GB 0b11111

//NVIC
#define NVIC_ISER_BASE 0xE000E100

#define NVIC_ISERn_OFFSET(n) (0x00 + 4 * (n))

#endif
