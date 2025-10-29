#ifndef __EXTI_H
#define __EXTI_H

void Exti_Init(void);

//KEY-UP¿ØÖÆ·äÃùÆ÷
void EXTI0_IRQHandler();

//KEY1¿ØÖÆLED1
void EXTI3_IRQHandler();

//KEY0¿ØÖÆLED0
void EXTI4_IRQHandler();


#endif