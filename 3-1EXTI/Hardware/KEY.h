#ifndef __KEY_H
#define __KEY_H
#include "stm32f10x.h"                  // Device header


void KEY_Init(void);
uint8_t KEY_SCAN(GPIO_TypeDef* GPIOx,uint16_t  GPIO_Pin);



#endif