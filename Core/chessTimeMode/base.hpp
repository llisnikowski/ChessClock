/*
 * Base.h
 *
 *  Created on: 18 sie 2022
 *      Author: Łukasz
 */

#ifndef CHESSTIMEMODE_BASE_HPP_
#define CHESSTIMEMODE_BASE_HPP_

#include "../time/timeHMS.hpp"


namespace ChessTimeMode {

class Base
{
public:
	constexpr Base()
	{
	}

	virtual ~Base();

	virtual const TimeHMS & getTime1() const = 0;
	virtual const TimeHMS & getTime2() const = 0;

private:
};



} /* namespace ChessTimeMode */

#endif /* CHESSTIMEMODE_BASE_HPP_ */
