/*
 * Button.cpp
 *
 *  Created on: Aug 1, 2022
 *      Author: Łukasz
 */

#include "button.hpp"
#include "gpio.h"

Button::Button(GPIO_TypeDef * port, uint16_t pin)
	:port_(port), pin_(pin)
{
}

Button::~Button()
{
}

bool Button::risingEdge(bool update)
{
	bool currentState = static_cast<bool>(HAL_GPIO_ReadPin(port_, pin_));
	bool ret = currentState && !state_;
	if(update) state_ = currentState;
	return ret;
}

bool Button::fallingEdge(bool update)
{
	bool currentState = static_cast<bool>(HAL_GPIO_ReadPin(port_, pin_));
	bool ret = !currentState && state_;
	if(update) state_ = currentState;
	return ret;
}

bool Button::pressUp(bool update)
{
	bool currentState = static_cast<bool>(HAL_GPIO_ReadPin(port_, pin_));
	if(update) state_ = currentState;
	return currentState;
}

bool Button::pressDown(bool update)
{
	bool currentState = static_cast<bool>(HAL_GPIO_ReadPin(port_, pin_));
	if(update) state_ = currentState;
	return !currentState;
}

void Button::update()
{
	state_ = static_cast<bool>(HAL_GPIO_ReadPin(port_, pin_));
}
