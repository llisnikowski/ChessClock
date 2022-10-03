/*
 * timeWithMilisecounds.cpp
 *
 *  Created on: 4 wrz 2022
 *      Author: Łukasz
 */

#include "countdownTimer.hpp"

#include "main.h"

CountdownTimer::CountdownTimer()
	:time_(), millisecond_(), oldTick_(), play_()
{
}

CountdownTimer::CountdownTimer(const TimeHMS & time)
	:time_(time), millisecond_(), oldTick_(), play_()
{
}


void CountdownTimer::operator =(const TimeHMS & time)
{
	time_ = time;
	millisecond_ = 0;
}

const TimeHMS & CountdownTimer::getTime() const
{
	return time_;
}

TimeHMS & CountdownTimer::getTime()
{
	return time_;
}

int16_t CountdownTimer::getMilliseconds() const
{
	if(!play_) return millisecond_;
	return oneSecound - (HAL_GetTick() - oldTick_);
}

void CountdownTimer::start()
{
	play_ = true;
	oldTick_ = HAL_GetTick() - oneSecound + millisecond_;
}

void CountdownTimer::stop()
{
	if(play_ == false) return;
	play_ = false;
	update();
	millisecond_ = oneSecound - (HAL_GetTick() - oldTick_);
}

uint8_t CountdownTimer::update()
{
	if(play_ == false){
		if(time_ == TimeHMS(0,0,0) && millisecond_ <= 0){
			return timeIsUp;
		}
		return noAction;
	}
	uint32_t tick = HAL_GetTick();
	uint8_t secPas = noAction;
	if(tick - oldTick_ <= oneSecound){
		secPas = secondPassed;
	}
	else if(time_ < TimeHMS{0, 0, 10} && tick - oldTick_ > 30){
		secPas = littleTime;
	}
	while(tick - oldTick_ > oneSecound){
		if(time_ == TimeHMS(0,0,0)){
			play_ = false;
			millisecond_ = 0;
			return timeIsUp;
		}
		else{
			time_.addSeconds(-1);
			oldTick_ += oneSecound;
		}
	}
	if(time_ == TimeHMS(0,0,0) && millisecond_ <= 0){
		return timeIsUp;
	}
	return secPas;
}
