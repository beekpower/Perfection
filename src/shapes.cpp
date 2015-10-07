#include "shapes.h"

//private
void Shapes::drawCenterPeg() {
  glColor3ub(0, 0, 0);
  Util().drawCircle(5, 0, 360);
}

//public
void Shapes::drawRelativeBox() {
  glBegin(GL_LINE_LOOP);
    glVertex2i(50, 50);
    glVertex2i(50,-50);
    glVertex2i(-50,-50);
    glVertex2i(-50,50);
  glEnd();
}

void Shapes::drawCircle()
{
  Util().drawCircle(50, 0, 360);
  drawCenterPeg();
}

void Shapes::drawHalfCircle() {
  glPushMatrix();
    glTranslatef(15, -15, 0);
    Util().drawCircle(48, 45, 225);
  glPopMatrix();
  drawCenterPeg();
}

void Shapes::drawSquare() {
  Util().drawPolygon(4);
  drawCenterPeg();
}

void Shapes::drawOffsetCircle1() {
  glPushMatrix();
    glTranslatef(-12, -12, 0);
    Util().drawCircle(38, 45, 225);
  glPopMatrix();
  glPushMatrix();
    glTranslatef(11, 13, 0);
    Util().drawCircle(38, 225, 45);
  glPopMatrix();
  drawCenterPeg();
}

void Shapes::drawOffsetCircle2() {
  glPushMatrix();
    glTranslatef(11, -13, 0);
    Util().drawCircle(38, 315, 135);
  glPopMatrix();
  glPushMatrix();
    glTranslatef(-12, 12, 0);
    Util().drawCircle(38, 135, 315);
  glPopMatrix();
  drawCenterPeg();
}

void Shapes::drawHexagon() {
  Util().drawPolygon(6);
  drawCenterPeg();
}

void Shapes::drawRectangle() {
  glBegin(GL_POLYGON);
    glVertex2i(-50, 35);
    glVertex2i(50, 35);
    glVertex2i(50, -35);
    glVertex2i(-50, -35);
  glEnd();
  drawCenterPeg();
}

void Shapes::drawRightTriangle() {
  glPushMatrix();
    glTranslatef(25, -25, 0);
    glBegin(GL_POLYGON);
      glVertex2i(-50, 50);
      glVertex2i(25, 50);
      glVertex2i(-50, -25);
    glEnd();
  glPopMatrix();
  drawCenterPeg();
}

void Shapes::drawOctogon() {
  glBegin(GL_POLYGON);
    glVertex2i(0, 50);
    glVertex2i(37, 37);
    glVertex2i(50, 0);
    glVertex2i(37, -37);
    glVertex2i(0, -50);
    glVertex2i(-37, -37);
    glVertex2i(-50, 0);
    glVertex2i(-37, 37);
  glEnd();
  drawCenterPeg();
}

void Shapes::drawCup() {
  glBegin(GL_POLYGON);
    glVertex2i(-50, 50);
    glVertex2i(50, 50);
    glVertex2i(30, -50);
    glVertex2i(-30, -50);
  glEnd();
  drawCenterPeg();
}

void Shapes::drawEqualTriangle() {
  Util().drawPolygon(3);
  drawCenterPeg();
}

void Shapes::drawThinCylinder() {
  glPushMatrix();
    glTranslatef(-25, 25, 0);
    Util().drawCircle(25, 45, 225);
  glPopMatrix();
  glPushMatrix();
    glTranslatef(25, -25, 0);
    Util().drawCircle(25, 225, 45);
  glPopMatrix();

  glBegin(GL_POLYGON);
    glVertex2i(-43, 7);
    glVertex2i(-7, 43);
    glVertex2i(44, -8);
    glVertex2i(8, -44);
  glEnd();
  drawCenterPeg();
}

void Shapes::drawThickCylinder() {
  glPushMatrix();
    glRotatef(90,0,0,1.0);
    glPushMatrix();
      glTranslatef(-15, 15, 0);
      Util().drawCircle(35, 45, 225);
    glPopMatrix();
    glPushMatrix();
      glTranslatef(15, -15, 0);
      Util().drawCircle(35, 225, 45);
    glPopMatrix();

    glBegin(GL_POLYGON);
      glVertex2i(-43, -7);
      glVertex2i(8, 43);
      glVertex2i(42, 8);
      glVertex2i(-4, -45);
    glEnd();
  glPopMatrix();
  drawCenterPeg();
}

void Shapes::drawPentagon() {
  Util().drawPolygon(5);
  drawCenterPeg();
}

void Shapes::drawThickCross() {
  glPushMatrix();
    glRotatef(45,0,0,1.0);
    glBegin(GL_POLYGON);
      glVertex2i(-48, 20);
      glVertex2i(48, 20);
      glVertex2i(48, -20);
      glVertex2i(-48, -20);
    glEnd();
  glPopMatrix();

  glPushMatrix();
    glRotatef(-45,0,0,1.0);
    glBegin(GL_POLYGON);
      glVertex2i(-48, 20);
      glVertex2i(48, 20);
      glVertex2i(48, -20);
      glVertex2i(-48, -20);
    glEnd();
  glPopMatrix();
  drawCenterPeg();
}
