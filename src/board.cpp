#ifdef __linux__
#include "GL/freeglut.h"
#include "GL/gl.h"
#elif _WIN32
// Put your windows imports here
#elif __APPLE__
#include <freeglut.h>
#endif

#include "string"
#include "board.h"

Board::Board(int screenWidth, int screenHeight, BoardPieceSlot *boardpieceSlotArray[25])
{
	this->boardOffset = 100;
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
    for(int i = 0; i < 25; i++) {
        boardPiecesSlot[i] = boardpieceSlotArray[i];
    }
    on = false;

	initDisplayLists();
}

void Board::draw()
{
    //glCallList(this->board);
		glCallList(this->mainBoard);
		glCallList(this->outline);
		glCallList(this->body);
    this->drawHeader();
    for (int i = 0; i < 25; i++) {
        glColor3ub(230, 221, 42);
        boardPiecesSlot[i]->draw();
    }
glBegin(GL_BITMAP);
            glColor3ub(230, 221, 42);
            glRasterPos2i(5, 420 - boardOffset);
            glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)"PERFECTION");
        glEnd();
}

void Board::turnOnGame() {
    on = true;
}

void Board::turnOffGame() {
    on = false;
}

void Board::initDisplayLists() {
//	int mainBoard = glGenLists(1);
//  int outline = glGenLists(1);
//	int body = glGenLists(1);

	// Main board
  glNewList(mainBoard, GL_COMPILE);
		glBegin(GL_QUADS);
				glColor3f((float)210/255, (float)24/255, (float)26/255);
				glVertex2f(-325,400 + (boardOffset/2));
				glVertex2f(-325,-400 - (boardOffset/2));
				glVertex2f(325,-400 - (boardOffset/2));
				glVertex2f(325,400 + (boardOffset/2));
		glEnd();
  glEndList();

  //outline
  glNewList(outline, GL_COMPILE);
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
  glEndList();

	//body
  glNewList(body, GL_COMPILE);
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
  glEndList();

	glNewList(board, GL_COMPILE);
		glCallList(mainBoard);
		glCallList(outline);
		glCallList(body);
  glEndList();
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
