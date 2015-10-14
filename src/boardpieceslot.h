/* Board class to be used in Perfection game */

#ifndef BOARDPIECESLOT_H
#define BOARDPIECESLOT_H

#include "piece.h"
#include <stdio.h>

class BoardPieceSlot
{
private:
	int x;
	int y;
  int shape;

public:
	BoardPieceSlot(int x, int y, int shape);
	void draw();
	int getX();
	int getY();
	int getShape();
};

#endif
