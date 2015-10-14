#ifndef Util_Header
#define Util_Header

#ifdef __linux__
    #include "GL/freeglut.h"
    #include "GL/gl.h"
#elif _WIN32
    // Put your windows imports here
#elif __APPLE__
    #include <freeglut.h>
#endif

#include "math.h"

class Util {
  public:
    void static drawCircle(int radius, int startDegree, int endDegree, bool drawBorder);
    void static drawCircle(int radius, bool drawBorder);
    void static drawPolygon(int n, int radius, bool drawBorder);
};

#endif
