/* Board class to be used in Perfection game */

#ifndef BOARD_H
#define BOARD_H

#include "shapes.h"

class Board
{
private:
	int screenWidth;
	int screenHeight;

public:
	Board(int screenWidth, int screenHeight);

	void draw();
};

#endif
