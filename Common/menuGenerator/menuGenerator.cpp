/*
 * MenuGenerator.cpp
 *
 *  Created on: 20 sie 2022
 *      Author: Łukasz
 */

#include "menuGenerator.hpp"

#include "../menu/mainlist.hpp"
#include "../menu/list.hpp"
#include "../menu/timeModeElement.hpp"
#include "../chessTimeMode/base.hpp"
#include "../chessTimeMode/normal.hpp"
#include "../chessTimeMode/extraTime.hpp"
#include "../time/timeHMS.hpp"

constexpr uint8_t BLITZ_COUNT{3};
constexpr uint8_t RAPID_COUNT{5};
constexpr uint8_t NORMAL_COUNT{3};

MainList<mainListSize> mainList;
Menu::List<BLITZ_COUNT + RAPID_COUNT + NORMAL_COUNT, TimeModeElement> allModesList{"All"};
Menu::List<BLITZ_COUNT,TimeModeElement> blitzList{"Blitz"};
Menu::List<RAPID_COUNT,TimeModeElement> rapidList{"Rapid"};
Menu::List<NORMAL_COUNT,TimeModeElement> normalList{"Normal"};

ChessTimeMode::Normal cTM_1m{TimeHMS{0, 1, 0}};
ChessTimeMode::ExtraTime cTM_3m_2s{TimeHMS{0, 3, 0},TimeHMS{0, 0, 2}};
ChessTimeMode::Normal cTM_5m{TimeHMS{0, 5, 0}};

ChessTimeMode::Normal cTM_10m{TimeHMS{0, 10, 0}};
ChessTimeMode::ExtraTime cTM_10m_5s{TimeHMS{0, 10, 0},TimeHMS{0, 0, 5}};
ChessTimeMode::Normal cTM_15m{TimeHMS{0, 15, 0}};
ChessTimeMode::Normal cTM_20m{TimeHMS{0, 20, 0}};
ChessTimeMode::Normal cTM_30m{TimeHMS{0, 30, 0}};

ChessTimeMode::Normal cTM_1h{TimeHMS{1, 0, 0}};
ChessTimeMode::ExtraTime cTM_1h_30s{TimeHMS{1, 0, 0},TimeHMS{0, 0, 30}};
ChessTimeMode::Normal cTM_1h30m{TimeHMS{1, 30, 0}};


TimeModeElement blitzElements[BLITZ_COUNT]{{"1min", cTM_1m}, {"3min+2s", cTM_3m_2s}, {"5min", cTM_5m}};
TimeModeElement rapidElements[RAPID_COUNT]{{"10min", cTM_10m}, {"10min+5s", cTM_10m_5s}, {"15min", cTM_15m}, {"20min", cTM_20m}, {"30min", cTM_30m}};
TimeModeElement normalElements[NORMAL_COUNT]{{"1h", cTM_1h}, {"1h+30s", cTM_1h_30s}, {"1h 30min", cTM_1h30m}};



MenuGenerator::MenuGenerator()
{
}

MenuGenerator::~MenuGenerator()
{
}

bool MenuGenerator::linkMainList()
{
	return mainList.setElement(0, &allModesList)
			&& mainList.setElement(1, &blitzList)
			&& mainList.setElement(2, &rapidList)
			&& mainList.setElement(3, &normalList);
}

bool MenuGenerator::linkBlitzList()
{
	for(int i = 0; i < BLITZ_COUNT ; i++){
		if(!blitzList.setElement(i, &blitzElements[i])){
			return false;
		}
	}
	return true;
}

bool MenuGenerator::linkRapidList()
{
	for(int i = 0; i < RAPID_COUNT ; i++){
		if(!rapidList.setElement(i, &rapidElements[i])){
			return false;
		}
	}
	return true;
}

bool MenuGenerator::linkNormalList()
{
	for(int i = 0; i < NORMAL_COUNT ; i++){
		if(!normalList.setElement(i, &normalElements[i])){
			return false;
		}
	}
	return true;
}

bool MenuGenerator::linkAllModesList()
{
	for(int i = 0; i < BLITZ_COUNT ; i++){
		if(!allModesList.setElement(i, &blitzElements[i])){
			return false;
		}
	}
	for(int i = 0; i < RAPID_COUNT ; i++){
		if(!allModesList.setElement(i + BLITZ_COUNT, &rapidElements[i])){
			return false;
		}
	}
	for(int i = 0; i < NORMAL_COUNT ; i++){
		if(!allModesList.setElement(i + BLITZ_COUNT + RAPID_COUNT, &normalElements[i])){
			return false;
		}
	}
	return true;
}

void MenuGenerator::link()
{
	if(!linkMainList()){
		while(true);
	}
	if(!linkBlitzList() || !linkRapidList() || !linkNormalList() || !linkAllModesList()){
		while(true);
	}
}


MainList<mainListSize> * MenuGenerator::getMainList()
{
	return &mainList;
}














