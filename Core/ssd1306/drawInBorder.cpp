/*
 * OledDisplayDrawBorder.cpp
 *
 *  Created on: Jul 31, 2022
 *      Author: Łukasz
 */

#include "drawInBorder.h"

DrawInBorder::DrawInBorder(uint8_t width, uint8_t height)
	:borderX0(0), borderY0(0), borderX1(width), borderY1(height)
{

}


DrawInBorder::~DrawInBorder()
{

}

void DrawInBorder::setBorderDraw(int16_t x0, int16_t y0, int16_t x1, int16_t y1)
{
	borderX0 = x0;
	borderY0 = y0;
	borderX1 = x1;
	borderY1 = y1;
}
