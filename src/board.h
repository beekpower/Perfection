/* Board class to be used in Perfection game */

#ifndef BOARD_H
#define BOARD_H

#include "shapes.h"
#include "piece.h"
#include "boardpieceslot.h"

class Board
{
private:
	int screenWidth;
	int screenHeight;
    BoardPieceSlot *boardPiecesSlot[25];
    int boardOffset = 100; // height offset - the blue part of the board isn't centered vertically
    void drawHeader();
    void drawBody();
    void drawBackground();
    bool on;

public:
	Board(int screenWidth, int screenHeight, BoardPieceSlot *boardpieceSlotArray[]);
	void draw();
    void turnOnGame();
    void turnOffGame();
};

#endif
