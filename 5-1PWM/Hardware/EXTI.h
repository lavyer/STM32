#ifndef __EXTI_H
#define __EXTI_H

void Exti_Init(void);

//KEY-UP���Ʒ�����
void EXTI0_IRQHandler();

//KEY1����LED1
void EXTI3_IRQHandler();

//KEY0����LED0
void EXTI4_IRQHandler();


#endif