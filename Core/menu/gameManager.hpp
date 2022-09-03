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
public:
	static constexpr uint16_t oneSecound = 1000;
	enum{
		stop,
		play
	};

	GameManager();
	~GameManager();

	void setChessTimeMode(const ChessTimeMode::Base * mode);
	const ChessTimeMode::Universal & getChessTimeMode() const;

	uint8_t update() override;
	uint8_t sendImpulse(uint16_t id, uint16_t state = 0) override;

private:
	ChessTimeMode::Universal mode_;
	uint16_t player1Ticks_;
	uint16_t player2Ticks_;
	uint32_t oldTick;

	uint8_t gameState_;
	bool player_;
};

#endif /* MENU_GAMEMANAGER_HPP_ */
