/*
 * diode.hpp
 *
 *  Created on: 18 sie 2022
 *      Author: Łukasz
 */

#ifndef DIODE_DIODE_HPP_
#define DIODE_DIODE_HPP_

#include <stdint.h>
#include "../Inc/gpio.h"

class Diode {
public:
	Diode(GPIO_TypeDef * port, uint16_t pin);
	~Diode();

	void toggle();
	void write(bool on);

private:
	GPIO_TypeDef * port_;
	uint16_t pin_;
};

#endif /* DIODE_DIODE_HPP_ */
