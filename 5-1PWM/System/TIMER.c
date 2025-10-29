#include "stm32f10x.h"                  // Device header
#include "TIMER.h"

void TIMER_Init(void){
	//����TIM3ʱ�Ӽ�����ʱ�ӣ�����PB5Ϊ�����������ΪTIM3_CH2ͨ��ӳ�䵽PB5
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	//����GPIO��ʼ��
	GPIO_InitTypeDef GPIO_InitStr;
	GPIO_InitStr.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStr.GPIO_Pin  = GPIO_Pin_5;
	GPIO_InitStr.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStr);

	//����TIM3_CH2��ӳ�䵽PB5��
	GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3,ENABLE);
	
	//��ʼ��TIM3,����TIM3��ARR��PSC
	TIM_TimeBaseInitTypeDef TIM_InitStr;
	TIM_OCInitTypeDef TIM_OCInitStr;
	TIM_InitStr.TIM_Period = 10000 - 1; //�����Զ���װ��ֵ
	TIM_InitStr.TIM_Prescaler = 72 - 1; //����Ԥ��Ƶֵ
	TIM_InitStr.TIM_ClockDivision = 0; //ʱ�ӷָ�
	TIM_InitStr.TIM_CounterMode = TIM_CounterMode_Up; //���ϼ���
	TIM_TimeBaseInit(TIM3,&TIM_InitStr);
	
	//����TIM3_CH2��PWMģʽ��ʹ��TIM3��CH2���
	TIM_OCStructInit(&TIM_OCInitStr);  // ����Ĭ��ֵ��ʼ��
    
    TIM_OCInitStr.TIM_OCMode = TIM_OCMode_PWM1;        // PWMģʽ1
    TIM_OCInitStr.TIM_OutputState = TIM_OutputState_Enable;  // ʹ�����
    TIM_OCInitStr.TIM_OCPolarity = TIM_OCPolarity_Low;      // ������Ե�
    TIM_OCInitStr.TIM_Pulse = 500;                          // ��ʼռ�ձ�
	TIM_OC2Init(TIM3,&TIM_OCInitStr);
	
	//ʹ��TIM3
	TIM_Cmd(TIM3,ENABLE);
	
	
	//�޸�TIM3_CH2������ռ�ձ�
	TIM_SetCompare2(TIM3, 500);  // ����CCR2�Ĵ���ֵΪ500
}



