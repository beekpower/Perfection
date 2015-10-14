#include "boardpieceslot.h"
#include "shapes.h"

BoardPieceSlot::BoardPieceSlot(int x, int y, int shape)
{
	this->x = x;
	this->y = y;
    this->shape = shape;
}

void BoardPieceSlot::draw()
{
    glPushMatrix();
        glTranslatef(x, y, 0);
        glRotatef(0,0,0,1);
        glColor3ub(230, 221, 42);
        Shapes::drawShape(shape, false);
    glPopMatrix();
}

bool BoardPieceSlot::pieceInSlot(Piece *testPiece)
{
  if (testPiece->getType() == shape) {
		if ((x + 3) > testPiece->getLocX() && (x - 3) < testPiece->getLocX() && (y + 3) > testPiece->getLocY() && (y - 3) < testPiece->getLocY()) {
			printf("piece in right place");
    }

	}


}
