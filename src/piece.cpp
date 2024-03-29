#include "piece.h"
#include "boardpieceslot.h"
#include "shapes.h"

Piece::Piece(int l_x, int l_y, int type)
{
	randomizeInitialLocation();
	loc_x = initialX;
	loc_y = initialY;
	this->type = type;
  returnToInitialLocation = false;
  hasMoved = false;
  movingUp = false;
}

void Piece::draw()
{
	glPushMatrix();
		glTranslatef(loc_x, loc_y, 0);
		glRotatef(rotation,0,0,1);
		glColor3ub(230, 221, 42);
		Shapes::drawShape(type, true);
	glPopMatrix();

    if(returnToInitialLocation) {
        int newX = loc_x;
        int newY = loc_y;

        if(!hasMoved) {
            hasMoved = true;
            movingY = true;
            movingX = true;
            // Get the horizontal direction
            if(initialX < newX) {
                movingLeft = true;
            } else if(initialX > newX) {
                movingLeft = false;
            }

            // Get the vertical direction
            if(initialY < newY) {
                movingUp = true;
            } else if(initialY > newY) {
                movingUp = false;
            }
        }
        if(initialY < newY) {
            if(!movingUp) {
                movingY = false;
            } else {
                loc_y = newY - 10;
            }
        } else if(initialY > newY) {
            if(movingUp) {
                movingY = false;
            } else {
                loc_y = newY + 10;
            }
        } else {
            movingY = false;
        }

        if(initialX < newX) {
            if(!movingLeft) {
                movingX = false;
            } else {
                loc_x = newX - 10;
            }
        } else if(initialX > newX) {
            if(movingLeft) {
                movingX = false;
            } else {
                loc_x = newX + 10;
            }
        } else {
            movingX = false;
        }

        if((!movingY) && (!movingX)) {
            returnToInitialLocation = false;
            hasMoved = false;
            loc_x = initialX;
            loc_y = initialY;
        }

    }
}

void Piece::randomizeInitialLocation() {
	rotation = (Util::randomNumber(0, 360) / 10) * 10;
	symmetryCount = Shapes::symmetricalDegrees(type);
	// Set the position of this piece to a random location
	if(Util::randomNumber(1, 2) == 1) {
			// Piece will be on a random X on the right side
			initialX = Util::randomNumber(525, 100);
	} else {
			// Piece will be on a random X on the left side
			initialX = Util::randomNumber(-925, -400);
	}
	initialY = Util::randomNumber(-400, 400);
}

bool Piece::isInSlot(BoardPieceSlot *slot)
{
	const int thresh = 5;
	//shapes match
	if (slot->getShape() == type) {
		//locations match
		if (loc_x < (slot->getX() + thresh) && loc_x > (slot->getX() - thresh) && loc_y < (slot->getY() + thresh) && loc_y > (slot->getY() - thresh)) {
			//rotations match
			int incrementDegree = 360 / symmetryCount;
			for (int testDegree = 0; testDegree < 360; testDegree += incrementDegree) {
				int roundedDegree = round(testDegree/10) * 10;
      	if (rotation == roundedDegree) {
					return true;
				}
			}
			return false;
    } else {
			return false;
		}
    } else {
      return false;
    }
}

void Piece::rotate(int degrees)
{
		rotation += degrees;
		if (rotation < 0) {
			rotation = 350;
		} else if (rotation == 360) {
			rotation = 0;
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
	//loc_x = initialX;
	//loc_y = initialY;
    returnToInitialLocation = true;
    hasMoved = false;
}

void Piece::setInitialLocation(int x, int y) {
    initialX = x;
    initialY = y;
}

void Piece::setLoc(int x, int y)
{
  loc_x = x;
	loc_y = y;
}

int Piece::getType() {
	return type;
}

int Piece::getLocX()
{
	return loc_x;
}

int Piece::getLocY()
{
	return loc_y;
}
