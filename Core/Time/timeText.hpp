/*
 * TimeText.h
 *
 *  Created on: 1 wrz 2022
 *      Author: Łukasz
 */

#ifndef TIME_TIMETEXT_HPP_
#define TIME_TIMETEXT_HPP_

#include <stdint.h>
#include "timeHMS.hpp"

class TimeText {
	static constexpr uint8_t TIME_TEXT_SIZE = 6;
public:
	TimeText();
	explicit constexpr TimeText(const TimeHMS & time)
		:timeText_{}
	{
		operator=(time);
	}
	~TimeText();

	constexpr void operator=(const TimeHMS & time);
	constexpr const char * operator()(){return timeText_;}

	constexpr const char * getText() const {return timeText_;}
	constexpr const uint8_t getLength() const;

private:
	char timeText_[TIME_TEXT_SIZE];
};



constexpr void TimeText::operator=(const TimeHMS & time)
{
	for(int i = 0; i < TIME_TEXT_SIZE; i++) timeText_[i] = 0;
	char * timeTextPointer = timeText_;
	if(time >= TimeHMS{1,0,0}){
		int8_t timeElement = time.getHour();
		if(timeElement >= 10){
			*timeTextPointer++ = timeElement/10 + '0';
		}
		*timeTextPointer++ = timeElement%10 + '0';
		*timeTextPointer++ = ':';

		timeElement = time.getMinute();
		*timeTextPointer++ = timeElement/10 + '0';
		*timeTextPointer++ = timeElement%10 + '0';
	}
	else{
		int8_t timeElement = time.getMinute();
		if(timeElement >= 10){
			*timeTextPointer++ = timeElement/10 + '0';
		}
		*timeTextPointer++ = timeElement%10 + '0';
		*timeTextPointer++ = '.';

		timeElement = time.getSecond();
		*timeTextPointer++ = timeElement/10 + '0';
		*timeTextPointer++ = timeElement%10 + '0';
	}
}

constexpr const uint8_t TimeText::getLength() const
{
	uint8_t i = 0;
	for(; i < TIME_TEXT_SIZE; i++){
		if(timeText_[i] == 0)
		{
			return i;
		}
	}
	return i;
}

#endif /* TIME_TIMETEXT_HPP_ */
