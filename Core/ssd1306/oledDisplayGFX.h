/*
 * oledDisplayGFX.h
 *
 *  Created on: Jul 26, 2022
 *      Author: lukasz
 */

#ifndef SSD1306_OLEDDISPLAYGFX_H_
#define SSD1306_OLEDDISPLAYGFX_H_

#include <stdint.h>
#include "bitmapsTest.h"

class OledDisplayGFX
{
public:
	OledDisplayGFX(uint8_t width, uint8_t height);
	virtual ~OledDisplayGFX();

	virtual void setPixel(int16_t x, int16_t y, uint8_t color) = 0;
	void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint8_t color=1);
	void fillRect(int16_t x, int16_t y, int16_t width, int16_t height, uint8_t color=1);
	void drawFastVLine(int16_t x, int16_t y, int16_t height, uint8_t color=1);

	void setCursor(int16_t x, int16_t y);
	void drawChar(unsigned char c, uint8_t size=1, uint8_t color=1, uint8_t bg=0);
	void print(const char *str, uint8_t size=1, uint8_t color=1, uint8_t bg=0);
	void drawBitmap(uint16_t x, uint16_t y, const uint8_t *bitmap, uint8_t width, uint8_t height, uint8_t color=1);

protected:
	uint8_t width_;
	uint8_t height_;
	int16_t cursorX_;
	int16_t cursorY_;
};

#endif /* SSD1306_OLEDDISPLAYGFX_H_ */
