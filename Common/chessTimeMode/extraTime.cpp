/*
 * extraTime.cpp
 *
 *  Created on: Oct 3, 2022
 *      Author: Łukasz
 */

#include "extraTime.hpp"

namespace ChessTimeMode {



const TimeHMS & ExtraTime::getTime1() const
{
	return time_;
}

const TimeHMS & ExtraTime::getTime2() const
{
	return time_;
}

TimeHMS & ExtraTime::getTime1()
{
	return time_;
}

TimeHMS & ExtraTime::getTime2()
{
	return time_;
}

const TimeHMS & ExtraTime::getExtraTime1() const
{
	return extraTime_;
}

const TimeHMS & ExtraTime::getExtraTime2() const
{
	return extraTime_;
}



} /* namespace ChessTimeMode */
