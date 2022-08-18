/*
 * diode.cpp
 *
 *  Created on: 18 sie 2022
 *      Author: Łukasz
 */

#include "diode.hpp"

Diode::Diode(GPIO_TypeDef * port, uint16_t pin)
	:port_(port), pin_(pin)
{
}

Diode::~Diode()
{
}


void Diode::toggle()
{
	HAL_GPIO_TogglePin(port_, pin_);
}


void Diode::write(bool on)
{
	HAL_GPIO_WritePin(port_, pin_, static_cast<GPIO_PinState>(on));
}
