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
#include "../diode/diode.hpp"

GameManager::GameManager()
	:Menu::Element(""), gameState_(), player_(), diodes_()
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
				mode_.getCountdownTimer1().start();
			}
			else{
				mode_.getCountdownTimer2().start();
			}
		}
		else if(gameState_ == play){
			gameState_ = stop;
			mode_.getCountdownTimer1().stop();
			mode_.getCountdownTimer2().stop();
		}
		turnOnDiodes();
		return 1;
	case SignalId::player1Button:
		if(gameState_ == play && !player_){
			player_ = true;
			mode_.getCountdownTimer1().stop();
			mode_.getCountdownTimer2().start();
			turnOnDiodes();
			return 1;
		}
		return 0;
	case SignalId::player2Button:
		if(gameState_ == play && player_ ){
			player_ = false;
			mode_.getCountdownTimer2().stop();
			mode_.getCountdownTimer1().start();
			turnOnDiodes();
			return 1;
		}
		return 0;
	default:
		return 0;
	}
}

void GameManager::setDiodes(Diode * diode1, Diode * diode2)
{
	diodes_[0] = diode1;
	diodes_[1] = diode2;
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
		if(!player_){
			if(mode_.getCountdownTimer1().update())
				return Menu::used;
		}
		else{
			if(mode_.getCountdownTimer2().update())
				return Menu::used;
		}
	}
	return Menu::noAction;
}

void GameManager::turnOnDiodes()
{
	if(!diodes_[0] || !diodes_[1]) return;
	if(gameState_ == play){
		if(!player_){
			diodes_[0]->write(true);
			diodes_[1]->write(false);
		}
		else{
			diodes_[0]->write(false);
			diodes_[1]->write(true);
		}
	}
	else{
		diodes_[0]->write(false);
		diodes_[1]->write(false);
	}
}


