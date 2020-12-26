#include <stm32f446xx.h>
#include <FreeRTOSConfig.h>
#include <header.h>
#include <functions.h>
#include <atomic>
#define SysTick_Handler

int main(){
	
	//SysTickInit();

	while(1);
}
/*
	__attribute__((interrupt)) void SysTick_Handler(void){
		volatile uint32_t delay;
		GPIOA->ODR ^=GPIO_ODR_OD6;
		for(delay = 1000000; delay; delay--){};
}*/