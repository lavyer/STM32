#include "stm32f10x.h"                  // Device header
#include "delay.h"
#include "OLED.h"
#include "LED.h"
#include "EXTI.h"
#include "BEEP.h"
#include "KEY.h"

int main(void)
{
    KEY_Init();
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	//设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	LED_Init();
	delay_init();
	BEEP_Init();
	Exti_Init();
	//LED_ON(0);
	//GPIO_SetBits(GPIOB, GPIO_Pin_8);
	while(1){
	delay_ms(100);}
	
}
