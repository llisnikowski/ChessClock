/*
 * uartLog.h
 *
 *  Created on: Jul 26, 2022
 *      Author: Łukasz
 */

#ifndef UARTLOG_UARTLOG_H_
#define UARTLOG_UARTLOG_H_

#include <stdio.h>
#include "usart.h"

extern UART_HandleTypeDef *uartLog;


#ifdef __cplusplus
extern "C" {
#endif


int __io_putchar(int ch);



#ifdef __cplusplus
}
#endif

#endif /* UARTLOG_UARTLOG_H_ */
