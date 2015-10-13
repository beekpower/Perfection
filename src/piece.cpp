#include "piece.h"

Piece::Piece(int l_x, int l_y, pieceType t)
{
	loc_x = l_x;
	loc_y = l_y;
	type = t;
}

//Will incorporate the added features from header
void Piece::drawPiece()
{
	glTranslatef(loc_x, loc_y, 0);
	Shapes::drawShape(type);
}

int Piece::getLocX()
{
	return loc_x;
}

int Piece::getLocY()
{
	return loc_y;
}
