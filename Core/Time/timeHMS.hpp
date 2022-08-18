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
	constexpr TimeHMS();
	constexpr TimeHMS(int8_t hour, int8_t minute, int8_t second);
	~TimeHMS() = default;

	bool addSeconds(int8_t s);
	bool addMinutes(int8_t m);
	bool addHours(int8_t h);

	void setHour(int8_t h);
	void setMinute(int8_t m);
	void setSecond(int8_t s);
	void setTime(int8_t h, int8_t m,int8_t s);
	constexpr int8_t getHour() const {return hour_;}
	constexpr int8_t getMinute() const {return minute_;}
	constexpr int8_t getSecond() const {return second_;}

	bool operator+=(const TimeHMS & t);
	bool operator-=(const TimeHMS & t);

private:
	bool correctTime();

	int8_t hour_;
	int8_t minute_;
	int8_t second_;
};

TimeHMS operator+(TimeHMS & t1, TimeHMS & t2);
TimeHMS operator-(TimeHMS & t1, TimeHMS & t2);


#endif /* TIME_TIMEHMS_HPP_ */
