#ifndef Shapes_Header
#define Shapes_Header

#ifdef __linux__
    #include "GL/freeglut.h"
    #include "GL/gl.h"
#elif _WIN32
    // Put your windows imports here
#elif __APPLE__
    #include <freeglut.h>
#endif

#include "util.h"

class Shapes {
  private:
    void static drawCenterPeg();
  public:
    void static drawRelativeBox();
    void static drawShape(int shape);
    int static symmetricalDegrees(int shape);
    //Shapes
    void static drawCircle();
    void static drawHalfCircle();
    void static drawSquare();
    void static drawOffsetCircle1();
    void static drawOffsetCircle2();
    void static drawHexagon();
    void static drawRectangle();
    void static drawRightTriangle();
    void static drawOctogon();
    void static drawCup();
    void static drawThinCylinder();
    void static drawThickCylinder();
    void static drawThickCross();
    void static drawPentagon();
    void static drawEqualTriangle();
    void static drawRhombus();
    void static drawKite();
    void static draw5Star();
    void static draw6Star();
    void static drawThinCross();
    void static drawFlower();
    void static drawQuarterCircle();
    void static drawQuad();
    void static drawCircleFlower();
    void static drawT();
};

#endif
