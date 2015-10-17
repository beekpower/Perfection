/* Piece class to be used in Perfection game */

#ifndef PIECE_H
#define PIECE_H

#include "shapes.h"
#include "boardpieceslot.h"

enum pieceType {CIRCLE, HALF_CIRCLE, SQUARE, OFFSET_CIRCLE_1, OFFSET_CIRCLE2, HEXAGON, RECTANGLE, RIGHT_TRIANGLE, OCTAGON,
				CUP, THIN_CYLINDER, THICK_CYLINDER, THICK_CROSS, PENTAGON, EQUAL_TRIANGLE, RHOMBUS, KITE, FIVE_STAR, SIX_STAR,
				THIN_CROSS, FLOWER, QUARTER_CIRCLE, QUAD, CIRCLE_FLOWER, T};

class Piece
{
private:
	int initialX;
	int initialY;
	int loc_x;
	int loc_y;
	int rotation;
	int symmetryCount;
	int type;
  int rotationVelocity;
	bool inPlace;
  bool returnToInitialLocation;
  bool hasMoved;
  bool movingLeft;

public:
	Piece(int x, int y, int t);

	/* Totally need to add varying color and translation to current x,y location here */
	void draw();
	void rotate(int degrees);
	bool clicked(int x, int y);
	void setLoc(int x, int y);
	int getType();
	bool isInSlot(BoardPieceSlot *slot);
	int getLocX();
	int getLocY();
	void restoreInitialLocation();
  void setInitialLocation(int x, int y);
};

#endif
