/*
 * Universal.cpp
 *
 *  Created on: 1 wrz 2022
 *      Author: Łukasz
 */

#include "universal.hpp"

namespace ChessTimeMode {

Universal::Universal()
	:times_{}
{
}

Universal::~Universal()
{
}


void Universal::operator =(const Normal & mode)
{
	times_[0] = mode.getTime1();
	times_[1] = mode.getTime2();
}


const TimeHMS & Universal::getTime1() const
{
	return times_[0].getTime();
}

const TimeHMS & Universal::getTime2() const
{
	return times_[1].getTime();
}

TimeHMS & Universal::getTime1()
{
	return times_[0].getTime();
}

TimeHMS & Universal::getTime2()
{
	return times_[1].getTime();
}

CountdownTimer & Universal::getCountdownTimer1()
{
	return times_[0];
}

CountdownTimer & Universal::getCountdownTimer2()
{
	return times_[1];
}






} /* namespace ChessTimeMode */
