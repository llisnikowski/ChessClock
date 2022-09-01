/*
 * MenuGenerator.h
 *
 *  Created on: 20 sie 2022
 *      Author: Łukasz
 */

#ifndef MENUGENERATOR_MENUGENERATOR_HPP_
#define MENUGENERATOR_MENUGENERATOR_HPP_

#include <stdint.h>

template <int16_t Size>
class MainList;


constexpr uint8_t mainListSize = 4;

class MenuGenerator {
public:
	MenuGenerator();
	~MenuGenerator();

	void link();
	MainList<mainListSize> * getMainList();

private:
	bool linkMainList();
	bool linkBlitzList();
	bool linkRapidList();
	bool linkNormalList();
	bool linkAllModesList();

};

#endif /* MENUGENERATOR_MENUGENERATOR_HPP_ */
