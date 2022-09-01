/*
 * normal.h
 *
 *  Created on: 19 sie 2022
 *      Author: Łukasz
 */

#ifndef CHESSTIMEMODE_NORMAL_HPP_
#define CHESSTIMEMODE_NORMAL_HPP_

#include "../time/timeHMS.hpp"
#include "base.hpp"

namespace ChessTimeMode {

class Normal : public Base
{
public:
	constexpr Normal()
		:time_{}
	{}
	explicit constexpr Normal(const TimeHMS & t)
		:time_{t}
	{}
	virtual ~Normal() = default;

	const TimeHMS & getTime1() const override;
	const TimeHMS & getTime2() const override;
	TimeHMS & getTime1() override;
	TimeHMS & getTime2() override;

private:
	TimeHMS time_;
};



} /* namespace ChessTimeMode */

#endif /* CHESSTIMEMODE_NORMAL_HPP_ */
