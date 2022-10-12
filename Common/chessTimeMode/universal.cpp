/*
 * Universal.cpp
 *
 *  Created on: 1 wrz 2022
 *      Author: Łukasz
 */

#include "universal.hpp"

namespace ChessTimeMode {

Universal::Universal()
	:times_{}, extraTimes_{}, copiedMode_{ModeType::none}
{
}

Universal::~Universal()
{
}


void Universal::operator =(const Normal & mode)
{
	times_[0] = mode.getTime1();
	times_[1] = mode.getTime2();
	copiedMode_ = ModeType::normal;
}

void Universal::operator =(const ExtraTime & mode)
{
	times_[0] = mode.getTime1();
	times_[1] = mode.getTime2();
	extraTimes_[0] = mode.getExtraTime1();
	extraTimes_[1] = mode.getExtraTime2();
	copiedMode_ = ModeType::extraTime;
	addExtraTime(0);
	addExtraTime(1);
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

const CountdownTimer & Universal::getCountdownTimer1() const
{
	return times_[0];
}

const CountdownTimer & Universal::getCountdownTimer2() const
{
	return times_[1];
}

const TimeHMS & Universal::getExtraTime1() const
{
	return extraTimes_[0];
}

const TimeHMS & Universal::getExtraTime2() const
{
	return extraTimes_[1];
}

void Universal::addExtraTime(uint8_t i)
{
	if(i > 1) return;
	TimeHMS currentTime = times_[i].getTime();
	if(currentTime == TimeHMS{0,0,0} && times_[i].getMilliseconds() == 0) return;
	times_[i].setTime(currentTime + extraTimes_[i]);
}



} /* namespace ChessTimeMode */
