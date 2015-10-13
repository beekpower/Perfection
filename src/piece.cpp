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
	glRotatef(degreeToRotate,0,0,1);
	glColor3ub(230, 221, 42);
	Shapes::drawShape(type);
}

int rotate(int degrees)
{
	if ((rotation + degrees) > 360 || (rotation + degrees) < 0) {
		rotation = degrees - (360 - rotation);

	} else {
		rotation += degrees;
	}
}

int Piece::getLocX()
{
	return loc_x;
}

int Piece::getLocY()
{
	return loc_y;
}
