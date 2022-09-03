/*
 * DisplayManager.h
 *
 *  Created on: 23 sie 2022
 *      Author: Łukasz
 */

#ifndef DISPLAYMANAGER_DISPLAYMANAGER_HPP_
#define DISPLAYMANAGER_DISPLAYMANAGER_HPP_

#include <stdint.h>
#include "../menuGenerator/menuGenerator.hpp"

class OledDisplay;
class TimeModeElement;
class TimeHMS;
class GameManager;

namespace Menu
{
class Element;
class ListBase;
}

template <int16_t Size>
class MainList;


class DisplayManager {
public:
	DisplayManager(OledDisplay & display1, OledDisplay & display2);
	~DisplayManager();

	void findAndDisplay(Menu::Element * el);
	void display(MainList<mainListSize> * list);
	void display(GameManager * gameManager);
	void display(OledDisplay & display, TimeModeElement * timeModeElement);

	void displayTime(OledDisplay & display, const TimeHMS & time);


private:
	OledDisplay & display1_;
	OledDisplay & display2_;

	Menu::Element * currentElement_;
};

#endif /* DISPLAYMANAGER_DISPLAYMANAGER_HPP_ */
