#include "stm32f10x.h"                  // Device header
#include "TIMER.h"

void TIMER_Init(void){
	//开启TIM3时钟及复用时钟，配置PB5为复用输出，因为TIM3_CH2通道映射到PB5
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	//进行GPIO初始化
	GPIO_InitTypeDef GPIO_InitStr;
	GPIO_InitStr.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStr.GPIO_Pin  = GPIO_Pin_5;
	GPIO_InitStr.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStr);

	//设置TIM3_CH2重映射到PB5上
	GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3,ENABLE);
	
	//初始化TIM3,设置TIM3的ARR和PSC
	TIM_TimeBaseInitTypeDef TIM_InitStr;
	TIM_OCInitTypeDef TIM_OCInitStr;
	TIM_InitStr.TIM_Period = 10000 - 1; //设置自动重装载值
	TIM_InitStr.TIM_Prescaler = 72 - 1; //设置预分频值
	TIM_InitStr.TIM_ClockDivision = 0; //时钟分割
	TIM_InitStr.TIM_CounterMode = TIM_CounterMode_Up; //向上计数
	TIM_TimeBaseInit(TIM3,&TIM_InitStr);
	
	//设置TIM3_CH2的PWM模式，使能TIM3的CH2输出
	TIM_OCStructInit(&TIM_OCInitStr);  // 先用默认值初始化
    
    TIM_OCInitStr.TIM_OCMode = TIM_OCMode_PWM1;        // PWM模式1
    TIM_OCInitStr.TIM_OutputState = TIM_OutputState_Enable;  // 使能输出
    TIM_OCInitStr.TIM_OCPolarity = TIM_OCPolarity_Low;      // 输出极性低
    TIM_OCInitStr.TIM_Pulse = 500;                          // 初始占空比
	TIM_OC2Init(TIM3,&TIM_OCInitStr);
	
	//使能TIM3
	TIM_Cmd(TIM3,ENABLE);
	
	
	//修改TIM3_CH2来控制占空比
	TIM_SetCompare2(TIM3, 500);  // 设置CCR2寄存器值为500
}



