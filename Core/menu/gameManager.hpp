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
#include "../menu/menuType.hpp"

namespace ChessTimeMode
{
class Base;
}

class Diode;

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

	MenuType getMenuType() override {return MenuType::gameManager;}

	uint8_t update() override;
	uint8_t sendImpulse(uint16_t id, uint16_t state = 0) override;

	void setDiodes(Diode * diode1, Diode * diode2);
	bool getPlayer() const;

private:
	void turnOnDiodes();

	ChessTimeMode::Universal mode_;

	uint8_t gameState_;
	bool player_;

	Diode * diodes_[2];
};

#endif /* MENU_GAMEMANAGER_HPP_ */
