/*
 * OledDisplay.cpp
 *
 *  Created on: Jul 25, 2022
 *      Author: Łukasz
 */

#include "oledDisplay.h"
#include "../uartLog/uartLog.h"


OledDisplay::OledDisplay(I2C_HandleTypeDef* i2c, uint8_t width, uint8_t height)
	:OledDisplayGFX(width, height), DrawInBorder(width, height), i2cHandle_(i2c)
{
	bufSize_ = width * height / 8;
	buffor_ = new uint8_t[bufSize_]{};
}

OledDisplay::~OledDisplay()
{
	delete [] buffor_;
}


void OledDisplay::init(uint8_t address)
{
	address_ = address;

	static uint8_t init1[] = {
			SSD1306_DISPLAYOFF,         // 0xAE
	        SSD1306_SETDISPLAYCLOCKDIV, // 0xD5
	        0x80, // the suggested ratio 0x80
	        SSD1306_SETMULTIPLEX}; // 0xA8
	commandList(init1, sizeof(init1));
	command(height_ -1);

	static uint8_t init2[] = {SSD1306_SETDISPLAYOFFSET, // 0xD3
		0x0,                      // no offset
		SSD1306_SETSTARTLINE | 0x0, // line #0
		SSD1306_CHARGEPUMP};        // 0x8D
	commandList(init2, sizeof(init2));

	command(0x14); //SSD1306_SWITCHCAPVCC  (vccstate == SSD1306_EXTERNALVCC) ? 0x10 : 0x14)

	static uint8_t init3[] = {SSD1306_MEMORYMODE, // 0x20
		0x00, // 0x0 act like ks0108
		SSD1306_SEGREMAP | 0x1,
	 	SSD1306_COMSCANDEC};
	commandList(init3, sizeof(init3));

	uint8_t comPins = 0x02;
	uint8_t  contrast = 0x8F;
	if ((width_ == 128) && (height_ == 32)) {
	    comPins = 0x02;
	    contrast = 0x8F;
	} else if ((width_ == 128) && (height_ == 64)) {
	    comPins = 0x12;
	    contrast = 0xCF; // (vccstate == SSD1306_EXTERNALVCC) ? 0x9F : 0xCF
	} else if ((width_ == 96) && (height_ == 16)) {
		comPins = 0x2; // ada x12
	    contrast = 0xAF; //(vccstate == SSD1306_EXTERNALVCC) ? 0x10 : 0xAF
	} else {
	    // Other screen varieties -- TBD
	}

	command(SSD1306_SETCOMPINS);
	command(comPins);
	command(SSD1306_SETCONTRAST);
	command(contrast);

	command(SSD1306_SETPRECHARGE); // 0xd9
	command(0xF1); //(vccstate == SSD1306_EXTERNALVCC) ? 0x22 : 0xF1

	static uint8_t init5[] = {
	      SSD1306_SETVCOMDETECT, // 0xDB
	      0x40,
	      SSD1306_DISPLAYALLON_RESUME, // 0xA4
	      SSD1306_NORMALDISPLAY,       // 0xA6
	      SSD1306_DEACTIVATE_SCROLL,
	      SSD1306_DISPLAYON}; // Main screen turn on
	commandList(init5, sizeof(init5));

	display();
}


void OledDisplay::command(uint8_t cmd)
{
	HAL_I2C_Mem_Write(i2cHandle_, address_, 0x0, 1, &cmd, 1, HAL_MAX_DELAY);
}

void OledDisplay::commandList(uint8_t *cmds, uint8_t count)
{
	HAL_I2C_Mem_Write(i2cHandle_, address_ , 0x0, 1, cmds, count, HAL_MAX_DELAY);
}


void OledDisplay::clear()
{
	for(int i = 0; i<bufSize_; i++){
		buffor_[i] = 0;
	}
}


void OledDisplay::drawPixel(int16_t x, int16_t y, uint8_t color)
{
	if(x < 0 || x >= width_) return;
	if(y < 0 || y >= height_) return;
	if(x < borderX0 || x > borderX1) return;
	if(y < borderY0 || y > borderY1) return;

	while(HAL_I2C_GetState(i2cHandle_) != HAL_I2C_STATE_READY);
	switch(color){
	case SSD1306_WHITE:
		buffor_[width_ * (y/8) + x] |= (1 << (y & 7));
		break;
	case SSD1306_BLACK:
		buffor_[width_ * (y/8) + x] &= ~(1 << (y & 7));
		break;
	case SSD1306_INVERSE:
		buffor_[width_ * (y/8) + x] ^= (1 << (y & 7));
		break;
	}

}


void OledDisplay::display()
{
	static uint8_t dlist1[] = {
	      SSD1306_PAGEADDR,
	      0,                      // Page start address
	      0xFF,                   // Page end (not really, but works here)
	      SSD1306_COLUMNADDR, 0}; // Column start address
	commandList(dlist1, sizeof(dlist1));
	command(width_ - 1); // Column end address

	while(HAL_I2C_GetState(i2cHandle_) != HAL_I2C_STATE_READY);
	HAL_I2C_Mem_Write_DMA(i2cHandle_, address_ ,(uint8_t)0x40, 1, buffor_, bufSize_);
}













