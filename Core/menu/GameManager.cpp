/*
 * GameManager.cpp
 *
 *  Created on: 2 wrz 2022
 *      Author: Łukasz
 */

#include "main.h"
#include "config.hpp"
#include "gameManager.hpp"
#include "../chessTimeMode/base.hpp"
#include "../chessTimeMode/modeType.hpp"
#include "../chessTimeMode/normal.hpp"
#include "../chessTimeMode/universal.hpp"

GameManager::GameManager()
	:Menu::Element(""), gameState_(), player_()
{

}

GameManager::~GameManager()
{
}


uint8_t GameManager::sendImpulse(uint16_t id, uint16_t state)
{
	switch(static_cast<SignalId>(id))
	{
	case SignalId::playButton:
		if(gameState_ == stop){
			gameState_ = play;
			if(!player_){
				oldTick = HAL_GetTick() - oneSecound + player1Ticks_;
			}
			else{
				oldTick = HAL_GetTick() - oneSecound + player2Ticks_;
			}
		}
		else if(gameState_ == play){
			gameState_ = stop;
			if(!player_){
				player1Ticks_ = HAL_GetTick() - oldTick;
			}
			else{
				player2Ticks_ = HAL_GetTick() - oldTick;
			}
		}
		return 1;
	case SignalId::player1Button:
		if(gameState_ == play && !player_){
			player_ = true;
			return 1;
		}
		return 0;
	case SignalId::player2Button:
		if(gameState_ == play && player_ ){
			player_ = false;
			return 1;
		}
		return 0;
	default:
		return 0;
	}
}

void GameManager::setChessTimeMode(const ChessTimeMode::Base * mode)
{
	switch(mode->getMenuType())
	{
	case ModeType::normal:
	{
		mode_ = *static_cast<const ChessTimeMode::Normal *>(mode);
		break;
	}
	case ModeType::universal:
	{
		mode_ = *static_cast<const ChessTimeMode::Universal *>(mode);
		break;
	}
	default:
		break;
	}
}

const ChessTimeMode::Universal & GameManager::getChessTimeMode() const
{
	return mode_;
}


uint8_t GameManager::update()
{
	if(gameState_ == play){
		uint32_t curTick = HAL_GetTick();
		if(curTick - oldTick >= oneSecound){
			while(curTick - oldTick >= oneSecound){
				if(!player_)
					mode_.getTime1().addSeconds(-1);
				else
					mode_.getTime2().addSeconds(-1);
				oldTick += 1000;
			}
		return Menu::used;
		}
	}
	return Menu::noAction;
}




