#ifndef Util_Header
#define Util_Header

#include "GL/freeglut.h"
#include "GL/gl.h"
#include "math.h"

class Util {
  public:
    void drawCircle(int radius, int startDegree, int endDegree);
    void drawCircle(int radius);
    void drawPolygon(int n, int radius);
};

#endif
