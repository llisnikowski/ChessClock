/*
 * DisplayManager.cpp
 *
 *  Created on: 23 sie 2022
 *      Author: Łukasz
 */

#include "displayManager.hpp"

#include "../ssd1306/oledDisplay.h"
#include "../menu/element.hpp"
#include "../menu/listBase.hpp"
#include "../menu/mainList.hpp"
#include "../menu/timeModeElement.hpp"
#include "../time/timeText.hpp"


DisplayManager::DisplayManager(OledDisplay & display1, OledDisplay & display2)
	:display1_(display1), display2_(display2), currentElement_{}
{

}

DisplayManager::~DisplayManager()
{

}

void DisplayManager::findAndDisplay(Menu::Element * el)
{
	if(!el) return;
	else if(el->getMenuType() == MenuType::mainList){
		display(static_cast<MainList<mainListSize> *>(el));
	}
	else if(el->getMenuType() == MenuType::timeModeElement){
		//display(static_cast<TimeModeElement *>(el));
	}
}

void DisplayManager::display(MainList<mainListSize> * list)
{
	display1_.clear();
	display1_.setCursor(5, 5);
	if(auto * subList = list->getCurElementType()){
		display1_.print(subList->getName(), 1);
		if(auto * subEl = subList->getCurElement()){
			if(subEl->getMenuType() == MenuType::timeModeElement){
				display2_.clear();
				display2_.setCursor(5, 5);
				display2_.print(TimeText{static_cast<TimeModeElement*>(subEl)->getMode()->getTime1()}(), 1);
				display2_.display();
			}
		}
	}

	display1_.display();
	currentElement_ = list;
}

void DisplayManager::display(OledDisplay & display, TimeModeElement * timeModeElement)
{
	display.clear();
	display.setCursor(5, 5);
	display.print(timeModeElement->getName(), 1);
	display.display();
	currentElement_ = timeModeElement;
}
















