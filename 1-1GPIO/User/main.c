#include "stm32f10x.h"                  // Device header
#include "LED.h"
#include "delay.h"

int main(void)
{
    LED_Init();
	delay_init();
	//展示循环亮灭效果
	while(1){
		LED_ON(0);
		delay_ms(200);
		LED_DOWN(0);
		LED_ON(1);
		delay_ms(200);
		LED_DOWN(1);
	}
	
	
}
