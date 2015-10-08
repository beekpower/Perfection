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

#include "util.h"
#include "math.h"

class Util {
  public:
    void drawCircle(int radius, int startDegree, int endDegree);
    void drawCircle(int radius);
    void drawPolygon(int n, int radius);
};

#endif
