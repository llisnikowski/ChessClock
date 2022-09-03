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
#include "menuType.hpp"
#include "timeModeElement.hpp"

namespace Menu
{
class ListBase;
}
namespace ChessTimeMode
{
class Base;
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
	const ChessTimeMode::Base * getCurrentTimeMode();

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

template <int16_t Size>
const ChessTimeMode::Base * MainList<Size>::getCurrentTimeMode()
{
	if(Menu::ListBase * list = menuL::getCurElementType()){
		if(Menu::Element * el = list->getCurElement()){
			if(el->getMenuType() == MenuType::timeModeElement){
				return static_cast<TimeModeElement *>(el)->getMode();
			}
		}
	}

	return nullptr;
}





#endif /* MENU_MAINLIST_HPP_ */
