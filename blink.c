#include <stdint.h>
#include "reg.h"

/**
 *
 * LED init
 *
 */
void led_init(unsigned int led)
{
	SET_BIT(RCC_BASE + RCC_AHB1ENR_OFFSET, GPIO_EN_BIT(GPIO_PORTD));

	//MODER led pin = 01 => General purpose output mode
	CLEAR_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_MODER_OFFSET, MODERy_1_BIT(led));
	SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_MODER_OFFSET, MODERy_0_BIT(led));

	//OT led pin = 0 => Output push-pull
	CLEAR_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_OTYPER_OFFSET, OTy_BIT(led));

	//OSPEEDR led pin = 00 => Low speed
	CLEAR_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_OSPEEDR_OFFSET, OSPEEDRy_1_BIT(led));
	CLEAR_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_OSPEEDR_OFFSET, OSPEEDRy_0_BIT(led));

	//PUPDR led pin = 00 => No pull-up, pull-down
	CLEAR_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_PUPDR_OFFSET, PUPDRy_1_BIT(led));
	CLEAR_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_PUPDR_OFFSET, PUPDRy_0_BIT(led));
}
/**
 *
 * blink LED forever
 *
 */
void blink(unsigned int led)
{
	led_init(led);

	unsigned int i;

	while (1)
	{
		//set GPIOD led pin
		SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_BSRR_OFFSET, BSy_BIT(led));

		for (i = 0; i < 500000; i++)
			;
		//reset GPIOD led pin
		SET_BIT(GPIO_BASE(GPIO_PORTD) + GPIOx_BSRR_OFFSET, BRy_BIT(led));

		for (i = 0; i < 500000; i++)
			;
	}
}

/**
 *
 * blink LED x count
 *
 */
void blink_count(unsigned int led, unsigned int count)
{
	led_init(led);

	unsigned int i;

	while (count--)
	{
		//set GPIOD led pin
		SET_BIT(GPIO_BASE(GPIO_PORTI) + GPIOx_BSRR_OFFSET, BSy_BIT(led));

		for (i = 0; i < 500000; i++)
			;

		//reset GPIOD led pin
		SET_BIT(GPIO_BASE(GPIO_PORTI) + GPIOx_BSRR_OFFSET, BRy_BIT(led));

		for (i = 0; i < 500000; i++)
			;
	}
}

void button_init(){
	//RCC Enable GPIOA
	SET_BIT(RCC_BASE + RCC_AHB1ENR_OFFSET, GPIO_EN_BIT(GPIO_PORTA));

	//GPIO Configurations
	CLEAR_BIT(GPIO_BASE(GPIO_PORTA) + GPIOx_MODER_OFFSET, MODERy_1_BIT(0));
	CLEAR_BIT(GPIO_BASE(GPIO_PORTA)+ GPIOx_MODER_OFFSET, MODERy_0_BIT(0));
	CLEAR_BIT(GPIO_BASE(GPIO_PORTA)+ GPIOx_PUPDR_OFFSET, PUPDRy_1_BIT(0));
	CLEAR_BIT(GPIO_BASE(GPIO_PORTA)+ GPIOx_PUPDR_OFFSET, PUPDRy_0_BIT(0));

	//RCC Enable SYSCFG
	SET_BIT(SYSCFG_BASE + RCC_APB2ENR_OFFSET, SYSCFGEN_BIT);

	//SYSCFG Configurations
	WRITE_BITS(SYSCFG_BASE + SYSCFG_EXTICR1_OFFSET, EXTI0_3_BIT, EXTI0_0_BIT, 0);

	//EXIT Configurations
	SET_BIT(EXTI_BASE + EXTI_IMR_OFFSET, 0);
	CLEAR_BIT(EXTI_BASE + EXTI_RTSR_OFFSET, 0);
	SET_BIT(EXTI_BASE + EXTI_FTSR_OFFSET, 0);
	SET_BIT(EXTI_BASE + EXTI_PR_OFFSET, 0);

	SET_BIT(NVIC_ISER_BASE + NVIC_ISERn_OFFSET(0), 6); //IRQ6

}
