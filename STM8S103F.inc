;/* STM8S103F.h */

;/* Copyright (c) 2003-2017 STMicroelectronics */

;#ifndef __STM8S103F__
;#define __STM8S103F__

;/* STM8S103F */

	;/* Check MCU name */
	;#ifdef MCU_NAME
		;#define STM8S103F 1
		;#if (MCU_NAME != STM8S103F)
		;#error "wrong include file STM8S103F.h for chosen MCU!"
		;#endif
	;#endif

	;#ifdef __CSMC__
		;#define DEF_8BIT_REG_AT(NAME,ADDRESS) volatile unsigned char NAME @ADDRESS
		;#define DEF_16BIT_REG_AT(NAME,ADDRESS) volatile unsigned int NAME @ADDRESS
	;#endif

	;#ifdef __RAISONANCE__
		;#define DEF_8BIT_REG_AT(NAME,ADDRESS) at ADDRESS hreg NAME
		;#define DEF_16BIT_REG_AT(NAME,ADDRESS) at ADDRESS hreg16 NAME
	;#endif

;/* Port A */
;/*****************************************************************/

;/* Port A data output latch register */
PA_ODR equ 0x5000

;/* Port A input pin value register */
PA_IDR equ 0x5001

;/* Port A data direction register */
PA_DDR equ 0x5002

;/* Port A control register 1 */
PA_CR1 equ 0x5003

;/* Port A control register 2 */
PA_CR2 equ 0x5004

;/* Port B */
;/*****************************************************************/

;/* Port B data output latch register */
PB_ODR equ 0x5005

;/* Port B input pin value register */
PB_IDR equ 0x5006

;/* Port B data direction register */
PB_DDR equ 0x5007

;/* Port B control register 1 */
PB_CR1 equ 0x5008

;/* Port B control register 2 */
PB_CR2 equ 0x5009

;/* Port C */
;/*****************************************************************/

;/* Port C data output latch register */
PC_ODR equ 0x500a

;/* Port C input pin value register */
PC_IDR equ 0x500b

;/* Port C data direction register */
PC_DDR equ 0x500c

;/* Port C control register 1 */
PC_CR1 equ 0x500d

;/* Port C control register 2 */
PC_CR2 equ 0x500e

;/* Port D */
;/*****************************************************************/

;/* Port D data output latch register */
PD_ODR equ 0x500f

;/* Port D input pin value register */
PD_IDR equ 0x5010

;/* Port D data direction register */
PD_DDR equ 0x5011

;/* Port D control register 1 */
PD_CR1 equ 0x5012

;/* Port D control register 2 */
PD_CR2 equ 0x5013

;/* Flash */
;/*****************************************************************/

;/* Flash control register 1 */
FLASH_CR1 equ 0x505a

;/* Flash control register 2 */
FLASH_CR2 equ 0x505b

;/* Flash complementary control register 2 */
FLASH_NCR2 equ 0x505c

;/* Flash protection register */
FLASH_FPR equ 0x505d

;/* Flash complementary protection register */
FLASH_NFPR equ 0x505e

;/* Flash in-application programming status register */
FLASH_IAPSR equ 0x505f

;/* Flash Program memory unprotection register */
FLASH_PUKR equ 0x5062

;/* Data EEPROM unprotection register */
FLASH_DUKR equ 0x5064

;/* External Interrupt Control Register (ITC) */
;/*****************************************************************/

;/* External interrupt control register 1 */
EXTI_CR1 equ 0x50a0

;/* External interrupt control register 2 */
EXTI_CR2 equ 0x50a1

;/* Reset (RST) */
;/*****************************************************************/

;/* Reset status register 1 */
RST_SR equ 0x50b3

;/* Clock Control (CLK) */
;/*****************************************************************/

;/* Internal clock control register */
CLK_ICKR equ 0x50c0

;/* External clock control register */
CLK_ECKR equ 0x50c1

;/* Clock master status register */
CLK_CMSR equ 0x50c3

;/* Clock master switch register */
CLK_SWR equ 0x50c4

