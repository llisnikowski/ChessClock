/*
 * GameManager.cpp
 *
 *  Created on: 2 wrz 2022
 *      Author: Łukasz
 */

#include "config.hpp"
#include "gameManager.hpp"
#include "../chessTimeMode/base.hpp"

GameManager::GameManager()
	:Menu::Element(""), gameState_(), player_()
{

}

GameManager::~GameManager()
{
}


uint8_t GameManager::sendImpulse(uint16_t id, uint16_t state)
{
	switch(static_cast<SignalId>(id)){
	case SignalId::playButton:
		if(gameState_ == stop){

		}
		else if(gameState_ == play){

		}
		return 1;
	case SignalId::player1Button:
		if(gameState_ == play && !player_){
			return 1;
		}
		return 0;
	case SignalId::player2Button:
		if(gameState_ == play && player_ ){
			return 1;
		}
		return 0;
	default:
		return 0;
	}
}
