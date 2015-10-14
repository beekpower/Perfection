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
    void static drawShape(int shape, bool isPiece);
    int static symmetricalDegrees(int shape);
    //Shapes
    void static drawCircle(bool isPiece);
    void static drawHalfCircle(bool isPiece);
    void static drawSquare(bool isPiece);
    void static drawOffsetCircle1(bool isPiece);
    void static drawOffsetCircle2(bool isPiece);
    void static drawHexagon(bool isPiece);
    void static drawRectangle(bool isPiece);
    void static drawRightTriangle(bool isPiece);
    void static drawOctogon(bool isPiece);
    void static drawCup(bool isPiece);
    void static drawThinCylinder(bool isPiece);
    void static drawThickCylinder(bool isPiece);
    void static drawThickCross(bool isPiece);
    void static drawPentagon(bool isPiece);
    void static drawEqualTriangle(bool isPiece);
    void static drawRhombus(bool isPiece);
    void static drawKite(bool isPiece);
    void static draw5Star(bool isPiece);
    void static draw6Star(bool isPiece);
    void static drawThinCross(bool isPiece);
    void static drawFlower(bool isPiece);
    void static drawQuarterCircle(bool isPiece);
    void static drawQuad(bool isPiece);
    void static drawCircleFlower(bool isPiece);
    void static drawT(bool isPiece);
};

#endif
