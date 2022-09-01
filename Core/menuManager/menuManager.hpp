/*
 * menuManager.hpp
 *
 *  Created on: 23 sie 2022
 *      Author: Łukasz
 */

#ifndef MENUMANAGER_MENUMANAGER_HPP_
#define MENUMANAGER_MENUMANAGER_HPP_

#include <stdint.h>
#include "../menuGenerator/menuGenerator.hpp"

namespace Menu{
class Element;
class ListBase;
}

class DisplayManager;

template <int16_t Size>
class MainList;

class MenuManager {
public:
	using menuEl = Menu::Element *;
	using menuList = MainList<mainListSize> *;

	MenuManager();
	~MenuManager();

	void begin(DisplayManager * displayManager, menuList list);
	void update();
	void sendImpulse(uint16_t id, uint16_t state = 0);

private:
	DisplayManager * displayManager_;

	menuEl currentElement_;

	menuEl loadingScreen_;
	menuList mainList_;
	menuEl configTime_;
	menuEl gameElement_;
};

#endif /* MENUMANAGER_MENUMANAGER_HPP_ */
