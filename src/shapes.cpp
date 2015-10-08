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

void Shapes::drawShape(int shape) {
  switch (shape) {
    default:
    case 0:
      drawCircle();
      break;
    case 1:
      drawHalfCircle();
      break;
    case 2:
      drawSquare();
      break;
    case 3:
      drawOffsetCircle1();
      break;
    case 4:
      drawOffsetCircle2();
      break;
    case 5:
      drawRectangle();
      break;
    case 6:
      drawRightTriangle();
      break;
    case 7:
      drawOctogon();
      break;
    case 8:
      drawCup();
      break;
    case 9:
      drawThinCylinder();
      break;
    case 10:
      drawThickCylinder();
      break;
    case 11:
      drawThickCross();
      break;
    case 12:
      drawPentagon();
      break;
    case 13:
      drawEqualTriangle();
      break;
    case 14:
      drawRhombus();
      break;
    case 15:
      drawKite();
      break;
    case 16:
      draw5Star();
      break;
    case 17:
      draw6Star();
      break;
    case 18:
      drawThinCross();
      break;
    case 19:
      drawFlower();
      break;
    case 20:
      drawQuarterCircle();
      break;
    case 21:
      drawQuad();
      break;
    case 22:
      drawCircleFlower();
      break;
    case 23:
      drawT();
      break;
    case 24:
      drawHexagon();
  }
}

int Shapes::symmetricalDegrees(int shape) {
  switch (shape) {
    default:
    case 0:
      return 360;
      break;
    case 1:
      return 1;
      break;
    case 2:
      return 4;
      break;
    case 3:
      return 2;
      break;
    case 4:
      return 2;
      break;
    case 5:
      return 2;
      break;
    case 6:
      return 1;
      break;
    case 7:
      return 8;
      break;
    case 8:
      return 1;
      break;
    case 9:
      return 2;
      break;
    case 10:
      return 2;
      break;
    case 11:
      return 4;
      break;
    case 12:
      return 5;
      break;
    case 13:
      return 3;
      break;
    case 14:
      return 2;
      break;
    case 15:
      return 1;
      break;
    case 16:
      return 5;
      break;
    case 17:
      return 6;
      break;
    case 18:
      return 2;
      break;
    case 19:
      return 5;
      break;
    case 20:
      return 1;
      break;
    case 21:
      return 2;
      break;
    case 22:
      return 5;
      break;
    case 23:
      return 1;
      break;
    case 24:
      return 6;
  }
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
  Util().drawPolygon(4, 50);
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
  Util().drawPolygon(6, 50);
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
  Util().drawPolygon(3, 50);
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
  Util().drawPolygon(5, 50);
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

void Shapes::drawRhombus() {
  glBegin(GL_POLYGON);
    glVertex2i(-50, 50);
    glVertex2i(25, 25);
    glVertex2i(50, -50);
    glVertex2i(-25, -25);
  glEnd();
  drawCenterPeg();
}

void Shapes::drawKite() {
  glBegin(GL_POLYGON);
    glVertex2i(-50, 50);
    glVertex2i(20, 20);
    glVertex2i(30, -30);
    glVertex2i(-20, -20);
  glEnd();
  // glBegin(GL_POLYGON);
  //   glVertex2i(-50, 50);
  //   glVertex2i(35, 5);
  //   glVertex2i(30, -30);
  //   glVertex2i(-5, -35);
  // glEnd();
  drawCenterPeg();
}

void Shapes::draw5Star() {
  Util().drawPolygon(5, 25);
  for (int i = 0; i < 5; i++) {
    int degree = i * (360/5);
    glPushMatrix();
      glRotatef(degree,0,0,1);
      glTranslatef(-20, 0, 0);
      glBegin(GL_POLYGON);
        glVertex2i(0, 15.5);
        glVertex2i(0, -15.5);
        glVertex2i(-31, 0);
      glEnd();
    glPopMatrix();
  }
  drawCenterPeg();
}

void Shapes::draw6Star() {
  Util().drawPolygon(6, 25);
  for (int i = 0; i < 6; i++) {
    int degree = i * (360/6);
    glPushMatrix();
      glRotatef(degree,0,0,1);
      glTranslatef(0, 21, 0);
      glBegin(GL_POLYGON);
        glVertex2i(0, 25);
        glVertex2i(-12.5, 0);
        glVertex2i(12.5, 0);
      glEnd();
    glPopMatrix();
  }
  drawCenterPeg();
}

void Shapes::drawThinCross() {
  glPushMatrix();
    glRotatef(55,0,0,1.0);
    glBegin(GL_POLYGON);
      glVertex2i(-48, 7);
      glVertex2i(48, 7);
      glVertex2i(48, -7);
      glVertex2i(-48, -7);
    glEnd();
  glPopMatrix();

  glPushMatrix();
    glRotatef(-55,0,0,1.0);
    glBegin(GL_POLYGON);
      glVertex2i(-48, 7);
      glVertex2i(48, 7);
      glVertex2i(48, -7);
      glVertex2i(-48, -7);
    glEnd();
  glPopMatrix();
  drawCenterPeg();
}

void Shapes::drawFlower() {
  Util().drawPolygon(5, 25);
  for (int i = 0; i < 5; i++) {
    int degree = i * (360/5);
    glPushMatrix();
      glRotatef(degree,0,0,1);
      glTranslatef(-20, 0, 0);
      glBegin(GL_POLYGON);
        glVertex2i(0, 15.5);
        glVertex2i(0, -15.5);
        glVertex2i(-25, -15.5);
        glVertex2i(-25, 15.5);
      glEnd();
    glPopMatrix();
  }
  drawCenterPeg();
}

void Shapes::drawQuarterCircle() {
  glPushMatrix();
    glTranslatef(-30, -30, 0);
    Util().drawCircle(75, 0, 90);
    glBegin(GL_POLYGON);
      glVertex2i(0, 77);
      glVertex2i(0, 0);
      glVertex2i(77,0);
    glEnd();
  glPopMatrix();
  drawCenterPeg();
}

void Shapes::drawQuad() {
  glBegin(GL_POLYGON);
    glVertex2i(50, 50);
    glVertex2i(-35, 50);
    glVertex2i(-50, -50);
    glVertex2i(35, -50);
  glEnd();
  drawCenterPeg();
}

void Shapes::drawCircleFlower() {
  for (int i = 0; i < 5; i++) {
    int degree = i * (360/5);
    glPushMatrix();
      glRotatef(degree,0,0,1);
      glTranslatef(-25, 0, 0);
      Util().drawCircle(22);
    glPopMatrix();
  }
  drawCenterPeg();
}

void Shapes::drawT() {
  glBegin(GL_POLYGON);
    glVertex2i(50, -15);
    glVertex2i(-50, -15);
    glVertex2i(-50, -50);
    glVertex2i(50, -50);
  glEnd();
  glBegin(GL_POLYGON);
    glVertex2i(20, -15);
    glVertex2i(-20, -15);
    glVertex2i(-20, 50);
    glVertex2i(20, 50);
  glEnd();
  drawCenterPeg();
}
