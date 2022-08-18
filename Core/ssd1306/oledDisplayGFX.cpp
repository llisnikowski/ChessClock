/*
 * oledDisplayGFX.cpp
 *
 *  Created on: Jul 26, 2022
 *      Author: lukasz
 */

#include "oledDisplayGFX.h"
#include "font.h"


#define swap_int16_t(a, b)                                                    \
  {                                                                            \
    int16_t t = a;                                                             \
    a = b;                                                                     \
    b = t;                                                                     \
  }

template<typename T>
static T abs(T a){return a>=0? a : -a;}

OledDisplayGFX::OledDisplayGFX(uint8_t width, uint8_t height) :
		width_(width), height_(height)
{
}

OledDisplayGFX::~OledDisplayGFX()
{
}

void OledDisplayGFX::drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint8_t color)
{
	int16_t steep = abs(y1 - y0) > abs(x1 - x0);
	if (steep) {
		swap_int16_t(x0, y0);
		swap_int16_t(x1, y1);
	}

	if (x0 > x1) {
		swap_int16_t(x0, x1);
		swap_int16_t(y0, y1);
	}

	int16_t dx, dy;
	dx = x1 - x0;
	dy = abs(y1 - y0);

	int16_t err = dx / 2;
	int16_t ystep;

	if (y0 < y1) {
		ystep = 1;
	} else {
		ystep = -1;
	}

	for (; x0 <= x1; x0++) {
		if (steep) {
			setPixel(y0, x0, color);
		} else {
			setPixel(x0, y0, color);
		}
		err -= dy;
		if (err < 0) {
			y0 += ystep;
			err += dx;
		}
	}
}

void OledDisplayGFX::fillRect(int16_t x, int16_t y, int16_t width, int16_t height, uint8_t color)
{
	for(int16_t i=x; i<x+width; i++){
		drawFastVLine(i, y, height, color);
	}
}

void OledDisplayGFX::drawFastVLine(int16_t x, int16_t y, int16_t height, uint8_t color)
{
    drawLine(x, y, x, y+height-1, color);
}

void OledDisplayGFX::setCursor(int16_t x, int16_t y)
{
	cursorX_ = x;
	cursorY_ = y;
}

#include "../uartLog/uartLog.h"


void OledDisplayGFX::drawChar(unsigned char c, uint8_t size, uint8_t color, uint8_t bg)
{
	if ((cursorX_ >= width_) || (cursorY_ >= height_) || ((cursorX_ + 6 * size - 1) < 0) || ((cursorY_ + 8 * size - 1) < 0)){
		cursorX_ += 5*size +1; return;
	}

	for (int8_t i = 0; i < 5; i++) { // Char bitmap = 5 columns
		uint8_t line = font[c * 5 + i];
		for (int8_t j = 0; j < 8; j++, line >>= 1) {
			if (line & 1) {
				if (size == 1)
					setPixel(cursorX_ + i, cursorY_ + j, color);
				else
					fillRect(cursorX_ + i * size, cursorY_ + j * size, size,
							size, color);
			} else if (bg != color) {
				if (size == 1)
					setPixel(cursorX_ + i, cursorY_ + j, bg);
				else
					fillRect(cursorX_ + i * size, cursorY_ + j * size, size,
							size, bg);
			}
		}
	}
	if (bg != color) { // If opaque, draw vertical line for last column
		if (size == 1)
			drawFastVLine(cursorX_ + 5, cursorY_, 8, bg);
		else
			fillRect(cursorX_ + 5 * size, cursorY_, size, 8 * size, bg);
	}

	cursorX_ += 5 * size + 1;
}

void OledDisplayGFX::print(const char *str, uint8_t size, uint8_t color, uint8_t bg)
{
    while(*str != 0){
        drawChar(*str++, size, color, bg);
    }
}

void OledDisplayGFX::drawBitmap(uint16_t x, uint16_t y, const uint8_t *bitmap, uint8_t width, uint8_t height, uint8_t color){
	int byteWidth = (width+7)/8;

	for(int j=0; j<height; j++){
		for(int i=0; i<width; i++){
			if( bitmap[j*byteWidth+i/8] & (128 >> (i & 7)) ){
				setPixel(x+i, y+j, color);
			}
		}
	}
}
