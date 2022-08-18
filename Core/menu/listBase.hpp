/*
 * listBase.h
 *
 *  Created on: Aug 17, 2022
 *      Author: Łukasz
 */

#ifndef MENU_LISTBASE_HPP_
#define MENU_LISTBASE_HPP_

#include "element.hpp"

namespace Menu {

class ListBase : public Element
{
public:
	ListBase(const char* name);
	virtual ~ListBase();
};

} /* namespace Menu */

#endif /* MENU_LISTBASE_HPP_ */
