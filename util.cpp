#include "util.h"

void Util::drawCircle(int radius, int startDegree, int endDegree) {
  glBegin(GL_POLYGON);
    for (int i=startDegree; i != endDegree; i++) {
      float degInRad = i*0.0174532925;
      glVertex2f(cos(degInRad)*radius,sin(degInRad)*radius);
      if (i == 360) {
        i = 0;
      }
    }
  glEnd();
}

void Util::drawCircle(int radius) {
  glBegin(GL_POLYGON);
    for (int i=0; i < 360; i++) {
      float degInRad = i*0.0174532925;
      glVertex2f(cos(degInRad)*radius,sin(degInRad)*radius);
      if (i == 360) {
        i = 0;
      }
    }
  glEnd();
}

void Util::drawPolygon(int n) {
  float angleIncrement = 360.0f / n;
  angleIncrement *= M_PI / 180.0f;
  glBegin(GL_TRIANGLE_FAN);
    float angle = 0.0f;
    for (int k = 0; k < n; ++k) {
      glVertex2f(50 * cos(angle), 50 * sin(angle));
      angle += angleIncrement;
    }
  glEnd();
}
