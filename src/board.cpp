#include "board.h"

Board::Board(int screenWidth, int screenHeight)
{
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;

    // Create all the board piece slots
    // Initialize all piece objects
    int row = 0;
    for (int i = 0; i < 25; i++) {
        boardPiecesSlot[i] = new BoardPieceSlot(-240 + (120 *(i % 5)), 140 - (row * 120), i);
        if(((i+1)%5) == 0) {
            row++;
        }
    }
}

void Board::draw()
{
    this->drawBackground();
    this->drawBody();
    this->drawHeader();
    for (int i = 0; i < 25; i++) {
        glColor3ub(230, 221, 42);
        boardPiecesSlot[i]->draw();
    }
}

void Board::drawBackground() {
    // Main board
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
}

void Board::drawBody() {
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

void Board::drawHeader() {
    // Main blue section
    glBegin(GL_QUADS);
        glColor3f((float)39/255, (float)116/255, (float)212/255);
        glVertex2f(-300,500 - boardOffset);
        glVertex2f(-300,325 - boardOffset);
        glVertex2f(300,325 - boardOffset);
        glVertex2f(300,500 - boardOffset);
    glEnd();

    // Outline it so it looks good
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
        glColor3ub(230, 221, 42);
        glVertex2f(-300,500 - boardOffset);
        glVertex2f(-300,325 - boardOffset);
        glVertex2f(300,325 - boardOffset);
        glVertex2f(300,500 - boardOffset);
        glVertex2f(-300,500 - boardOffset);
    glEnd();
}