;/* Clock switch control register */
CLK_SWCR equ 0x50c5

;/* Clock divider register */
CLK_CKDIVR equ 0x50c6

;/* Peripheral clock gating register 1 */
CLK_PCKENR1 equ 0x50c7

;/* Clock security system register */
CLK_CSSR equ 0x50c8

;/* Configurable clock control register */
CLK_CCOR equ 0x50c9

;/* Peripheral clock gating register 2 */
CLK_PCKENR2 equ 0x50ca

;/* CAN clock control register */
CLK_CANCCR equ 0x50cb

;/* HSI clock calibration trimming register */
CLK_HSITRIMR equ 0x50cc

;/* SWIM clock control register */
CLK_SWIMCCR equ 0x50cd

;/* Window Watchdog (WWDG) */
;/*****************************************************************/

;/* WWDG Control Register */
WWDG_CR equ 0x50d1

;/* WWDR Window Register */
WWDG_WR equ 0x50d2

;/* Independent Watchdog (IWDG) */
;/*****************************************************************/

;/* IWDG Key Register */
IWDG_KR equ 0x50e0

;/* IWDG Prescaler Register */
IWDG_PR equ 0x50e1

;/* IWDG Reload Register */
IWDG_RLR equ 0x50e2

;/* Auto Wake-Up (AWU) */
;/*****************************************************************/

;/* AWU Control/Status Register */
AWU_CSR equ 0x50f0

;/* AWU asynchronous prescaler buffer register */
AWU_APR equ 0x50f1

;/* AWU Timebase selection register */
AWU_TBR equ 0x50f2

;/* Beeper (BEEP) */
;/*****************************************************************/

;/* BEEP Control/Status Register */
BEEP_CSR equ 0x50f3

;/* Serial Peripheral Interface (SPI) */
;/*****************************************************************/

;/* SPI Control Register 1 */
SPI_CR1 equ 0x5200

;/* SPI Control Register 2 */
SPI_CR2 equ 0x5201

;/* SPI Interrupt Control Register */
SPI_ICR equ 0x5202

;/* SPI Status Register */
SPI_SR equ 0x5203

;/* SPI Data Register */
SPI_DR equ 0x5204

;/* SPI CRC Polynomial Register */
SPI_CRCPR equ 0x5205

;/* SPI Rx CRC Register */
SPI_RXCRCR equ 0x5206

;/* SPI Tx CRC Register */
SPI_TXCRCR equ 0x5207

;/* I2C Bus Interface (I2C) */
;/*****************************************************************/

;/* I2C control register 1 */
I2C_CR1 equ 0x5210

;/* I2C control register 2 */
I2C_CR2 equ 0x5211

;/* I2C frequency register */
I2C_FREQR equ 0x5212

;/* I2C Own address register low */
I2C_OARL equ 0x5213

;/* I2C Own address register high */
I2C_OARH equ 0x5214

;/* I2C data register */
I2C_DR equ 0x5216

;/* I2C status register 1 */
I2C_SR1 equ 0x5217

;/* I2C status register 2 */
I2C_SR2 equ 0x5218

;/* I2C status register 3 */
I2C_SR3 equ 0x5219

;/* I2C interrupt control register */
I2C_ITR equ 0x521a

;/* I2C Clock control register low */
I2C_CCRL equ 0x521b

;/* I2C Clock control register high */
I2C_CCRH equ 0x521c

;/* I2C TRISE register */
I2C_TRISER equ 0x521d

;/* I2C packet error checking register */
I2C_PECR equ 0x521e

;/* Universal synch/asynch receiver transmitter (UART1) */
;/*****************************************************************/

;/* UART1 Status Register */
UART1_SR equ 0x5230

;/* UART1 Data Register */
UART1_DR equ 0x5231

;/* UART1 Baud Rate Register 1 */
UART1_BRR1 equ 0x5232

;/* UART1 Baud Rate Register 2 */
UART1_BRR2 equ 0x5233

;/* UART1 Control Register 1 */
UART1_CR1 equ 0x5234

