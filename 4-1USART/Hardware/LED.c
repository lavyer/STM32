#include "stm32f10x.h"                  // Device header
#include "LED.h"

void LED_Init(void){
	//ʹ��ʱ�ӣ�LED0,PB5;LED1,PE5
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	
	//��ʼ��GPIO���Ų���
	GPIO_InitTypeDef GPIO_InitStr;
	GPIO_InitStr.GPIO_Mode = GPIO_Mode_Out_PP;    //�������
	GPIO_InitStr.GPIO_Pin = GPIO_Pin_5;           //PB5����
	GPIO_InitStr.GPIO_Speed = GPIO_Speed_50MHz;   //���Ƶ����50MHz
	
	//��ʼ��
	GPIO_Init(GPIOB,&GPIO_InitStr);
	
	GPIO_InitStr.GPIO_Pin = GPIO_Pin_5; 
	GPIO_Init(GPIOE,&GPIO_InitStr);
	
	//��ʼ��Ϩ��LED0
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
        // ֻ����LED0
        if(GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_5) == 1){
            GPIO_ResetBits(GPIOB, GPIO_Pin_5);
        } else {
            GPIO_SetBits(GPIOB, GPIO_Pin_5);
        }
    }
    else if(led_num == 1){
        // ֻ����LED1
        if(GPIO_ReadOutputDataBit(GPIOE, GPIO_Pin_5) == 1){
            GPIO_ResetBits(GPIOE, GPIO_Pin_5);
        } else {
            GPIO_SetBits(GPIOE, GPIO_Pin_5);
        }
    }
}