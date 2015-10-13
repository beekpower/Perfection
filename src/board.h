/* Board class to be used in Perfection game */

#ifndef BOARD_H
#define BOARD_H

#include "shapes.h"

class Board
{
private:
	int screenWidth;
	int screenHeight;
    int boardOffset = 100; // height offset - the blue part of the board isn't centered vertically
    void drawHeader();
    void drawBody();
    void drawBackground();
    
public:
	Board(int screenWidth, int screenHeight);

	void draw();
};

#endif
