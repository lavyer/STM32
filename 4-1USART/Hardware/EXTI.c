#include "stm32f10x.h"                  // Device header
#include "EXTI.h"
#include "KEY.h"
#include "BEEP.h"
#include "LED.h"
#include "delay.h"

void Exti_Init(void){
	//GPIO的输入模式才能触发中断
	//初始化IO输入
	KEY_Init();
	
	//使能AFIO时钟，进行引脚复用
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	//初始化EXTI中断
	EXTI_InitTypeDef EXTI_InitStr;
	NVIC_InitTypeDef NVIC_InitStr;
	
	//配置GPIO和中断线的映射关系
	//GPIO_EXTILineConfig(GPIO_PortSourceGPIOA | GPIO_PortSourceGPIOE,GPIO_PinSource0|GPIO_PinSource3 |GPIO_PinSource4);
	
	//进行中断参数属性配置
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);
	EXTI_InitStr.EXTI_Line=EXTI_Line0;
	EXTI_InitStr.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStr.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_Init(&EXTI_InitStr);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource3);
	EXTI_InitStr.EXTI_Line=EXTI_Line3;
	EXTI_InitStr.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStr.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitStr);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource4);
	EXTI_InitStr.EXTI_Line=EXTI_Line4;
	EXTI_InitStr.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStr.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitStr);
	
	//NVIC配置
	NVIC_InitStr.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStr.NVIC_IRQChannelPreemptionPriority = 0x02;
	NVIC_InitStr.NVIC_IRQChannelSubPriority = 0x03;
	NVIC_InitStr.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStr);
	
	NVIC_InitStr.NVIC_IRQChannel = EXTI3_IRQn;
	NVIC_InitStr.NVIC_IRQChannelPreemptionPriority = 0x03;
	NVIC_InitStr.NVIC_IRQChannelSubPriority = 0x02;
	NVIC_InitStr.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStr);
	
	NVIC_InitStr.NVIC_IRQChannel = EXTI4_IRQn;
	NVIC_InitStr.NVIC_IRQChannelPreemptionPriority = 0x02;
	NVIC_InitStr.NVIC_IRQChannelSubPriority = 0x00;
	NVIC_InitStr.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStr);

}

// KEY-UP控制蜂鸣器
void EXTI0_IRQHandler(){
    if(EXTI_GetITStatus(EXTI_Line0) != RESET){
        delay_ms(20);
        
        // 等待按键释放
        while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 1) {
            delay_ms(10);
        }
        
        //BEEP_TOGGLG();
		LED_TOGGLG(1);
		LED_TOGGLG(0);
        EXTI_ClearITPendingBit(EXTI_Line0);
    }
}

//KEY1控制LED1
void EXTI3_IRQHandler(){
	if(EXTI_GetITStatus(EXTI_Line3) != RESET){
		
			delay_ms(20);
			LED_TOGGLG(1);
			//清除中断标志位
			EXTI_ClearITPendingBit(EXTI_Line3);
	}
}

//KEY0控制LED0
void EXTI4_IRQHandler(){
	if(EXTI_GetITStatus(EXTI_Line4) != RESET){
		
			delay_ms(20);
			LED_TOGGLG(0);
			//清除中断标志位
			EXTI_ClearITPendingBit(EXTI_Line4);;
	}
}