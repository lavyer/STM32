#include "stm32f10x.h"                  // Device header
#include "LED.h"
#include "delay.h"
#include "KEY.h"
#include "BEEP.h"

int main(void)
{
    LED_Init();
	delay_init();
	KEY_Init();
	BEEP_Init();
	//展示按下点亮
	//KEY0 控制LED0，KEY1控制LED1
	while(1){
		if(KEY_SCAN(GPIOE,GPIO_Pin_4)==1){
			delay_ms(20);
			while(KEY_SCAN(GPIOE, GPIO_Pin_4) == 1){
            delay_ms(10);
        }
			GPIO_SetBits(GPIOB,GPIO_Pin_8);
			LED_TOGGLG(0);
			delay_ms(20);
		
		}
		
		if(KEY_SCAN(GPIOE,GPIO_Pin_3)==1){
			delay_ms(20);
			while(KEY_SCAN(GPIOE, GPIO_Pin_3) == 1){
            delay_ms(10);
        }
			GPIO_ResetBits(GPIOB,GPIO_Pin_8);
			LED_TOGGLG(1);
			delay_ms(20);
		
		}
		
	
	}
	
	
}
