/*
 * config.hpp
 *
 *  Created on: 24 sie 2022
 *      Author: Łukasz
 */

#ifndef INC_CONFIG_HPP_
#define INC_CONFIG_HPP_

#include <stdint.h>

enum class SignalId : uint8_t{
	leftButton,
	rightButton,
	playButton ,
	optionButton,
	minusButton,
	plusButton,

	player1Button,
	player2Button
};


#endif /* INC_CONFIG_HPP_ */
