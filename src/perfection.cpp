#ifdef __linux__
    #include "GL/freeglut.h"
    #include "GL/gl.h"
#elif _WIN32
    // Put your windows imports here
#elif __APPLE__
    #include <freeglut.h>
#endif

#include "util.h"
#include "math.h"
#include "stdio.h"
#include "piece.h"
#include "board.h"

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 500

int degreeToRotate = 0;

Piece *pieces[25];
Piece *selectedPiece;
Board *board;

void draw() {
  //Clear the whole screen
  glClear(GL_COLOR_BUFFER_BIT);
    // Draw board
    drawBoard();
    board->draw();

    // Draw shapes
    Shapes::drawRelativeBox();
    glPushMatrix();
    glTranslatef(-920, 420, 0);
    int row = 0;
    //Loop through each shape
    for (int i = 0; i < 25; i++) {
        pieces[i]->draw();
    }
  glPopMatrix();
  glFlush();
}

void processNormalKeys(unsigned char key, int x, int y) {

	if (key == 'a') {
    degreeToRotate+=2;
    if (degreeToRotate > 359) {
      degreeToRotate = 0;
    }
    glutPostRedisplay();
  }

  if (key == 's') {
    degreeToRotate-=2;
    if (degreeToRotate < 0) {
      degreeToRotate = 359;
    }
    glutPostRedisplay();
  }



}



void init(void) {
    //Set background color to white
    glClearColor(1,1,1,0.0);
    //Make thettons lines a bit thicker
    glLineWidth(1.0);
    //Setup the viewport
    glOrtho(-1000, 1000, -500, 500, 1, -1);
    //Initialy clear the screen
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    // Initialize the board object
    board = new Board(WINDOW_WIDTH, WINDOW_HEIGHT);

    // Initialize all piece objects
    int row = 0;
    for (int i = 0; i < 25; i++) {
        pieces[i] = new Piece(105 * (i % 5), -row * 105, i);
        if(((i+1)%5) == 0) {
            row++;
        }

    }

}

/*Mouse event*/
void mouse(int button, int state, int x, int y) {
  switch (button) {
    case GLUT_LEFT_BUTTON:   //When something is left clicked
      if(state == GLUT_UP) {

      }
      break;
  }
}

/*Main entry point for the progam*/
int main(int argc, char** argv) {
  glutInit(&argc, argv);                           //init glut
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);     //set display mode
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT); //set the window size
  glutInitWindowPosition(100, 150);                 //set the window position
  glutCreateWindow("Project 1 Shapes");                   //create the window and window name
  glutKeyboardFunc(processNormalKeys);
  glutMouseFunc(mouse);                             //set the mouse event function
  glutDisplayFunc(draw);                     //set the redraw function                            //set the mouse event function
  init();                                           //init function
  glutMainLoop();                                   //enter the glut loop
  return (0);
}
