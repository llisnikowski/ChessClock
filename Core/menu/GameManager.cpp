/*
 * GameManager.cpp
 *
 *  Created on: 2 wrz 2022
 *      Author: Łukasz
 */

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
