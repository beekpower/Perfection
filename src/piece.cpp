#include "piece.h"

Piece::Piece(int l_x, int l_y, int t)
{
	loc_x = l_x;
	loc_y = l_y;
	type = t;
	rotation = 0;
}

//Will incorporate the added features from header
void Piece::draw()
{
	glPushMatrix();
		glTranslatef(loc_x, loc_y, 0);
		glRotatef(rotation,0,0,1);
		glColor3ub(230, 221, 42);
		Shapes::drawShape(type, false);
	glPopMatrix();
}

void Piece::rotate(int degrees)
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
