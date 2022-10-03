/*
 * OledDisplayDrawBorder.h
 *
 *  Created on: Jul 31, 2022
 *      Author: Łukasz
 */

#ifndef SSD1306_DRAWINBORDER_H_
#define SSD1306_DRAWINBORDER_H_

#include <stdint.h>

class DrawInBorder
{
public:
	DrawInBorder(uint8_t width, uint8_t height);
	virtual ~DrawInBorder();

	void setBorderDraw(int16_t x0, int16_t y0, int16_t x1, int16_t y1);

protected:
	int16_t borderX0;
	int16_t borderY0;
	int16_t borderX1;
	int16_t borderY1;
};

#endif /* SSD1306_DRAWINBORDER_H_ */
