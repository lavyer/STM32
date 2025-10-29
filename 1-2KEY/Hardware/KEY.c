#include "KEY.h"
#include "stm32f10x.h"                  // Device header
#include "delay.h"

void KEY_Init(void){
	//��ʼ��GPIO����
	GPIO_InitTypeDef GPIO_InitStr;
	
	//ʹ��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	
	//��ʼ����������
	GPIO_InitStr.GPIO_Pin = GPIO_Pin_3;
	//��������
	GPIO_InitStr.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStr.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE,&GPIO_InitStr);
	
	GPIO_InitStr.GPIO_Pin = GPIO_Pin_4;
	GPIO_Init(GPIOE,&GPIO_InitStr);
	
}

//������ŵ�ƽ
uint8_t KEY_SCAN(GPIO_TypeDef* GPIOx,uint16_t  GPIO_Pin){
	//����Ƿ��а�������
	if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin)==1){
		delay_ms(20);
		
		return 1;
	
	}else delay_ms(20);return 0;

}