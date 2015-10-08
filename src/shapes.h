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
    void drawShape(int shape);
    int symmetricalDegrees(int shape);
    //Shapes
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
    void drawRhombus();
    void drawKite();
    void draw5Star();
    void draw6Star();
    void drawThinCross();
    void drawFlower();
    void drawQuarterCircle();
    void drawQuad();
    void drawCircleFlower();
    void drawT();
};

#endif
