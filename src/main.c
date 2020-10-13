
#include "stm32f1xx.h"

#define LED_1_Pin GPIO_PIN_9
#define LED_1_GPIO_Port GPIOA
#define LED_2_Pin GPIO_PIN_10
#define LED_2_GPIO_Port GPIOA
#define LED_3_Pin GPIO_PIN_11
#define LED_3_GPIO_Port GPIOA
#define LED_4_Pin GPIO_PIN_12
#define LED_4_GPIO_Port GPIOA
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

void SystemClock_Config(void);
void GPIO_Init(void);

int main(void)
{
	HAL_Init();
	SystemClock_Config();
	GPIO_Init();

	while (1) {
	  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
	  HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin);
	  HAL_GPIO_TogglePin(LED_2_GPIO_Port, LED_2_Pin);
	  HAL_GPIO_TogglePin(LED_3_GPIO_Port, LED_3_Pin);
	  HAL_GPIO_TogglePin(LED_4_GPIO_Port, LED_4_Pin);
	  HAL_GPIO_TogglePin(LED_5_GPIO_Port, LED_5_Pin);
	  HAL_GPIO_TogglePin(LED_6_GPIO_Port, LED_6_Pin);
	  HAL_GPIO_TogglePin(LED_7_GPIO_Port, LED_7_Pin);
	  HAL_GPIO_TogglePin(LED_8_GPIO_Port, LED_8_Pin);
	  HAL_GPIO_TogglePin(LED_9_GPIO_Port, LED_9_Pin);
	  HAL_Delay(500);
	}

}

void SystemClock_Config(void)
{

	RCC_ClkInitTypeDef clkinitstruct = {0};
	RCC_OscInitTypeDef oscinitstruct = {0};

	oscinitstruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	oscinitstruct.HSEState = RCC_HSE_ON;
	oscinitstruct.HSIState = RCC_HSI_OFF;
	oscinitstruct.PLL.PLLState = RCC_PLL_ON;
	oscinitstruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	oscinitstruct.PLL.PLLMUL = RCC_PLL_MUL9;
	if(HAL_RCC_OscConfig(&oscinitstruct)!= HAL_OK)
	{
		while(1);
	}

	clkinitstruct.ClockType = (RCC_CLOCKTYPE_SYSCLK |
			RCC_CLOCKTYPE_HCLK |
			RCC_CLOCKTYPE_PCLK1 |
			RCC_CLOCKTYPE_PCLK2);
	clkinitstruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	clkinitstruct.AHBCLKDivider = RCC_HCLK_DIV1;
	clkinitstruct.APB1CLKDivider = RCC_HCLK_DIV2;
	if (HAL_RCC_ClockConfig(&clkinitstruct, FLASH_LATENCY_2)!= HAL_OK)
	{
	  while(1);
	}
}

void GPIO_Init(void)
{  GPIO_InitTypeDef GPIO_InitStruct = {0};

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOA, LED_1_Pin|LED_2_Pin|LED_3_Pin|LED_4_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOB, LED_5_Pin|LED_6_Pin|LED_7_Pin|LED_8_Pin
                        |LED_9_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin : PC13 */
	GPIO_InitStruct.Pin = GPIO_PIN_13;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	/*Configure GPIO pins : LED_1_Pin LED_2_Pin LED_3_Pin LED_4_Pin */
	GPIO_InitStruct.Pin = LED_1_Pin|LED_2_Pin|LED_3_Pin|LED_4_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/*Configure GPIO pins : LED_5_Pin LED_6_Pin LED_7_Pin LED_9_Pin
                         LED_10_Pin */
	GPIO_InitStruct.Pin = LED_5_Pin|LED_6_Pin|LED_7_Pin|LED_8_Pin
                        |LED_9_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}
