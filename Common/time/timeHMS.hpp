/*
 * timeHMS.h
 *
 *  Created on: 18 sie 2022
 *      Author: Łukasz
 */

#ifndef TIME_TIMEHMS_HPP_
#define TIME_TIMEHMS_HPP_

#include <stdint.h>

class TimeHMS {
public:
	constexpr TimeHMS()
		:hour_{0}, minute_{0}, second_{0}
	{}
	constexpr TimeHMS(int8_t hour, int8_t minute, int8_t second)
		:hour_{hour}, minute_{minute}, second_{second}
	{
		correctTime();
	}

	~TimeHMS() = default;

	constexpr bool addSeconds(int8_t s);
	constexpr bool addMinutes(int8_t m);
	constexpr bool addHours(int8_t h);

	constexpr void setHour(int8_t h);
	constexpr void setMinute(int8_t m);
	constexpr void setSecond(int8_t s);
	constexpr void setTime(int8_t h, int8_t m,int8_t s);
	constexpr int8_t getHour() const {return hour_;}
	constexpr int8_t getMinute() const {return minute_;}
	constexpr int8_t getSecond() const {return second_;}

	constexpr bool operator+=(const TimeHMS & t);
	constexpr bool operator-=(const TimeHMS & t);

	constexpr bool operator<(const TimeHMS & t) const;
	constexpr bool operator<=(const TimeHMS & t) const;
	constexpr bool operator>(const TimeHMS & t) const;
	constexpr bool operator>=(const TimeHMS & t) const;
	constexpr bool operator==(const TimeHMS & t) const;
	constexpr bool operator!=(const TimeHMS & t) const;

private:
	constexpr bool correctTime();

	int8_t hour_;
	int8_t minute_;
	int8_t second_;
};



constexpr TimeHMS operator+(const TimeHMS & t1, const TimeHMS & t2);
constexpr TimeHMS operator-(const TimeHMS & t1, const TimeHMS & t2);



//------------------------------------------------------

constexpr bool TimeHMS::addSeconds(int8_t s)
{
	second_ += s;
	return correctTime();
}

constexpr bool TimeHMS::addMinutes(int8_t m)
{
	minute_ += m;
	return correctTime();
}

constexpr bool TimeHMS::addHours(int8_t h)
{
	hour_ += h;
	return correctTime();
}

constexpr void TimeHMS::setHour(int8_t h)
{
	hour_ = h;
	correctTime();
}

constexpr void TimeHMS::setMinute(int8_t m)
{
	minute_ = m;
	correctTime();
}

constexpr void TimeHMS::setSecond(int8_t s)
{
	second_ = s;
	correctTime();
}

constexpr void TimeHMS::setTime(int8_t h, int8_t m,int8_t s)
{
	hour_ = h;
	minute_ = m;
	second_ = s;
	correctTime();
}


constexpr bool TimeHMS::correctTime()
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


constexpr bool TimeHMS::operator+=(const TimeHMS & t)
{
	this->second_ += t.second_;
	this->minute_ += t.minute_;
	this->hour_ += t.hour_;
	return correctTime();
}

constexpr bool TimeHMS::operator-=(const TimeHMS & t)
{
	this->second_ -= t.second_;
	this->minute_ -= t.minute_;
	this->hour_ -= t.hour_;
	return correctTime();
}

constexpr bool TimeHMS::operator<(const TimeHMS & t) const
{
	return this->hour_ < t.hour_
		|| (this->hour_ == t.hour_ && ( this->minute_ < t.minute_
		|| (this->minute_ == t.minute_ && this->second_ < t.second_)));
}
constexpr bool TimeHMS::operator<=(const TimeHMS & t) const
{
	return this->hour_ < t.hour_
		|| (this->hour_ == t.hour_ && ( this->minute_ < t.minute_
		|| (this->minute_ == t.minute_ && this->second_ <= t.second_)));
}
constexpr bool TimeHMS::operator>(const TimeHMS & t) const
{
	return this->hour_ > t.hour_
		|| (this->hour_ == t.hour_ && ( this->minute_ > t.minute_
		|| (this->minute_ == t.minute_ && this->second_ > t.second_)));
}
constexpr bool TimeHMS::operator>=(const TimeHMS & t) const
{
	return this->hour_ > t.hour_
		|| ( this->hour_ == t.hour_ && ( this->minute_ > t.minute_
		|| (this->minute_ == t.minute_ && this->second_ >= t.second_)));
}
constexpr bool TimeHMS::operator==(const TimeHMS & t) const
{
	return this->hour_ == t.hour_
		&& this->minute_ == t.minute_
		&& this->second_ == t.second_;
}
constexpr bool TimeHMS::operator!=(const TimeHMS & t) const
{
	return this->hour_ != t.hour_
		|| this->minute_ != t.minute_
		|| this->second_ != t.second_;
}



//------------------------

constexpr TimeHMS operator+(const TimeHMS & t1, const TimeHMS & t2)
{
	TimeHMS t = t1;
	t += t2;
	return t;
}

constexpr TimeHMS operator-(const TimeHMS & t1, const TimeHMS & t2)
{
	TimeHMS t = t1;
	t -= t2;
	return t;
}



#endif /* TIME_TIMEHMS_HPP_ */
