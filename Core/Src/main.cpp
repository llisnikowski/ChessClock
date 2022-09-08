/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "config.hpp"

#include "../uartLog/uartLog.h"
#include "../button/button.hpp"
#include "../diode/diode.hpp"
#include "../ssd1306/oledDisplay.h"
#include "../displayManager/displayManager.hpp"
#include "../menuGenerator/menuGenerator.hpp"
#include "../menuManager/menuManager.hpp"
#include "../menu/gameManager.hpp"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

Button bLeft{BUTTON_LEFT_GPIO_Port, BUTTON_LEFT_Pin};
Button bRight{BUTTON_RIGHT_GPIO_Port, BUTTON_RIGHT_Pin};
Button bPlay{BUTTON_PLAY_GPIO_Port, BUTTON_PLAY_Pin};
Button bOptions{BUTTON_OPTIONS_GPIO_Port, BUTTON_OPTIONS_Pin};
Button bPlus{BUTTON_PLUS_GPIO_Port, BUTTON_PLUS_Pin};
Button bMinus{BUTTON_MINUS_GPIO_Port, BUTTON_MINUS_Pin};
Button bPlayer1{BUTTON_PLAYER1_GPIO_Port, BUTTON_PLAYER1_Pin};
Button bPlayer2{BUTTON_PLAYER2_GPIO_Port, BUTTON_PLAYER2_Pin};

Diode dPlayer1{DIODE_PLAYER1_GPIO_Port, DIODE_PLAYER1_Pin};
Diode dPlayer2{DIODE_PLAYER2_GPIO_Port, DIODE_PLAYER2_Pin};

MenuGenerator menuGenerator;

OledDisplay display1(&hi2c1, 128, 32);
OledDisplay display2(&hi2c2, 128, 32);

DisplayManager displayManager(display1, display2);

MenuManager menuManager;

GameManager gameManager;


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */


  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_I2C1_Init();
  MX_USART2_UART_Init();
  MX_I2C2_Init();
  MX_TIM4_Init();
  /* USER CODE BEGIN 2 */

  HAL_Delay(100);
  menuGenerator.link();

  display1.init(0x78);
  display2.init(0x78);
  display1.drawPixel(1, 1);
  display1.display();
  display2.drawPixel(1, 1);
  display2.display();

  gameManager.setDiodes(&dPlayer1, &dPlayer2);

  menuManager.begin(&displayManager, menuGenerator.getMainList(), &gameManager);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  for(int i = 0; i<10; i++){
	  dPlayer1.toggle();
	  dPlayer2.toggle();
	  HAL_Delay(50);
  }



  while (1)
  {
	  if(bLeft.fallingEdge(true))
		  menuManager.sendImpulse(static_cast<uint16_t>(SignalId::leftButton));
	  if(bRight.fallingEdge(true))
		  menuManager.sendImpulse(static_cast<uint16_t>(SignalId::rightButton));
	  if(bPlay.fallingEdge(true))
		  menuManager.sendImpulse(static_cast<uint16_t>(SignalId::playButton));
	  if(bOptions.fallingEdge(true))
		  menuManager.sendImpulse(static_cast<uint16_t>(SignalId::optionButton));
	  if(bMinus.fallingEdge(true))
		  menuManager.sendImpulse(static_cast<uint16_t>(SignalId::minusButton));
	  if(bPlus.fallingEdge(true))
		  menuManager.sendImpulse(static_cast<uint16_t>(SignalId::plusButton));

	  if(bPlayer1.fallingEdge(true))
		  menuManager.sendImpulse(static_cast<uint16_t>(SignalId::player1Button));
	  if(bPlayer2.fallingEdge(true))
		  menuManager.sendImpulse(static_cast<uint16_t>(SignalId::player2Button));

	  menuManager.update();

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  HAL_Delay(20);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL8;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
