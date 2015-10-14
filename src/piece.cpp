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
		Shapes::drawShape(type);
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

bool Piece::clicked(int x, int y) {
	if (x > (loc_x - 50) && x < (loc_x + 50) && y > (loc_y - 50) && y < (loc_y + 50)) {
		return true;
	} else {
		return false;
	}
}

void Piece::setLoc(int x, int y)
{
  loc_x = x;
	loc_y = y;
}

int Piece::getLocX()
{
	return loc_x;
}

int Piece::getLocY()
{
	return loc_y;
}
