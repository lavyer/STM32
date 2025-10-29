#include "stm32f10x.h"                  // Device header
#include "delay.h"
#include "OLED.h"
#include "LED.h"
#include "EXTI.h"
#include "BEEP.h"
#include "KEY.h"
#include "TIMER.h"


int main(void)
{
	delay_init();
	LED_Init();
	TIMER_Init();
	 while(1)
    {
        // Ω•¡¡
        for(uint16_t i = 0; i <= 1000; i += 10)
        {
            TIM_SetCompare2(TIM3, i);
            delay_ms(5);
        }
        
        // Ω•∞µ
        for(uint16_t i = 1000; i > 0; i -= 10)
        {
            TIM_SetCompare2(TIM3, i);
            delay_ms(5);
        }
    }
	
	
	
	
	
}