;/* UART1 Control Register 2 */
UART1_CR2 equ 0x5235

;/* UART1 Control Register 3 */
UART1_CR3 equ 0x5236

;/* UART1 Control Register 4 */
UART1_CR4 equ 0x5237

;/* UART1 Control Register 5 */
UART1_CR5 equ 0x5238

;/* UART1 Guard time Register */
UART1_GTR equ 0x5239

;/* UART1 Prescaler Register */
UART1_PSCR equ 0x523a

;/* 16-Bit Timer 1 (TIM1) */
;/*****************************************************************/

;/* TIM1 Control register 1 */
TIM1_CR1 equ 0x5250

;/* TIM1 Control register 2 */
TIM1_CR2 equ 0x5251

;/* TIM1 Slave Mode Control register */
TIM1_SMCR equ 0x5252

;/* TIM1 external trigger register */
TIM1_ETR equ 0x5253

;/* TIM1 Interrupt enable register */
TIM1_IER equ 0x5254

;/* TIM1 Status register 1 */
TIM1_SR1 equ 0x5255

;/* TIM1 Status register 2 */
TIM1_SR2 equ 0x5256

;/* TIM1 Event Generation register */
TIM1_EGR equ 0x5257

;/* TIM1 Capture/Compare mode register 1 */
TIM1_CCMR1 equ 0x5258

;/* TIM1 Capture/Compare mode register 2 */
TIM1_CCMR2 equ 0x5259

;/* TIM1 Capture/Compare mode register 3 */
TIM1_CCMR3 equ 0x525a

;/* TIM1 Capture/Compare mode register 4 */
TIM1_CCMR4 equ 0x525b

;/* TIM1 Capture/Compare enable register 1 */
TIM1_CCER1 equ 0x525c

;/* TIM1 Capture/Compare enable register 2 */
TIM1_CCER2 equ 0x525d

;/* TIM1 Counter */
TIM1_CNTR equ 0x525e
;/* Data bits High */
TIM1_CNTRH equ 0x525e
;/* Data bits Low */
TIM1_CNTRL equ 0x525f

;/* TIM1 Prescaler register */
TIM1_PSCR equ 0x5260
;/* Data bits High */
TIM1_PSCRH equ 0x5260
;/* Data bits Low */
TIM1_PSCRL equ 0x5261

;/* TIM1 Auto-reload register */
TIM1_ARR equ 0x5262
;/* Data bits High */
TIM1_ARRH equ 0x5262
;/* Data bits Low */
TIM1_ARRL equ 0x5263

;/* TIM1 Repetition counter register */
TIM1_RCR equ 0x5264

;/* TIM1 Capture/Compare register 1 */
TIM1_CCR1 equ 0x5265
;/* Data bits High */
TIM1_CCR1H equ 0x5265
;/* Data bits Low */
TIM1_CCR1L equ 0x5266

;/* TIM1 Capture/Compare register 2 */
TIM1_CCR2 equ 0x5267
;/* Data bits High */
TIM1_CCR2H equ 0x5267
;/* Data bits Low */
TIM1_CCR2L equ 0x5268

;/* TIM1 Capture/Compare register 3 */
TIM1_CCR3 equ 0x5269
;/* Data bits High */
TIM1_CCR3H equ 0x5269
;/* Data bits Low */
TIM1_CCR3L equ 0x526a

;/* TIM1 Capture/Compare register 4 */
TIM1_CCR4 equ 0x526b
;/* Data bits High */
TIM1_CCR4H equ 0x526b
;/* Data bits Low */
TIM1_CCR4L equ 0x526c

;/* TIM1 Break register */
TIM1_BKR equ 0x526d

;/* TIM1 Dead-time register */
TIM1_DTR equ 0x526e

;/* TIM1 Output idle state register */
TIM1_OISR equ 0x526f

;/* 16-Bit Timer 2 (TIM2) */
;/*****************************************************************/

;/* TIM2 Control register 1 */
TIM2_CR1 equ 0x5300

;/* TIM2 Interrupt enable register */
TIM2_IER equ 0x5303

