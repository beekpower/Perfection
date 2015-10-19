#ifdef __linux__
#include "GL/freeglut.h"
#include "GL/gl.h"
#elif _WIN32
// Put your windows imports here
#elif __APPLE__
#include <freeglut.h>
#endif

#include <stdio.h>
#include <stdlib.h>


#include <ctime>


#include "util.h"
#include "math.h"
#include "stdio.h"
#include "piece.h"
#include "board.h"
#include "timer.h"

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 500
#define SECONDS 60

int mouseX, mouseY;

Piece *pieces[25];
BoardPieceSlot *boardPiecesSlot[25];
Piece *selectedPiece;
Board *board;
Timer gameTimer(333333 * SECONDS);
bool switchActive = false;
long secs, usecs;
int loopCount=0;
timeval start, end;

void draw() {
    //Clear the whole screen
    glClear(GL_COLOR_BUFFER_BIT);

	// Draw board
    board->draw();
    glScalef(1.0,1.000000000000001,1.0);

    // Draw shapes
    int row = 0;
    if (selectedPiece != NULL) {
        selectedPiece->setLoc(mouseX, mouseY);
    }

    //Loop through each shape
    for (int i = 0; i < 25; i++) {
        pieces[i]->draw();
    }

	gameTimer.drawTimer();

    glFlush();
}

void processNormalKeys(unsigned char key, int x, int y) {

    if (selectedPiece != NULL) {
        if (key == 'a') {
            selectedPiece->rotate(10);
            glutPostRedisplay();
        }

        if (key == 's') {
            selectedPiece->rotate(-10);
            glutPostRedisplay();
        }
    }
}

void init(void) {
    //Set background color to white
    glClearColor(0.52,0.25,0.23,0.0);
    //Make thettons lines a bit thicker
    glLineWidth(1.0);
    //Setup the viewport
    glOrtho(-1000, 1000, -500, 500, 1, -1);
    //Initialy clear the screen
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    // Create all the board piece slots
    // Initialize all piece objects
    int row = 0;
    for (int i = 0; i < 25; i++) {
        boardPiecesSlot[i] = new BoardPieceSlot(-240 + (120 *(i % 5)), 140 - (row * 120), i);
        if(((i+1)%5) == 0) {
            row++;
        }
    }

    // Initialize the board object
    board = new Board(WINDOW_WIDTH, WINDOW_HEIGHT, boardPiecesSlot);

    // Initialize all piece objects
    row = 0;
    for (int i = 0; i < 25; i++) {
        pieces[i] = new Piece(105 * (i % 5), -row * 105, i);
        if(((i+1)%5) == 0) {
            row++;
        }

    }

}

/*Mouse event*/
void mouse(int button, int state, int x, int y) {

  x = ((float)x - ((float)WINDOW_WIDTH / 2.0)) * (2000.0 / WINDOW_WIDTH);
  y = (-((float)y - ((float)WINDOW_HEIGHT / 2.0))) * (1000.0 / WINDOW_HEIGHT);

    switch (button) {
        case GLUT_LEFT_BUTTON:   //When something is left clicked
            if(state == GLUT_UP) {
                if (selectedPiece == NULL) {
                    for (int i = 0; i < 25; i++) {
                        if (pieces[i]->clicked(x, y))
                        {
                            selectedPiece = pieces[i];
                        }
                    }
                } else {
                    if (selectedPiece->isInSlot(boardPiecesSlot[selectedPiece->getType()]))  {
                      selectedPiece = NULL;
                    } else {
                        // Now, if the piece is on the board, set it back to the initial location
                        if (x > (0 - 325) && x < (0 + 325) && y > (0 - 400) && y < (0 + 400)) {
                            selectedPiece->restoreInitialLocation();
                        } else {
                            // Piece can be moved here, but we must update it's original location
                            selectedPiece->setInitialLocation(x, y);
                        }
                        selectedPiece = NULL;
                    }
                }
                // Test to see if it is within the on / off switch
                if (x > (0 - 75) && x < (0 + 75) && y > (350 - 25 - 100) && y < (350 + 25 - 100)) {
                    if(board->on) {
						switchActive = false;
                        board->turnOffGame();
                    } else {
						switchActive = true;
                        board->turnOnGame();
                    }
                }
            }
            break;
    }

    glutPostRedisplay();
}

void mouseMove(int x, int y) {
    mouseX = ((float)x - ((float)WINDOW_WIDTH / 2.0)) * (2000.0 / WINDOW_WIDTH);
    mouseY = (-((float)y - ((float)WINDOW_HEIGHT / 2.0))) * (1000.0 / WINDOW_HEIGHT);
    glutPostRedisplay();
}

void idler() {
	if (loopCount == 0 || loopCount == 1)
		gettimeofday(&start, NULL);
    glutPostRedisplay();
	loopCount++;
	if (loopCount == 3)
	{
		gettimeofday(&end, NULL);
		secs = end.tv_sec - start.tv_sec;
		usecs = end.tv_usec - start.tv_usec;
		if (gameTimer.countDown((1000000 * secs) + usecs, switchActive))
		{
			board->turnOffGame();
	for(int i=0; i<25;i++)
	{
		if(pieces[i]->isInSlot(boardPiecesSlot[i]))
		{
			pieces[i]->randomizeInitialLocation();
			pieces[i]->restoreInitialLocation();
		}
	}
			switchActive = false;
			gameTimer.reset();
		}
		loopCount = 0;
	}
}

/*Main entry point for the progam*/
int main(int argc, char** argv) {
    srand(time(NULL)); //setup random seed
    glutInit(&argc, argv);                           //init glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);     //set display mode
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT); //set the window size
    glutInitWindowPosition(100, 150);                 //set the window position
    glutCreateWindow("Perfection");                   //create the window and window name
    glutKeyboardFunc(processNormalKeys);
    glutMouseFunc(mouse);                             //set the mouse event function
    glutPassiveMotionFunc(mouseMove);
    glutDisplayFunc(draw);                     //set the redraw function                            //set the mouse event function
    glutIdleFunc (idler);   // idler function
    init();                                           //init function
    glutMainLoop();                                   //enter the glut loop
    return (0);
}
