/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BUTTON_LEFT_Pin GPIO_PIN_6
#define BUTTON_LEFT_GPIO_Port GPIOA
#define BUTTON_RIGHT_Pin GPIO_PIN_7
#define BUTTON_RIGHT_GPIO_Port GPIOA
#define BUTTON_PLAY_Pin GPIO_PIN_0
#define BUTTON_PLAY_GPIO_Port GPIOB
#define BUTTON_PLAYER2_Pin GPIO_PIN_11
#define BUTTON_PLAYER2_GPIO_Port GPIOA
#define BUTTON_PLAYER1_Pin GPIO_PIN_12
#define BUTTON_PLAYER1_GPIO_Port GPIOA
#define BUTTON_PLUS_Pin GPIO_PIN_15
#define BUTTON_PLUS_GPIO_Port GPIOA
#define BUTTON_MINUS_Pin GPIO_PIN_3
#define BUTTON_MINUS_GPIO_Port GPIOB
#define BUTTON_OPTIONS_Pin GPIO_PIN_4
#define BUTTON_OPTIONS_GPIO_Port GPIOB
#define DIODE_PLAYER2_Pin GPIO_PIN_8
#define DIODE_PLAYER2_GPIO_Port GPIOB
#define DIODE_PLAYER1_Pin GPIO_PIN_9
#define DIODE_PLAYER1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
