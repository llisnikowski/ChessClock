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
		:time{}
	{}
	explicit constexpr Normal(const TimeHMS & t)
		:time{t}
	{}
	virtual ~Normal() = default;

	const TimeHMS & getTime1() const override;
	const TimeHMS & getTime2() const override;

private:
	TimeHMS time;
};



} /* namespace ChessTimeMode */

#endif /* CHESSTIMEMODE_NORMAL_HPP_ */
