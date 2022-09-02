/*
 * GameManager.h
 *
 *  Created on: 2 wrz 2022
 *      Author: Łukasz
 */

#ifndef MENU_GAMEMANAGER_H_
#define MENU_GAMEMANAGER_H_

#include "../menu/element.hpp"
#include "../chessTimeMode/universal.hpp"

class GameManager : public Menu::Element
{
public:
	GameManager();
	~GameManager();

private:
	ChessTimeMode::Universal mode;
};

#endif /* MENU_GAMEMANAGER_H_ */
