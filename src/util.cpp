#include "util.h"

void Util::drawCircle(int radius, int startDegree, int endDegree, bool drawBorder) {
  glBegin(GL_POLYGON);
  glColor3ub(230, 221, 42);
    for (int i=startDegree; i != endDegree; i++) {
      float degInRad = i*0.0174532925;
      glVertex2f(cos(degInRad)*radius,sin(degInRad)*radius);
      if (i == 360) {
        i = 0;
      }
    }
  glEnd();
    

    if(drawBorder) {
        glBegin(GL_LINE_LOOP);
        glColor3ub(0, 0, 0);
        for (int i=startDegree; i != endDegree; i++) {
            float degInRad = i*0.0174532925;
            glVertex2f(cos(degInRad)*radius,sin(degInRad)*radius);
            if (i == 360) {
                i = 0;
            }
        }
        glEnd();
    }
}

void Util::drawCircle(int radius, bool drawBorder) {
  glBegin(GL_POLYGON);
    glColor3ub(230, 221, 42);
    for (int i=0; i < 360; i++) {
      float degInRad = i*0.0174532925;
      glVertex2f(cos(degInRad)*radius,sin(degInRad)*radius);
      if (i == 360) {
        i = 0;
      }
    }
  glEnd();
    
    if(drawBorder) {
        glBegin(GL_LINE_LOOP);
        glColor3ub(0, 0, 0);
        for (int i=0; i < 360; i++) {
            float degInRad = i*0.0174532925;
            glVertex2f(cos(degInRad)*radius,sin(degInRad)*radius);
            if (i == 360) {
                i = 0;
            }
        }
        glEnd();
    }
}

void Util::drawPolygon(int n, int radius, bool drawBorder) {
  float angleIncrement = 360.0f / n;
  angleIncrement *= M_PI / 180.0f;
  glBegin(GL_TRIANGLE_FAN);
    glColor3ub(230, 221, 42);
    float angle = 0.0f;
    for (int k = 0; k < n; ++k) {
      glVertex2f(radius * cos(angle), radius * sin(angle));
      angle += angleIncrement;
    }
  glEnd();
    
    if(drawBorder) {
        glBegin(GL_LINE_LOOP);
        glColor3ub(0, 0, 0);
        float angle = 0.0f;
        for (int k = 0; k < n; ++k) {
            glVertex2f(radius * cos(angle), radius * sin(angle));
            angle += angleIncrement;
        }
        glEnd();
    }
}