;/* TIM2 Status register 1 */
TIM2_SR1 equ 0x5304

;/* TIM2 Status register 2 */
TIM2_SR2 equ 0x5305

;/* TIM2 Event Generation register */
TIM2_EGR equ 0x5306

;/* TIM2 Capture/Compare mode register 1 */
TIM2_CCMR1 equ 0x5307

;/* TIM2 Capture/Compare mode register 2 */
TIM2_CCMR2 equ 0x5308

;/* TIM2 Capture/Compare mode register 3 */
TIM2_CCMR3 equ 0x5309

;/* TIM2 Capture/Compare enable register 1 */
TIM2_CCER1 equ 0x530a

;/* TIM2 Capture/Compare enable register 2 */
TIM2_CCER2 equ 0x530b

;/* TIM2 Counter */
TIM2_CNTR equ 0x530c
;/* Data bits High */
TIM2_CNTRH equ 0x530c
;/* Data bits Low */
TIM2_CNTRL equ 0x530d

;/* TIM2 Prescaler register */
TIM2_PSCR equ 0x530e

;/* TIM2 Auto-reload register */
TIM2_ARR equ 0x530f
;/* Data bits High */
TIM2_ARRH equ 0x530f
;/* Data bits Low */
TIM2_ARRL equ 0x5310

;/* TIM2 Capture/Compare register 1 */
TIM2_CCR1 equ 0x5311
;/* Data bits High */
TIM2_CCR1H equ 0x5311
;/* Data bits Low */
TIM2_CCR1L equ 0x5312

;/* TIM2 Capture/Compare register 2 */
TIM2_CCR2 equ 0x5313
;/* Data bits High */
TIM2_CCR2H equ 0x5313
;/* Data bits Low */
TIM2_CCR2L equ 0x5314

;/* TIM2 Capture/Compare register 3 */
TIM2_CCR3 equ 0x5315
;/* Data bits High */
TIM2_CCR3H equ 0x5315
;/* Data bits Low */
TIM2_CCR3L equ 0x5316

;/* 8-Bit  Timer 4 (TIM4) */
;/*****************************************************************/

;/* TIM4 Control register 1 */
TIM4_CR1 equ 0x5340

;/* TIM4 Interrupt enable register */
TIM4_IER equ 0x5343

;/* TIM4 Status register */
TIM4_SR equ 0x5344

;/* TIM4 Event Generation register */
TIM4_EGR equ 0x5345

;/* TIM4 Counter */
TIM4_CNTR equ 0x5346

;/* TIM4 Prescaler register */
TIM4_PSCR equ 0x5347

;/* TIM4 Auto-reload register */
TIM4_ARR equ 0x5348

;/* 10-Bit A/D Converter (ADC1) */
;/*****************************************************************/

;/* ADC Data buffer Register 0 */
ADC_DB0R equ 0x53e0
;/* Data Buffer register 0 High */
ADC_DB0RH equ 0x53e0
;/* Data Buffer register 0 Low */
ADC_DB0RL equ 0x53e1

;/* ADC Data buffer Register 1 */
ADC_DB1R equ 0x53e2
;/* Data Buffer register 1 High */
ADC_DB1RH equ 0x53e2
;/* Data Buffer register 1 Low */
ADC_DB1RL equ 0x53e3

;/* ADC Data buffer Register 2 */
ADC_DB2R equ 0x53e4
;/* Data Buffer register 2 High */
ADC_DB2RH equ 0x53e4
;/* Data Buffer register 2 Low */
ADC_DB2RL equ 0x53e5

;/* ADC Data buffer Register 3 */
ADC_DB3R equ 0x53e6
;/* Data Buffer register 3 High */
ADC_DB3RH equ 0x53e6
;/* Data Buffer register 3 Low */
ADC_DB3RL equ 0x53e7

;/* ADC Data buffer Register 4 */
ADC_DB4R equ 0x53e8
;/* Data Buffer register 4 High */
ADC_DB4RH equ 0x53e8
;/* Data Buffer register 4 Low */
ADC_DB4RL equ 0x53e9

