/*
 * timeModeElement.cpp
 *
 *  Created on: 20 sie 2022
 *      Author: Łukasz
 */

#include "timeModeElement.hpp"

TimeModeElement::TimeModeElement(const char * name, CTMode & mode)
	: Menu::Element{name}, mode_{mode}
{
}

TimeModeElement::~TimeModeElement()
{
}

auto TimeModeElement::getMode() const -> const CTMode *
{
	return &mode_;
}
