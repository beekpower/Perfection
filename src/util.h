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
    void static drawCircle(int radius, int startDegree, int endDegree);
    void static drawCircle(int radius);
    void static drawPolygon(int n, int radius);
};

#endif
