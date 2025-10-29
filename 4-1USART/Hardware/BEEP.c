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

void BEEP_TOGGLG(void){  
    if(GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_8) == 1){
        // 当前为高电平（蜂鸣器可能不响）→ 输出低电平使其响
        GPIO_ResetBits(GPIOB, GPIO_Pin_8);
    } else {
        // 当前为低电平（蜂鸣器在响）→ 输出高电平使其停止
        GPIO_SetBits(GPIOB, GPIO_Pin_8);
    }
}