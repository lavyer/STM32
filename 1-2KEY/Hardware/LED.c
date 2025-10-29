#include "stm32f10x.h"                  // Device header
#include "LED.h"

void LED_Init(void){
	//使能时钟，LED0,PB5;LED1,PE5
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	
	//初始化GPIO引脚参数
	GPIO_InitTypeDef GPIO_InitStr;
	GPIO_InitStr.GPIO_Mode = GPIO_Mode_Out_PP;    //推挽输出
	GPIO_InitStr.GPIO_Pin = GPIO_Pin_5;           //PB5引脚
	GPIO_InitStr.GPIO_Speed = GPIO_Speed_50MHz;   //输出频率是50MHz
	
	//初始化
	GPIO_Init(GPIOB,&GPIO_InitStr);
	
	GPIO_InitStr.GPIO_Pin = GPIO_Pin_5; 
	GPIO_Init(GPIOE,&GPIO_InitStr);
	
	//初始化熄灭LED0
	GPIO_SetBits(GPIOB,GPIO_Pin_5);
	GPIO_SetBits(GPIOE,GPIO_Pin_5);
}

void LED_ON(uint8_t num){
	if(num==1){
	GPIO_ResetBits(GPIOE,GPIO_Pin_5);
	}else GPIO_ResetBits(GPIOB,GPIO_Pin_5);
}

void LED_DOWN(uint8_t num){
	if(num==1){
	GPIO_SetBits(GPIOE,GPIO_Pin_5);
	}else GPIO_SetBits(GPIOB,GPIO_Pin_5);
}

void LED_TOGGLG(uint8_t led_num){  
    if(led_num == 0){
        // 只控制LED0
        if(GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_5) == 1){
            GPIO_ResetBits(GPIOB, GPIO_Pin_5);
        } else {
            GPIO_SetBits(GPIOB, GPIO_Pin_5);
        }
    }
    else if(led_num == 1){
        // 只控制LED1
        if(GPIO_ReadOutputDataBit(GPIOE, GPIO_Pin_5) == 1){
            GPIO_ResetBits(GPIOE, GPIO_Pin_5);
        } else {
            GPIO_SetBits(GPIOE, GPIO_Pin_5);
        }
    }
}