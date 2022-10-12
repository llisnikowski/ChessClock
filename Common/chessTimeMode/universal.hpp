/*
 * Universal.h
 *
 *  Created on: 1 wrz 2022
 *      Author: Łukasz
 */

#ifndef CHESSTIMEMODE_UNIVERSAL_HPP_
#define CHESSTIMEMODE_UNIVERSAL_HPP_

#include "base.hpp"
#include "normal.hpp"
#include "extraTime.hpp"
#include "time/timeHMS.hpp"
#include "time/countdownTimer.hpp"
#include "modeType.hpp"

namespace ChessTimeMode {

class Universal : public Base
{
public:
	Universal();
	virtual ~Universal();

	void operator =(const Normal & mode);
	void operator =(const ExtraTime & mode);

	const ModeType getMenuType() const override {return ModeType::universal;}

	const TimeHMS & getTime1() const override;
	const TimeHMS & getTime2() const override;
	TimeHMS & getTime1() override;
	TimeHMS & getTime2() override;

	CountdownTimer & getCountdownTimer1();
	CountdownTimer & getCountdownTimer2();
	const CountdownTimer & getCountdownTimer1() const;
	const CountdownTimer & getCountdownTimer2() const;

	ModeType getCopiedMode() const {return copiedMode_;}
	const TimeHMS & getExtraTime1() const;
	const TimeHMS & getExtraTime2() const;

	void addExtraTime(uint8_t i);

private:
	CountdownTimer times_[2];
	TimeHMS extraTimes_[2];

	ModeType copiedMode_;
};

} /* namespace ChessTimeMode */

#endif /* CHESSTIMEMODE_UNIVERSAL_HPP_ */
