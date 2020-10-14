#ifndef __MAIN_H
#define __MAIN_H

#include "stm32f1xx.h"

// Define Output Pin for Port A
#define LED_1_Pin GPIO_PIN_9
#define LED_1_GPIO_Port GPIOA
#define LED_2_Pin GPIO_PIN_10
#define LED_2_GPIO_Port GPIOA
#define LED_3_Pin GPIO_PIN_11
#define LED_3_GPIO_Port GPIOA
#define LED_4_Pin GPIO_PIN_12
#define LED_4_GPIO_Port GPIOA

// Define Output Pin for Port B
#define LED_5_Pin GPIO_PIN_5
#define LED_5_GPIO_Port GPIOB
#define LED_6_Pin GPIO_PIN_6
#define LED_6_GPIO_Port GPIOB
#define LED_7_Pin GPIO_PIN_7
#define LED_7_GPIO_Port GPIOB
#define LED_8_Pin GPIO_PIN_8
#define LED_8_GPIO_Port GPIOB
#define LED_9_Pin GPIO_PIN_9
#define LED_9_GPIO_Port GPIOB

// Define Input Pin for Port B
#define Button_1_Pin GPIO_PIN_9
#define Button_1_GPIO_Port GPIOB
#define Button_2_Pin GPIO_PIN_10
#define Button_2_GPIO_Port GPIOB
#define Button_3_Pin GPIO_PIN_11
#define Button_3_GPIO_Port GPIOB
#define Button_4_Pin GPIO_PIN_12
#define Button_4_GPIO_Port GPIOB

void SystemClock_Config(void);
void GPIO_Init(void);

#endif
