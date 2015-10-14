/* Board class to be used in Perfection game */

#ifndef BOARDPIECESLOT_H
#define BOARDPIECESLOT_H

class BoardPieceSlot
{
private:
	int x;
	int y;
    int shape;
    
public:
	BoardPieceSlot(int x, int y, int shape);
	void draw();
};

#endif
