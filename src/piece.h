/* Piece class to be used in Perfection game */

#ifndef PIECE_H
#define PIECE_H

#include "shapes.h"

enum pieceType {CIRCLE, HALF_CIRCLE, SQUARE, OFFSET_CIRCLE_1, OFFSET_CIRCLE2, HEXAGON, RECTANGLE, RIGHT_TRIANGLE, OCTAGON,
				CUP, THIN_CYLINDER, THICK_CYLINDER, THICK_CROSS, PENTAGON, EQUAL_TRIANGLE, RHOMBUS, KITE, FIVE_STAR, SIX_STAR,
				THIN_CROSS, FLOWER, QUARTER_CIRCLE, QUAD, CIRCLE_FLOWER, T};

class Piece
{
private:
	int loc_x;
	int loc_y;
	pieceType type;

public:
	Piece(int x, int y, pieceType t);
	
	/* Totally need to add varying color and translation to current x,y location here */
	void drawPiece();
	int getLocX();
	int getLocY();
};

#endif
