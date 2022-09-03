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
#include "../menu/gameManager.hpp"


MenuManager::MenuManager()
	:currentElement_{}
{
}

MenuManager::~MenuManager()
{
}


void MenuManager::begin(DisplayManager * displayManager, menuList list, gameMgr gameManager)
{
	displayManager_ = displayManager;
	gameManager_ = gameManager;
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
		else if(currentElement_ == gameManager_){
		}
	}
}

void MenuManager::sendImpulse(uint16_t id, uint16_t state)
{
	if(!currentElement_) return;
	uint8_t signal = currentElement_->sendImpulse(id, state);
	if(signal == Menu::used){
		displayManager_->findAndDisplay(currentElement_);
	}
	else if(signal == Menu::changeElement){
		if(currentElement_ == mainList_){
			currentElement_ = gameManager_;
			displayManager_->display(gameManager_);
		}
		else {
			displayManager_->findAndDisplay(currentElement_);
		}
	}
}
