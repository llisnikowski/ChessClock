/*
 * TimeText.cpp
 *
 *  Created on: 1 wrz 2022
 *      Author: Łukasz
 */

#include "timeText.hpp"



TimeText::TimeText()
	:timeText_{}
{
}

TimeText::TimeText(const CountdownTimer & countdownTimer)
	:timeText_{}
{
	operator=(countdownTimer);
}


TimeText::~TimeText()
{
}

void TimeText::operator=(const CountdownTimer & countdownTimer)
{
	const TimeHMS time = countdownTimer.getTime();
	if(time >= TimeHMS{0,0,10}){
		operator=(time);
	}
	else{
		char * timeTextPointer = timeText_;
		for(int i = 0; i < TIME_TEXT_SIZE; i++) timeText_[i] = 0;
		int16_t timeElement = time.getSecond();
		*timeTextPointer++ = timeElement%10 + '0';
		*timeTextPointer++ = '.';

		timeElement = countdownTimer.getMilliseconds();
		*timeTextPointer++ = (timeElement%1000)/100 + '0';
		*timeTextPointer++ = (timeElement%100)/10 + '0';
	}
}

