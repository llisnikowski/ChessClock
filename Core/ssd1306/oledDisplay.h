/*
 * OledDisplay.h
 *
 *  Created on: Jul 25, 2022
 *      Author: Łukasz
 */

#ifndef SSD1306_OLEDDISPLAY_H_
#define SSD1306_OLEDDISPLAY_H_
#include <stdint.h>
#include "i2c.h"

#include "drawInBorder.h"
#include "oledDisplayGFX.h"

//--- Defines ---
#define SSD1306_BLACK 0   ///< Draw 'off' pixels
#define SSD1306_WHITE 1   ///< Draw 'on' pixels
#define SSD1306_INVERSE 2 ///< Invert pixels

#define REFRESH_MIN 0x80
#define REFRESH_MID 0xB0
#define REFRESH_MAX 0xF0


#define SSD1306_MEMORYMODE 0x20
#define SSD1306_COLUMNADDR 0x21
#define SSD1306_PAGEADDR 0x22
#define SSD1306_SETCONTRAST 0x81
#define SSD1306_CHARGEPUMP 0x8D
#define SSD1306_SEGREMAP 0xA0
#define SSD1306_DISPLAYALLON_RESUME 0xA4
#define SSD1306_DISPLAYALLON 0xA5
#define SSD1306_NORMALDISPLAY 0xA6
#define SSD1306_INVERTDISPLAY 0xA7
#define SSD1306_SETMULTIPLEX 0xA8
#define SSD1306_DISPLAYOFF 0xAE
#define SSD1306_DISPLAYON 0xAF
#define SSD1306_COMSCANINC 0xC0
#define SSD1306_COMSCANDEC 0xC8
#define SSD1306_SETDISPLAYOFFSET 0xD3
#define SSD1306_SETDISPLAYCLOCKDIV 0xD5
#define SSD1306_SETPRECHARGE 0xD9
#define SSD1306_SETCOMPINS 0xDA
#define SSD1306_SETVCOMDETECT 0xDB

#define SSD1306_SETLOWCOLUMN 0x00
#define SSD1306_SETHIGHCOLUMN 0x10
#define SSD1306_SETSTARTLINE 0x40

#define SSD1306_EXTERNALVCC 0x01  ///< External display voltage source
#define SSD1306_SWITCHCAPVCC 0x02 ///< Gen. display voltage from 3.3V

#define SSD1306_RIGHT_HORIZONTAL_SCROLL 0x26              ///< Init rt scroll
#define SSD1306_LEFT_HORIZONTAL_SCROLL 0x27               ///< Init left scroll
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29 ///< Init diag scroll
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 0x2A  ///< Init diag scroll
#define SSD1306_DEACTIVATE_SCROLL 0x2E                    ///< Stop scroll
#define SSD1306_ACTIVATE_SCROLL 0x2F                      ///< Start scroll
#define SSD1306_SET_VERTICAL_SCROLL_AREA 0xA3             ///< Set scroll range
//--- \ Defines ---



class OledDisplay :public OledDisplayGFX, public DrawInBorder
{
public:
	OledDisplay(I2C_HandleTypeDef* i2c, uint8_t width, uint8_t height);
	virtual ~OledDisplay();

	void init(uint8_t address);

	void clear();
	void drawPixel(int16_t x, int16_t y, uint8_t color = 1) final;

	void display();

private:
	void command(uint8_t cmd);
	void commandList(uint8_t *cmds, uint8_t count);

	I2C_HandleTypeDef* i2cHandle_;

	uint8_t address_;
	uint8_t *buffor_;
	uint16_t bufSize_;
};

#endif /* SSD1306_OLEDDISPLAY_H_ */
