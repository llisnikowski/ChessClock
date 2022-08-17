/*
 * Button.h
 *
 *  Created on: Aug 1, 2022
 *      Author: Łukasz
 */

#ifndef BUTTON_BUTTON_HPP_
#define BUTTON_BUTTON_HPP_

#include <stdint.h>
#include "../Inc/gpio.h"

class Button {
public:
	Button(GPIO_TypeDef * port, uint16_t pin);
	virtual ~Button();

	bool risingEdge(bool update=false);
	bool fallingEdge(bool update=false);
	bool pressUp(bool update=false);
	bool pressDown(bool update=false);

	void update();

private:
	GPIO_TypeDef * port_;
	uint16_t pin_;
	bool state_;
};

#endif /* BUTTON_BUTTON_HPP_ */
