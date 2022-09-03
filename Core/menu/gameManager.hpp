/*
 * GameManager.h
 *
 *  Created on: 2 wrz 2022
 *      Author: Łukasz
 */

#ifndef MENU_GAMEMANAGER_HPP_
#define MENU_GAMEMANAGER_HPP_

#include <stdint.h>
#include "../menu/element.hpp"
#include "../chessTimeMode/universal.hpp"

namespace ChessTimeMode
{
	class Base;
}

class GameManager : public Menu::Element
{
	enum{
		stop,
		play
	};

public:
	GameManager();
	~GameManager();

	uint8_t sendImpulse(uint16_t id, uint16_t state = 0) override;


private:
	ChessTimeMode::Universal mode_;

	uint8_t gameState_;
	bool player_;
};

#endif /* MENU_GAMEMANAGER_HPP_ */
