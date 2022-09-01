/*
 * timeModeElement.h
 *
 *  Created on: 20 sie 2022
 *      Author: Łukasz
 */

#ifndef CHESSMENU_TIMEMODEELEMENT_HPP_
#define CHESSMENU_TIMEMODEELEMENT_HPP_

#include "../menu/element.hpp"
#include "../chessTimeMode/base.hpp"
#include "menuType.hpp"



class TimeModeElement: public Menu::Element
{
public:
	using CTMode = ChessTimeMode::Base;

	TimeModeElement(const char* name, CTMode & mode);
	virtual ~TimeModeElement();

	const CTMode * getMode() const;

	MenuType getMenuType() override {return MenuType::timeModeElement;}

private:
	CTMode & mode_;
};

#endif /* CHESSMENU_TIMEMODEELEMENT_HPP_ */
