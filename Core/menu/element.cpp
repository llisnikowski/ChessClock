/*
 * element.cpp
 *
 *  Created on: Aug 17, 2022
 *      Author: Łukasz
 */

#include "element.hpp"

namespace Menu {


Element::Element(const char* name)
	:name_{name}
{
}

Element::~Element()
{
}

const char* Element::getName() const
{
	return name_;
}

void Element::markInList()
{}

void Element::selected()
{}



} /* namespace Menu */
