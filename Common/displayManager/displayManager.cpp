/*
 * DisplayManager.cpp
 *
 *  Created on: 23 sie 2022
 *      Author: Łukasz
 */

#include "displayManager.hpp"

#include <string.h>

#include "../ssd1306/oledDisplay.h"
#include "../menu/element.hpp"
#include "../menu/listBase.hpp"
#include "../menu/mainList.hpp"
#include "../menu/timeModeElement.hpp"
#include "../menu/gameManager.hpp"
#include "../time/timeText.hpp"
#include "../chessTimeMode/universal.hpp"



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
	else if(el->getMenuType() == MenuType::gameManager){
		display(static_cast<GameManager *>(el));
	}
}



void DisplayManager::display(MainList<mainListSize> * list)
{
	display1_.clear();
	if(auto * subList = list->getCurElementType()){
		const char * name = subList->getName();
		display1_.setCursor(findLocationX(3, strlen(name)), 5);
		display1_.print(name, 3);
		if(auto * subEl = subList->getCurElement()){
			if(subEl->getMenuType() == MenuType::timeModeElement){
				display2_.clear();
				TimeText timeText = TimeText{static_cast<TimeModeElement*>(subEl)->getMode()->getTime1()};
				display2_.setCursor(findLocationX(3, timeText.getLength()), 5);
				display2_.print(timeText(), 3);
				display2_.display();
			}
		}
	}

	display1_.display();
	currentElement_ = list;
}

void DisplayManager::display(GameManager * gameManager)
{
	const ChessTimeMode::Universal mode = gameManager->getChessTimeMode();

	display1_.clear();
	display2_.clear();
	TimeText timeText1(mode.getCountdownTimer1());
	TimeText timeText2(mode.getCountdownTimer2());
	display1_.setCursor(findLocationX(3, timeText1.getLength()), 5);
	display2_.setCursor(findLocationX(3, timeText2.getLength()), 5);

	display1_.print(timeText1(),3);
	display2_.print(timeText2(),3);

	if(!gameManager->getPlayer()){
		display1_.fillRect(0, 32-5+1, 5, 5);
	}
	else{
		display2_.fillRect(128-5+1, 32-5+1, 5, 5);
	}

	display1_.display();
	display2_.display();
}

void DisplayManager::display(OledDisplay & display, TimeModeElement * timeModeElement)
{
	display.clear();
	display.setCursor(5, 5);
	display.print(timeModeElement->getName(), 1);
	display.display();
	currentElement_ = timeModeElement;
}

int8_t DisplayManager::findLocationX(uint8_t size, uint8_t length)
{
	return (128 - (size * 5 + 1) * length)/2;
}













