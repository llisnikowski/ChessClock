/*
 * timeHMS.cpp
 *
 *  Created on: 18 sie 2022
 *      Author: Łukasz
 */

#include "timeHMS.hpp"

constexpr TimeHMS::TimeHMS()
	:hour_{0}, minute_{0}, second_{0}
{
}

constexpr TimeHMS::TimeHMS(int8_t hour, int8_t minute, int8_t secound)
	:hour_{hour}, minute_{minute}, second_{secound}
{
	correctTime();
}



bool TimeHMS::addSeconds(int8_t s)
{
	second_ += s;
	return correctTime();
}

bool TimeHMS::addMinutes(int8_t m)
{
	minute_ += m;
	return correctTime();
}

bool TimeHMS::addHours(int8_t h)
{
	hour_ += h;
	return correctTime();
}

void TimeHMS::setHour(int8_t h)
{
	hour_ = h;
	correctTime();
}

void TimeHMS::setMinute(int8_t m)
{
	minute_ = m;
	correctTime();
}

void TimeHMS::setSecond(int8_t s)
{
	second_ = s;
	correctTime();
}

void TimeHMS::setTime(int8_t h, int8_t m,int8_t s)
{
	hour_ = h;
	minute_ = m;
	second_ = s;
	correctTime();
}


bool TimeHMS::correctTime()
{
	while(second_ >= 60){
		minute_ ++;
		second_ -= 60;
	}
	while (second_ < 0){
		minute_--;
		second_ += 60;
	}
	while(minute_ >= 60){
		hour_ ++;
		minute_ -= 60;
	}
	while(minute_ < 0){
		hour_--;
		minute_ += 60;
	}
	if(hour_ >= 24){
		hour_ = hour_%24;
		return true;
	}
	else if(hour_ < 0){
		hour_ = 23 + (hour_ + 1) % 24;
		return true;
	}
	return false;
}



bool TimeHMS::operator+=(const TimeHMS & t)
{
	this->second_ += t.second_;
	this->minute_ += t.minute_;
	this->hour_ += t.hour_;
	return correctTime();
}

bool TimeHMS::operator-=(const TimeHMS & t)
{
	this->second_ -= t.second_;
	this->minute_ -= t.minute_;
	this->hour_ -= t.hour_;
	return correctTime();
}




TimeHMS operator+(TimeHMS & t1, TimeHMS & t2)
{
	TimeHMS t = t1;
	t += t2;
	return t;
}

TimeHMS operator-(TimeHMS & t1, TimeHMS & t2)
{
	TimeHMS t = t1;
	t -= t2;
	return t;
}




