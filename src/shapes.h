#ifndef Shapes_Header
#define Shapes_Header

#include "GL/freeglut.h"
#include "GL/gl.h"
#include "util.h"

class Shapes {
  private:
    void drawCenterPeg();
  public:
    void drawRelativeBox();
    void drawCircle();
    void drawHalfCircle();
    void drawSquare();
    void drawOffsetCircle1();
    void drawOffsetCircle2();
    void drawHexagon();
    void drawRectangle();
    void drawRightTriangle();
    void drawOctogon();
    void drawCup();
    void drawThinCylinder();
    void drawThickCylinder();
    void drawThickCross();
    void drawPentagon();
    void drawEqualTriangle();
};

#endif
