#include <stm32f446xx.h>
#include <core_cm4.h>
//*** SYSTICK PROGRAM ***//

void SysTickInit()
{
	RCC->AHB1ENR = RCC_AHB1ENR_GPIOAEN;
	__DSB();
	GPIOA->MODER |= GPIO_MODER_MODE6_0 | GPIO_MODER_MODE7_0;
	SysTick_Config(16000000/2);
}

__attribute__((interrupt)) void SysTick_Handler(void)
{
		volatile uint32_t delay;
		GPIOA->ODR ^=GPIO_ODR_OD6;
		for(delay = 1000000; delay; delay--){};
}
//*** SYSTICK PROGRAM END ***//

//*** BUTTON LED PROGRAM ***//
void ButtonInit()
{
    RCC->AHB1ENR = RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOCEN;
	__DSB();
	GPIOA->MODER |= GPIO_MODER_MODE5_0 | GPIO_MODER_MODE5_0;
	GPIOA->MODER &= ~GPIO_MODER_MODE13;
	__DSB();
}

void ButtonLoop()
{
	if(GPIOC->IDR & GPIO_IDR_IDR_13)
	{
		//GPIOA->ODR |= GPIO_ODR_OD5;	//Nie Atomowo
		GPIOA->BSRR = GPIO_BSRR_BR_5;	//BSRR – atomowe kasowanie, ustawianie bitów rejestru GPIO_ODR
	} else {
		//GPIOA->ODR &= ~GPIO_ODR_OD5;
		GPIOA->BSRR = GPIO_BSRR_BS_5;
	}
}
//*** BUTTON LED PROGRAM END ***//

//*** BLINKY LED PROGRAM ***//
void BlinkLEDinit()
{
	RCC->AHB1ENR = RCC_AHB1ENR_GPIOAEN;
	__DSB();
	GPIOA->MODER |= GPIO_MODER_MODE5_0 | GPIO_MODER_MODE6_0 | GPIO_MODER_MODE7_0;
}

void BlinkLED()
{
	volatile uint32_t delay;
	GPIOA->ODR ^= GPIO_ODR_OD5 | GPIO_ODR_OD6;
	for(delay = 1000000; delay; delay--){};
}
//*** BLINKY LED PROGRAM END ***//