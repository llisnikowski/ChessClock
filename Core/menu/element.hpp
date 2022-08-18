/*
 * element.h
 *
 *  Created on: Aug 17, 2022
 *      Author: Łukasz
 */

#ifndef MENU_ELEMENT_HPP_
#define MENU_ELEMENT_HPP_

namespace Menu {

class Element {
public:
	Element(const char* name);
	virtual ~Element();

	const char* getName() const;

	virtual void markInList();
	virtual void selected();

private:
	const char* name_;
};


} /* namespace Menu */

#endif /* MENU_ELEMENT_HPP_ */
