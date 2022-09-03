/*
 * element.h
 *
 *  Created on: Aug 17, 2022
 *      Author: Łukasz
 */

#ifndef MENU_ELEMENT_HPP_
#define MENU_ELEMENT_HPP_

#include <stdint.h>
#include "menuType.hpp"


namespace Menu {

enum{
	noAction,
	used,
	changeElement
};

class Element {
public:
	Element(const char* name);
	virtual ~Element();

	const char * getName() const;

	virtual uint8_t sendImpulse(uint16_t id, uint16_t state = 0){return 0;}
	virtual uint8_t update(){return 0;}

	virtual MenuType getMenuType(){return MenuType::element;}

private:
	const char* name_;
};


} /* namespace Menu */

#endif /* MENU_ELEMENT_HPP_ */
