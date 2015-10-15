#include "piece.h"
#include "boardpieceslot.h"
#include "shapes.h"


Piece::Piece(int l_x, int l_y, int t)
{
	rotation = Util::randomNumber(0, 360);
	symmetryCount = Shapes::symmetricalDegrees(t);
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
  rotationVelocity = 0;
}

void Piece::draw()
{
	glPushMatrix();
		glTranslatef(loc_x, loc_y, 0);
		glRotatef(rotation,0,0,1);
		glColor3ub(230, 221, 42);
		Shapes::drawShape(type, true);
	glPopMatrix();

    // Rotate this shape accoring to the shape's rotation velocity
    if ((rotation + rotationVelocity) > 360 || (rotation + rotationVelocity) < 0) {
        rotation = rotationVelocity - (360 - rotation);

    } else {
        rotation += rotationVelocity;
    }

    if(rotationVelocity > 0) {
        rotationVelocity--;
    } else if(rotationVelocity < 0) {
        rotationVelocity++;
    }
}

bool Piece::isInSlot(BoardPieceSlot *slot)
{
	const int thresh = 5;
	const int rotationThresh = 20;
	//shapes match
	if (slot->getShape() == type) {
		//locations match
		if (loc_x < (slot->getX() + thresh) && loc_x > (slot->getX() - thresh) && loc_y < (slot->getY() + thresh) && loc_y > (slot->getY() - thresh)) {
			//rotations match
			for (int i = 1; i < symmetryCount + 1; i++) {

				int testDegree = 360 / i;
					//	printf("%d\n", testDegree);

				for (int j = 0; j < rotationThresh; j++) {
					int deg;
          if (testDegree + i > 360) {
						deg = testDegree + i - 360;
					} else if (testDegree - i < 0) {
						deg = -(testDegree - i);
					} else {
						deg = testDegree + i;
					}
											printf("%d, %d\n", rotation, deg);

					if (rotation == deg) {

						return true;
					}


				}

				// if (rotation < (testDegree + rotationThresh) && rotation > (testDegree - rotationThresh)) {
				// 	return true;
				// }
			}
			return false;
    } else {
			return false;
		}
    } else {
      return false;
    }
}

void Piece::setInPlace(bool status)
{
	inPlace = status;
}

bool Piece::isInPlace()
{
	return inPlace;
}

void Piece::rotate(int degrees)
{
    // We must increase the current rotation velocity, only if it's below a threshold (don't want the piece spinning too much)
    if(abs(rotationVelocity) < 10) {
        rotationVelocity += degrees * 7;
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
