/*
 * timeWithMilisecounds.hpp
 *
 *  Created on: 4 wrz 2022
 *      Author: Łukasz
 */

#ifndef TIME_COUNTDOWNTIMER_HPP_
#define TIME_COUNTDOWNTIMER_HPP_

#include "timeHMS.hpp"

class CountdownTimer
{
public:
	static constexpr uint16_t oneSecound = 1000;
	enum{
		noAction,
		secondPassed,
		timeIsUp
	};

	CountdownTimer();
	explicit CountdownTimer(const TimeHMS & time);
	~CountdownTimer() = default;

	void operator =(const TimeHMS & time);

	const TimeHMS & getTime() const;
	TimeHMS & getTime();
	int16_t getMilliseconds() const;

	void start();
	void stop();
	uint8_t update();

private:
	TimeHMS time_;
	int16_t millisecond_;
	uint32_t oldTick_;
	bool play_;
};

#endif /* TIME_COUNTDOWNTIMER_HPP_ */
