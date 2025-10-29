#include "KEY.h"
#include "stm32f10x.h"                  // Device header
#include "delay.h"

void KEY_Init(void){
	//初始化GPIO按键
	GPIO_InitTypeDef GPIO_InitStr;
	
	//使能时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	
	//初始化按键参数
	GPIO_InitStr.GPIO_Pin = GPIO_Pin_3;
	//上拉输入
	GPIO_InitStr.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStr.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE,&GPIO_InitStr);
	
	GPIO_InitStr.GPIO_Pin = GPIO_Pin_4;
	GPIO_Init(GPIOE,&GPIO_InitStr);
	
}

//检测引脚电平
uint8_t KEY_SCAN(GPIO_TypeDef* GPIOx,uint16_t  GPIO_Pin){
	//检测是否有按键落下
	if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin)==1){
		delay_ms(20);
		
		return 1;
	
	}else delay_ms(20);return 0;

}