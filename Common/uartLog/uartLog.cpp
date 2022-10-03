/*
 * uartLog.cpp
 *
 *  Created on: Jul 26, 2022
 *      Author: Łukasz
 */

#include "uartLog.h"

#include <stdio.h>

UART_HandleTypeDef *uartLog = &huart2;

#ifdef __cplusplus
extern "C" {
#endif


int __io_putchar(int ch)
{
  if (ch == '\n') {
    __io_putchar('\r');
  }

  HAL_UART_Transmit(uartLog, (uint8_t*)&ch, 1, HAL_MAX_DELAY);

  return 1;
}


#ifdef __cplusplus
}
#endif