;/* ADC Data buffer Register 5 */
ADC_DB5R equ 0x53ea
;/* Data Buffer register 5 High */
ADC_DB5RH equ 0x53ea
;/* Data Buffer register 5 Low */
ADC_DB5RL equ 0x53eb

;/* ADC Data buffer Register 6 */
ADC_DB6R equ 0x53ec
;/* Data Buffer register 6 High */
ADC_DB6RH equ 0x53ec
;/* Data Buffer register 6 Low */
ADC_DB6RL equ 0x53ed

;/* ADC Data buffer Register 7 */
ADC_DB7R equ 0x53ee
;/* Data Buffer register 7 High */
ADC_DB7RH equ 0x53ee
;/* Data Buffer register 7 Low */
ADC_DB7RL equ 0x53ef

;/* ADC Data buffer Register 8 */
ADC_DB8R equ 0x53f0
;/* Data Buffer register 8 High */
ADC_DB8RH equ 0x53f0
;/* Data Buffer register 8 Low */
ADC_DB8RL equ 0x53f1

;/* ADC Data buffer Register 9 */
ADC_DB9R equ 0x53f2
;/* Data Buffer register 9 High */
ADC_DB9RH equ 0x53f2
;/* Data Buffer register 9 Low */
ADC_DB9RL equ 0x53f3

;/* ADC Control/Status Register */
ADC_CSR equ 0x5400

;/* ADC Configuration Register 1 */
ADC_CR1 equ 0x5401

;/* ADC Configuration Register 2 */
ADC_CR2 equ 0x5402

;/* ADC Configuration Register 3 */
ADC_CR3 equ 0x5403

;/* ADC Data Register */
ADC_DR equ 0x5404
;/* Data bits High */
ADC_DRH equ 0x5404
;/* Data bits Low */
ADC_DRL equ 0x5405

;/* ADC Schmitt Trigger Disable Register */
ADC_TDR equ 0x5406
;/* Schmitt trigger disable High */
ADC_TDRH equ 0x5406
;/* Schmitt trigger disable Low */
ADC_TDRL equ 0x5407

;/* ADC High Threshold Register */
ADC_HTR equ 0x5408
;/* High Threshold Register High */
ADC_HTRH equ 0x5408
;/* High Threshold Register Low */
ADC_HTRL equ 0x5409

;/* ADC Low Threshold Register */
ADC_LTR equ 0x540a
;/* Low Threshold Register High */
ADC_LTRH equ 0x540a
;/* Low Threshold Register Low */
ADC_LTRL equ 0x540b

;/* ADC Analog Watchdog Status Register */
ADC_AWSR equ 0x540c
;/* Analog Watchdog Status register High */
ADC_AWSRH equ 0x540c
;/* Analog Watchdog Status register Low */
ADC_AWSRL equ 0x540d

;/* ADC Analog Watchdog Control Register */
ADC_AWCR equ 0x540e
;/* Analog Watchdog Control register High */
ADC_AWCRH equ 0x540e
;/* Analog Watchdog Control register Low */
ADC_AWCRL equ 0x540f

;/*  Global configuration register (CFG) */
;/*****************************************************************/

;/* CFG Global configuration register */
CFG_GCR equ 0x7f60

;/* Interrupt Software Priority Register (ITC) */
;/*****************************************************************/

;/* Interrupt Software priority register 1 */
ITC_SPR1 equ 0x7f70

;/* Interrupt Software priority register 2 */
ITC_SPR2 equ 0x7f71

;/* Interrupt Software priority register 3 */
ITC_SPR3 equ 0x7f72

;/* Interrupt Software priority register 4 */
ITC_SPR4 equ 0x7f73

;/* Interrupt Software priority register 5 */
ITC_SPR5 equ 0x7f74

;/* Interrupt Software priority register 6 */
ITC_SPR6 equ 0x7f75

;/* Interrupt Software priority register 7 */
ITC_SPR7 equ 0x7f76

;#endif ;/* __STM8S103F__ */
