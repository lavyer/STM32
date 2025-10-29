#include "BEEP.h"
#include "stm32f10x.h"                  // Device header

void BEEP_Init(void){
	//��ʼ��GPIO����
	GPIO_InitTypeDef GPIO_InitStr;
	
	//ʹ��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	//��ʼ����������
	GPIO_InitStr.GPIO_Pin = GPIO_Pin_8;
	//��������
	GPIO_InitStr.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStr.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStr);
	
	//��ʼ�������رշ�����
	GPIO_ResetBits(GPIOB,GPIO_Pin_8);
	
	

}
