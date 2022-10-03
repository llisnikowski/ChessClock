/*
 * modeType.hpp
 *
 *  Created on: Sep 3, 2022
 *      Author: Łukasz
 */

#ifndef CHESSTIMEMODE_MODETYPE_HPP_
#define CHESSTIMEMODE_MODETYPE_HPP_

#include <stdint.h>

enum class ModeType : uint8_t
{
	base,
	normal,
	extraTime,
	universal,
};


#endif /* CHESSTIMEMODE_MODETYPE_HPP_ */
