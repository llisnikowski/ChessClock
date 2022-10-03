/*
 * extraTime.hpp
 *
 *  Created on: Oct 3, 2022
 *      Author: Łukasz
 */

#ifndef CHESSTIMEMODE_EXTRATIME_HPP_
#define CHESSTIMEMODE_EXTRATIME_HPP_


#include "time/timeHMS.hpp"
#include "base.hpp"
#include "modeType.hpp"

namespace ChessTimeMode {

class ExtraTime: public Base
{
public:
	constexpr ExtraTime()
		:time_{}, extraTime_{}
	{}
	explicit constexpr ExtraTime(const TimeHMS & t)
		:time_{t}, extraTime_{}
	{}
	constexpr ExtraTime(const TimeHMS & t, const TimeHMS & extra)
		:time_{t}, extraTime_{extra}
	{}
	virtual ~ExtraTime() = default;

	const ModeType getMenuType() const override {return ModeType::extraTime;}

	const TimeHMS & getTime1() const override;
	const TimeHMS & getTime2() const override;
	TimeHMS & getTime1() override;
	TimeHMS & getTime2() override;

	const TimeHMS & getExtraTime1() const;
	const TimeHMS & getExtraTime2() const;

private:
	TimeHMS time_;
	TimeHMS extraTime_;
};

} /* namespace ChessTimeMode */

#endif /* CHESSTIMEMODE_EXTRATIME_HPP_ */
