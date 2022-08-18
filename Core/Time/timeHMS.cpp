/*
 * timeHMS.cpp
 *
 *  Created on: 18 sie 2022
 *      Author: Łukasz
 */

#include "timeHMS.hpp"

TimeHMS::TimeHMS()
	:hour_{0}, minute_{0}, second_{0}, crossing_{}
{
}

TimeHMS::TimeHMS(int8_t hour, int8_t minute, int8_t secound)
	:hour_{hour}, minute_{minute}, second_{secound}, crossing_{}
{
	cutTime();
}

TimeHMS::TimeHMS(const TimeHMS & t)
	:hour_{t.hour_}, minute_{t.minute_}, second_{t.second_}, crossing_{}
{
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
	cutTime();
}

void TimeHMS::setMinute(int8_t m)
{
	minute_ = m;
	cutTime();
}

void TimeHMS::setSecond(int8_t s)
{
	second_ = s;
	cutTime();
}

void TimeHMS::setTime(int8_t h, int8_t m,int8_t s)
{
	hour_ = h;
	minute_ = m;
	second_ = s;
	cutTime();
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
		hour_ = 0;
		crossing_ = true;
		return true;
	}
	if(hour_ < 0){
		hour_ = 23;
		crossing_ = true;
		return true;
	}
	return false;
}

void TimeHMS::cutTime()
{
	if(second_ < 0 || second_ >= 60){
		second_ = 0;
	}
	if(minute_ < 0 || minute_ >= 60){
		minute_ = 0;
	}
	if(hour_ < 0 || hour_ >= 24){
		hour_ = 0;
	}
}



void TimeHMS::operator+=(TimeHMS & t)
{
	this->second_ += t.second_;
	this->minute_ += t.minute_;
	this->hour_ += t.hour_;
	correctTime();
}

void TimeHMS::operator-=(TimeHMS & t)
{
	this->second_ -= t.second_;
	this->minute_ -= t.minute_;
	this->hour_ -= t.hour_;
	correctTime();
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




