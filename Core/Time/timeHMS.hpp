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
	TimeHMS();
	TimeHMS(int8_t hour, int8_t minute, int8_t second);
	TimeHMS(const TimeHMS & t);
	~TimeHMS();

	bool addSeconds(int8_t s);
	bool addMinutes(int8_t m);
	bool addHours(int8_t h);

	void setHour(int8_t h);
	void setMinute(int8_t m);
	void setSecond(int8_t s);
	void setTime(int8_t h, int8_t m,int8_t s);
	int8_t getHour(){return hour_;}
	int8_t getMinute(){return minute_;}
	int8_t getSecond(){return second_;}

	bool zeroCrossing(){return crossing_;}
	void resetCrossing(){crossing_ = false;}

	void operator+=(TimeHMS & t);
	void operator-=(TimeHMS & t);

private:
	bool correctTime();
	void cutTime();

	int8_t hour_;
	int8_t minute_;
	int8_t second_;

	bool crossing_;
};

TimeHMS operator+(TimeHMS & t1, TimeHMS & t2);
TimeHMS operator-(TimeHMS & t1, TimeHMS & t2);


#endif /* TIME_TIMEHMS_HPP_ */
