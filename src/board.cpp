#include "board.h"

Board::Board(int screenWidth, int screenHeight)
{
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
}

void Board::draw()
{
    // Main board
    int boardOffset = 100; // height offset - the blue part of the board isn't centered vertically
    glBegin(GL_QUADS);
    glColor3f((float)210/255, (float)24/255, (float)26/255);
    glVertex2f(-325,400 + (boardOffset/2));
    glVertex2f(-325,-400 - (boardOffset/2));
    glVertex2f(325,-400 - (boardOffset/2));
    glVertex2f(325,400 + (boardOffset/2));
    glEnd();
    // Outline it so it looks good
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
    glColor3f((float)0/255, (float)0/255, (float)0/255);
    glVertex2f(-325,400 + (boardOffset/2));
    glVertex2f(-325,-400 - (boardOffset/2));
    glVertex2f(325,-400 - (boardOffset/2));
    glVertex2f(325,400 + (boardOffset/2));
    glVertex2f(-325,400 + (boardOffset/2));
    glEnd();
    
    // Main blue section
    glBegin(GL_QUADS);
    glColor3f((float)39/255, (float)116/255, (float)212/255);
    glVertex2f(-300,300 - boardOffset);
    glVertex2f(-300,-300 - boardOffset);
    glVertex2f(300,-300 - boardOffset);
    glVertex2f(300,300 - boardOffset);
    glEnd();
    // Outline it so it looks good
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
    glColor3f((float)0/255, (float)0/255, (float)0/255);
    glVertex2f(-300,300 - boardOffset);
    glVertex2f(-300,-300 - boardOffset);
    glVertex2f(300,-300 - boardOffset);
    glVertex2f(300,300 - boardOffset);
    glVertex2f(-300,300 - boardOffset);
    glEnd();
}