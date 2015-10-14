#include "piece.h"


Piece::Piece(int l_x, int l_y, int t)
{
	rotation = Util::randomNumber(0, 360);
    // Set the position of this piece to a random location
    if(Util::randomNumber(1, 2) == 1) {
        // Piece will be on a random X on the right side
        initialX = Util::randomNumber(525, 100);
    } else {
        // Piece will be on a random X on the left side
        initialX = Util::randomNumber(-925, -400);
    }
    initialY = Util::randomNumber(-400, 400);
	loc_x = initialX;
	loc_y = initialY;
	type = t;
}

//Will incorporate the added features from header
void Piece::draw()
{
	glPushMatrix();
		glTranslatef(loc_x, loc_y, 0);
		glRotatef(rotation,0,0,1);
		glColor3ub(230, 221, 42);
		Shapes::drawShape(type, true);
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

void Piece::restoreInitialLocation() {
	loc_x = initialX;
	loc_y = initialY;
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
