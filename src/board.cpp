#ifdef __linux__
#include "GL/freeglut.h"
#include "GL/gl.h"
#elif _WIN32
// Put your windows imports here
#elif __APPLE__
#include <freeglut.h>
#endif

#include "board.h"


Board::Board(int screenWidth, int screenHeight, BoardPieceSlot *boardpieceSlotArray[25])
{
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
    for(int i = 0; i < 25; i++) {
        boardPiecesSlot[i] = boardpieceSlotArray[i];
    }
    on = true;
}

void Board::checkInPlace(Piece* pieces[])
{
  for (int i = 0; i < 25; i++)
	{
		boardPiecesSlot[i]->pieceInSlot(pieces[i]);
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

void Board::turnOnGame() {
    on = true;
}

void Board::turnOffGame() {
    on = false;
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
    
    // Okay, now we have to draw the horizontal / vertical lines separate the board piece slots
    
    // Vertical lines first
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
        glColor3ub(64, 101, 147);
        glVertex2f(-180,300 - boardOffset);
        glVertex2f(-180,-300 - boardOffset);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3ub(64, 101, 147);
        glVertex2f(-60,300 - boardOffset);
        glVertex2f(-60,-300 - boardOffset);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3ub(64, 101, 147);
        glVertex2f(60,300 - boardOffset);
        glVertex2f(60,-300 - boardOffset);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3ub(64, 101, 147);
        glVertex2f(180,300 - boardOffset);
        glVertex2f(180,-300 - boardOffset);
    glEnd();
    
    // Horizontal lines next
    glBegin(GL_LINE_STRIP);
        glColor3ub(64, 101, 147);
        glVertex2f(-300,180 - boardOffset);
        glVertex2f(300,180 - boardOffset);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3ub(64, 101, 147);
        glVertex2f(-300,60 - boardOffset);
        glVertex2f(300,60 - boardOffset);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3ub(64, 101, 147);
        glVertex2f(-300,-60 - boardOffset);
        glVertex2f(300,-60 - boardOffset);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3ub(64, 101, 147);
        glVertex2f(-300,-180 - boardOffset);
        glVertex2f(300,-180 - boardOffset);
    glEnd();

    
    // Now outline the entire body so it looks good
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
    
    // Switch section
    glBegin(GL_QUADS);
        glColor3f((float)210/255, (float)24/255, (float)26/255);
        glVertex2f(-75,375 - boardOffset);
        glVertex2f(-75,325 - boardOffset);
        glVertex2f(75,325 - boardOffset);
        glVertex2f(75,375 - boardOffset);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
        glColor3ub(230, 221, 42);
        glVertex2f(-75,375 - boardOffset);
        glVertex2f(-75,325 - boardOffset);
        glVertex2f(75,325 - boardOffset);
        glVertex2f(75,375 - boardOffset);
    glEnd();
    
    if(on) {
        glBegin(GL_BITMAP);
            glColor3ub(0, 0, 0);
            glRasterPos2i(15, 340 - boardOffset);
            glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)"ON");
        glEnd();
        
        // Switch section
        glBegin(GL_QUADS);
            glColor3f((float)0/255, (float)0/255, (float)0/255);
            glVertex2f(-50,370 - boardOffset);
            glVertex2f(-50,330 - boardOffset);
            glVertex2f(-70,330 - boardOffset);
            glVertex2f(-70,370 - boardOffset);
        glEnd();
    } else {
        glBegin(GL_BITMAP);
            glColor3ub(0, 0, 0);
            glRasterPos2i(-65, 340 - boardOffset);
            glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)"OFF");
        glEnd();
        
        // Switch section
        glBegin(GL_QUADS);
            glColor3f((float)0/255, (float)0/255, (float)0/255);
            glVertex2f(50,370 - boardOffset);
            glVertex2f(50,330 - boardOffset);
            glVertex2f(70,330 - boardOffset);
            glVertex2f(70,370 - boardOffset);
        glEnd();
    }
    
    // Outline of entire header
    glBegin(GL_LINE_STRIP);
        glColor3ub(230, 221, 42);
        glVertex2f(-300,500 - boardOffset);
        glVertex2f(-300,325 - boardOffset);
        glVertex2f(300,325 - boardOffset);
        glVertex2f(300,500 - boardOffset);
        glVertex2f(-300,500 - boardOffset);
    glEnd();
}
