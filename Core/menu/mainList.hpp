/*
 * mainList.h
 *
 *  Created on: 24 sie 2022
 *      Author: Łukasz
 */

#ifndef MENU_MAINLIST_HPP_
#define MENU_MAINLIST_HPP_

#include "list.hpp"
#include "element.hpp"
#include "config.hpp"

namespace Menu{
class ListBase;
}

template <int16_t Size>
class MainList: public Menu::List<Size, Menu::ListBase>
{
public:
	using menuL = Menu::List<Size, Menu::ListBase>;

	MainList()
		:menuL("")
	{
		menuL::setLooping(false);
	}
	virtual ~MainList() = default;

	uint8_t sendImpulse(uint16_t id, uint16_t state = 0) override;
	MenuType getMenuType() override {return MenuType::mainList;}
};






template <int16_t Size>
uint8_t MainList<Size>::sendImpulse(uint16_t id, uint16_t state)
{
	switch(static_cast<SignalId>(id))
	{
	case SignalId::leftButton:
		this->prevElement();
		return Menu::used;
	case SignalId::rightButton:
		this->nextElement();
		return Menu::used;
	case SignalId::minusButton:
		if(!menuL::elements_[menuL::currentIndex_]) return false;
		menuL::elements_[menuL::currentIndex_]->prevElement();
		return Menu::used;
	case SignalId::plusButton:
		if(!menuL::elements_[menuL::currentIndex_]) return false;
		menuL::elements_[menuL::currentIndex_]->nextElement();
		return Menu::used;
	case SignalId::playButton:
		if(!menuL::elements_[menuL::currentIndex_]) return false;
		menuL::elements_[menuL::currentIndex_]->nextElement();
		return Menu::changeElement;
	default:
		return Menu::used;
	}
}








#endif /* MENU_MAINLIST_HPP_ */
