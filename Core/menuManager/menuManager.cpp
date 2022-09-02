/*
 * menuManager.cpp
 *
 *  Created on: 23 sie 2022
 *      Author: Łukasz
 */

#include "menuManager.hpp"

#include "../menu/element.hpp"
#include "../menu/listBase.hpp"
#include "../menu/mainList.hpp"
#include "../displayManager/displayManager.hpp"


MenuManager::MenuManager()
	:currentElement_{}
{
}

MenuManager::~MenuManager()
{
}


void MenuManager::begin(DisplayManager * displayManager, menuList list)
{
	displayManager_ = displayManager;
	mainList_ = list;
	currentElement_ = list;
	displayManager_->display(mainList_);
	update();
}


void MenuManager::update()
{
	if(!currentElement_) return;
	if(currentElement_->update()){
		if(currentElement_ == mainList_){
		}
		else if(currentElement_ == gameElement_){
		}
	}
}

void MenuManager::sendImpulse(uint16_t id, uint16_t state)
{
	if(!currentElement_) return;
	if(currentElement_->sendImpulse(id, state)){
		displayManager_->findAndDisplay(currentElement_);
	}
}
