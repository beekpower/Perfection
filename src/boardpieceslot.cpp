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
        Shapes::drawShape(shape);
    glPopMatrix();
}