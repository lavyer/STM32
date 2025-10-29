#include "BEEP.h"
#include "stm32f10x.h"                  // Device header

void BEEP_Init(void){
	//初始化GPIO按键
	GPIO_InitTypeDef GPIO_InitStr;
	
	//使能时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	//初始化按键参数
	GPIO_InitStr.GPIO_Pin = GPIO_Pin_8;
	//上拉输入
	GPIO_InitStr.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStr.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStr);
	
	//初始操作，关闭蜂鸣器
	GPIO_ResetBits(GPIOB,GPIO_Pin_8);
	
	

}
