#include "shapes.h"

//private
void Shapes::drawCenterPeg() {
    glColor3ub(0, 0, 0);
    Util::drawCircle(5, 0, 360, true);
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

void Shapes::drawShape(int shape, bool isPiece) {
    switch (shape) {
        default:
        case 0:
            drawCircle(isPiece);
            break;
        case 1:
            drawHalfCircle(isPiece);
            break;
        case 2:
            drawSquare(isPiece);
            break;
        case 3:
            drawOffsetCircle1(isPiece);
            break;
        case 4:
            drawOffsetCircle2(isPiece);
            break;
        case 5:
            drawRectangle(isPiece);
            break;
        case 6:
            drawRightTriangle(isPiece);
            break;
        case 7:
            drawOctogon(isPiece);
            break;
        case 8:
            drawCup(isPiece);
            break;
        case 9:
            drawThinCylinder(isPiece);
            break;
        case 10:
            drawThickCylinder(isPiece);
            break;
        case 11:
            drawThickCross(isPiece);
            break;
        case 12:
            drawPentagon(isPiece);
            break;
        case 13:
            drawEqualTriangle(isPiece);
            break;
        case 14:
            drawRhombus(isPiece);
            break;
        case 15:
            drawKite(isPiece);
            break;
        case 16:
            draw5Star(isPiece);
            break;
        case 17:
            draw6Star(isPiece);
            break;
        case 18:
            drawThinCross(isPiece);
            break;
        case 19:
            drawFlower(isPiece);
            break;
        case 20:
            drawQuarterCircle(isPiece);
            break;
        case 21:
            drawQuad(isPiece);
            break;
        case 22:
            drawCircleFlower(isPiece);
            break;
        case 23:
            drawT(isPiece);
            break;
        case 24:
            drawHexagon(isPiece);
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


void Shapes::drawCircle(bool isPiece)
{
    Util::drawCircle(50, 0, 360, isPiece);
    if(isPiece) {
        drawCenterPeg();
    }
}

void Shapes::drawHalfCircle(bool isPiece) {
    glPushMatrix();
    glTranslatef(15, -15, 0);
    Util::drawCircle(48, 45, 225, isPiece);
    glPopMatrix();
    
    if(isPiece) {
        drawCenterPeg();
    }
}

void Shapes::drawSquare(bool isPiece) {
    Util::drawPolygon(4, 50, isPiece);
    if(isPiece) {
        drawCenterPeg();
    }
}

void Shapes::drawOffsetCircle1(bool isPiece) {
    glPushMatrix();
    glTranslatef(-12, -12, 0);
    Util::drawCircle(38, 45, 225, isPiece);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(11, 13, 0);
    Util::drawCircle(38, 225, 45, isPiece);
    glPopMatrix();
    if(isPiece) {
        drawCenterPeg();
    }
}

void Shapes::drawOffsetCircle2(bool isPiece) {
    glPushMatrix();
    glTranslatef(11, -13, 0);
    Util::drawCircle(38, 315, 135, isPiece);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-12, 12, 0);
    Util::drawCircle(38, 135, 315,isPiece);
    glPopMatrix();
    if(isPiece) {
        drawCenterPeg();
    }
}

void Shapes::drawHexagon(bool isPiece) {
    Util::drawPolygon(6, 50, isPiece);
    if(isPiece) {
        drawCenterPeg();
    }
}

void Shapes::drawRectangle(bool isPiece) {
    glBegin(GL_POLYGON);
        if(isPiece) {
            glColor3ub(230, 221, 42);
        } else {
            glColor3ub(64, 101, 147);
        }
        glVertex2i(-50, 35);
        glVertex2i(50, 35);
        glVertex2i(50, -35);
        glVertex2i(-50, -35);
    glEnd();
    
    if(isPiece) {
        glBegin(GL_LINE_LOOP);
            glColor3ub(0, 0, 0);
            glVertex2i(-50, 35);
            glVertex2i(50, 35);
            glVertex2i(50, -35);
            glVertex2i(-50, -35);
        glEnd();
        drawCenterPeg();
    }
}

void Shapes::drawRightTriangle(bool isPiece) {
    glPushMatrix();
    glTranslatef(25, -25, 0);
    glBegin(GL_POLYGON);
        if(isPiece) {
            glColor3ub(230, 221, 42);
        } else {
            glColor3ub(64, 101, 147);
        }
        glVertex2i(-50, 50);
        glVertex2i(25, 50);
        glVertex2i(-50, -25);
    glEnd();
    glPopMatrix();
    
    if(isPiece) {
        glPushMatrix();
        glTranslatef(25, -25, 0);
        glBegin(GL_LINE_LOOP);
            glColor3ub(0, 0, 0);
            glVertex2i(-50, 50);
            glVertex2i(25, 50);
            glVertex2i(-50, -25);
        glEnd();
        glPopMatrix();
        drawCenterPeg();
    }
}

void Shapes::drawOctogon(bool isPiece) {
    glBegin(GL_POLYGON);
        if(isPiece) {
            glColor3ub(230, 221, 42);
        } else {
            glColor3ub(64, 101, 147);
        }
        glVertex2i(0, 50);
        glVertex2i(37, 37);
        glVertex2i(50, 0);
        glVertex2i(37, -37);
        glVertex2i(0, -50);
        glVertex2i(-37, -37);
        glVertex2i(-50, 0);
        glVertex2i(-37, 37);
    glEnd();
    
    if(isPiece) {
        glBegin(GL_LINE_LOOP);
            glColor3f((float)0/255, (float)0/255, (float)0/255);
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
}

void Shapes::drawCup(bool isPiece) {
    glBegin(GL_POLYGON);
        if(isPiece) {
            glColor3ub(230, 221, 42);
        } else {
            glColor3ub(64, 101, 147);
        }
        glVertex2i(-50, 50);
        glVertex2i(50, 50);
        glVertex2i(30, -50);
        glVertex2i(-30, -50);
    glEnd();
    if(isPiece) {
        glBegin(GL_LINE_LOOP);
            glColor3ub(0, 0, 0);
            glVertex2i(-50, 50);
            glVertex2i(50, 50);
            glVertex2i(30, -50);
            glVertex2i(-30, -50);
        glEnd();
        drawCenterPeg();
    }
}

void Shapes::drawEqualTriangle(bool isPiece) {
    Util::drawPolygon(3, 50, isPiece);
    if(isPiece) {
        drawCenterPeg();
    }
}

void Shapes::drawThinCylinder(bool isPiece) {
    glPushMatrix();
    glTranslatef(-25, 25, 0);
    Util::drawCircle(25, 45, 225, isPiece);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(25, -25, 0);
    Util::drawCircle(25, 225, 45, isPiece);
    glPopMatrix();
    
    glBegin(GL_POLYGON);
        if(isPiece) {
            glColor3ub(230, 221, 42);
        } else {
            glColor3ub(64, 101, 147);
        }
        glVertex2i(-43, 7);
        glVertex2i(-7, 43);
        glVertex2i(44, -8);
        glVertex2i(8, -44);
    glEnd();
    
    if(isPiece) {
        glBegin(GL_LINE_LOOP);
            glColor3ub(0, 0, 0);
            glVertex2i(-43, 7);
            glVertex2i(-7, 43);
            glVertex2i(44, -8);
            glVertex2i(8, -44);
        glEnd();
        drawCenterPeg();
    }
}

void Shapes::drawThickCylinder(bool isPiece) {
    glPushMatrix();
    glRotatef(90,0,0,1.0);
    glPushMatrix();
    glTranslatef(-15, 15, 0);
    Util::drawCircle(35, 45, 225, isPiece);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(15, -15, 0);
    Util::drawCircle(35, 225, 45, isPiece);
    glPopMatrix();
    
    glBegin(GL_POLYGON);
        if(isPiece) {
            glColor3ub(230, 221, 42);
        } else {
            glColor3ub(64, 101, 147);
        }
        glVertex2i(-43, -7);
        glVertex2i(8, 43);
        glVertex2i(42, 8);
        glVertex2i(-4, -45);
    glEnd();
    glPopMatrix();
    
    if(isPiece) {
        glPushMatrix();
            glRotatef(90,0,0,1.0);
            
            glBegin(GL_LINE_LOOP);
                glColor3ub(0, 0, 0);
                glVertex2i(-43, -7);
                glVertex2i(8, 43);
                glVertex2i(42, 8);
                glVertex2i(-4, -45);
            glEnd();
        glPopMatrix();
        drawCenterPeg();
    }
}

void Shapes::drawPentagon(bool isPiece) {
    Util::drawPolygon(5, 50, isPiece);
    if(isPiece) {
        drawCenterPeg();
    }
}

void Shapes::drawThickCross(bool isPiece) {
    glPushMatrix();
    glRotatef(45,0,0,1.0);
    glBegin(GL_POLYGON);
        if(isPiece) {
            glColor3ub(230, 221, 42);
        } else {
            glColor3ub(64, 101, 147);
        }
        glVertex2i(-48, 20);
        glVertex2i(48, 20);
        glVertex2i(48, -20);
        glVertex2i(-48, -20);
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(-45,0,0,1.0);
        glBegin(GL_POLYGON);
        if(isPiece) {
            glColor3ub(230, 221, 42);
        } else {
            glColor3ub(64, 101, 147);
        }
        glVertex2i(-48, 20);
        glVertex2i(48, 20);
        glVertex2i(48, -20);
        glVertex2i(-48, -20);
    glEnd();
    glPopMatrix();
    
    
    if(isPiece) {
        glPushMatrix();
        glRotatef(45,0,0,1.0);
        glBegin(GL_LINE_LOOP);
            glColor3ub(0, 0, 0);
            glVertex2i(-48, 20);
            glVertex2i(48, 20);
            glVertex2i(48, -20);
            glVertex2i(-48, -20);
        glEnd();
        glPopMatrix();
        
        glPushMatrix();
        glRotatef(-45,0,0,1.0);
        glBegin(GL_LINE_LOOP);
            glColor3ub(0, 0, 0);
            glVertex2i(-48, 20);
            glVertex2i(48, 20);
            glVertex2i(48, -20);
            glVertex2i(-48, -20);
        glEnd();
        glPopMatrix();
        drawCenterPeg();
    }
}

void Shapes::drawRhombus(bool isPiece) {
    glBegin(GL_POLYGON);
        if(isPiece) {
            glColor3ub(230, 221, 42);
        } else {
            glColor3ub(64, 101, 147);
        }
        glVertex2i(-50, 50);
        glVertex2i(25, 25);
        glVertex2i(50, -50);
        glVertex2i(-25, -25);
    glEnd();
    
    if(isPiece) {
        glBegin(GL_LINE_LOOP);
            glColor3ub(0, 0, 0);
            glVertex2i(-50, 50);
            glVertex2i(25, 25);
            glVertex2i(50, -50);
            glVertex2i(-25, -25);
        glEnd();
        drawCenterPeg();
    }
}

void Shapes::drawKite(bool isPiece) {
    glBegin(GL_POLYGON);
        if(isPiece) {
            glColor3ub(230, 221, 42);
        } else {
            glColor3ub(64, 101, 147);
        }
        glVertex2i(-50, 50);
        glVertex2i(20, 20);
        glVertex2i(30, -30);
        glVertex2i(-20, -20);
    glEnd();
    
    if(isPiece) {
        glBegin(GL_LINE_LOOP);
            glColor3ub(0, 0, 0);
            glVertex2i(-50, 50);
            glVertex2i(20, 20);
            glVertex2i(30, -30);
            glVertex2i(-20, -20);
        glEnd();
        drawCenterPeg();
    }
}

void Shapes::draw5Star(bool isPiece) {
    Util::drawPolygon(5, 25, isPiece);
    for (int i = 0; i < 5; i++) {
        int degree = i * (360/5);
        glPushMatrix();
        glRotatef(degree,0,0,1);
        glTranslatef(-20, 0, 0);
        glBegin(GL_POLYGON);
            if(isPiece) {
                glColor3ub(230, 221, 42);
            } else {
                glColor3ub(64, 101, 147);
            }
            glVertex2i(0, 15.5);
            glVertex2i(0, -15.5);
            glVertex2i(-31, 0);
        glEnd();
        glPopMatrix();
    }
    
    if(isPiece) {
        for (int i = 0; i < 5; i++) {
            int degree = i * (360/5);
            glPushMatrix();
            glRotatef(degree,0,0,1);
            glTranslatef(-20, 0, 0);
            glBegin(GL_LINE_LOOP);
                glColor3ub(0, 0, 0);
                glVertex2i(0, 15.5);
                glVertex2i(0, -15.5);
                glVertex2i(-31, 0);
            glEnd();
            glPopMatrix();
        }
        drawCenterPeg();
    }
}

void Shapes::draw6Star(bool isPiece) {
    Util::drawPolygon(6, 25, isPiece);
    for (int i = 0; i < 6; i++) {
        int degree = i * (360/6);
        glPushMatrix();
        glRotatef(degree,0,0,1);
        glTranslatef(0, 21, 0);
        glBegin(GL_POLYGON);
            if(isPiece) {
                glColor3ub(230, 221, 42);
            } else {
                glColor3ub(64, 101, 147);
            }
            glVertex2i(0, 25);
            glVertex2i(-12.5, 0);
            glVertex2i(12.5, 0);
        glEnd();
        glPopMatrix();
    }
    
    if(isPiece) {
        for (int i = 0; i < 6; i++) {
            int degree = i * (360/6);
            glPushMatrix();
            glRotatef(degree,0,0,1);
            glTranslatef(0, 21, 0);
            glBegin(GL_LINE_LOOP);
                glColor3ub(0, 0, 0);
                glVertex2i(0, 25);
                glVertex2i(-12.5, 0);
                glVertex2i(12.5, 0);
            glEnd();
            glPopMatrix();
        }
        drawCenterPeg();
    }
}

void Shapes::drawThinCross(bool isPiece) {
    glPushMatrix();
    glRotatef(55,0,0,1.0);
    glBegin(GL_POLYGON);
        if(isPiece) {
            glColor3ub(230, 221, 42);
        } else {
            glColor3ub(64, 101, 147);
        }
        glVertex2i(-48, 7);
        glVertex2i(48, 7);
        glVertex2i(48, -7);
        glVertex2i(-48, -7);
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(-55,0,0,1.0);
    glBegin(GL_POLYGON);
        if(isPiece) {
            glColor3ub(230, 221, 42);
        } else {
            glColor3ub(64, 101, 147);
        }
        glVertex2i(-48, 7);
        glVertex2i(48, 7);
        glVertex2i(48, -7);
        glVertex2i(-48, -7);
    glEnd();
    glPopMatrix();
    
    if(isPiece) {
        glPushMatrix();
        glRotatef(55,0,0,1.0);
        glBegin(GL_LINE_LOOP);
            glColor3ub(0, 0, 0);
            glVertex2i(-48, 7);
            glVertex2i(48, 7);
            glVertex2i(48, -7);
            glVertex2i(-48, -7);
        glEnd();
        glPopMatrix();
        
        glPushMatrix();
        glRotatef(-55,0,0,1.0);
        glBegin(GL_LINE_LOOP);
            glColor3ub(0, 0, 0);
            glVertex2i(-48, 7);
            glVertex2i(48, 7);
            glVertex2i(48, -7);
            glVertex2i(-48, -7);
        glEnd();
        glPopMatrix();
        drawCenterPeg();
        
    }
}

void Shapes::drawFlower(bool isPiece) {
    Util::drawPolygon(5, 25, isPiece);
    for (int i = 0; i < 5; i++) {
        int degree = i * (360/5);
        glPushMatrix();
        glRotatef(degree,0,0,1);
        glTranslatef(-20, 0, 0);
        glBegin(GL_POLYGON);
            if(isPiece) {
                glColor3ub(230, 221, 42);
            } else {
                glColor3ub(64, 101, 147);
            }
            glVertex2i(0, 15.5);
            glVertex2i(0, -15.5);
            glVertex2i(-25, -15.5);
            glVertex2i(-25, 15.5);
        glEnd();
        glPopMatrix();
    }
    
    if(isPiece) {
        for (int i = 0; i < 5; i++) {
            int degree = i * (360/5);
            glPushMatrix();
            glRotatef(degree,0,0,1);
            glTranslatef(-20, 0, 0);
            glBegin(GL_LINE_LOOP);
                glColor3ub(0, 0, 0);
                glVertex2i(0, 15.5);
                glVertex2i(0, -15.5);
                glVertex2i(-25, -15.5);
                glVertex2i(-25, 15.5);
            glEnd();
            glPopMatrix();
        }
        drawCenterPeg();
    }
}

void Shapes::drawQuarterCircle(bool isPiece) {
    glPushMatrix();
    glTranslatef(-30, -30, 0);
    Util::drawCircle(75, 0, 90, isPiece);
    glBegin(GL_POLYGON);
        if(isPiece) {
            glColor3ub(230, 221, 42);
        } else {
            glColor3ub(64, 101, 147);
        }      glVertex2i(0, 77);
        glVertex2i(0, 0);
        glVertex2i(77,0);
    glEnd();
    glPopMatrix();
    
    if(isPiece) {
        glPushMatrix();
        glTranslatef(-30, -30, 0);
        Util::drawCircle(75, 0, 90, isPiece);
        glBegin(GL_LINE_LOOP);
            glColor3ub(0, 0, 0);
            glVertex2i(0, 77);
            glVertex2i(0, 0);
            glVertex2i(77,0);
        glEnd();
        glPopMatrix();
        drawCenterPeg();
    }
}

void Shapes::drawQuad(bool isPiece) {
    glBegin(GL_POLYGON);
        if(isPiece) {
            glColor3ub(230, 221, 42);
        } else {
            glColor3ub(64, 101, 147);
        }
        glVertex2i(50, 50);
        glVertex2i(-35, 50);
        glVertex2i(-50, -50);
        glVertex2i(35, -50);
    glEnd();
    if(isPiece) {
        glBegin(GL_LINE_LOOP);
            glColor3ub(0, 0, 0);
            glVertex2i(50, 50);
            glVertex2i(-35, 50);
            glVertex2i(-50, -50);
            glVertex2i(35, -50);
        glEnd();
        drawCenterPeg();
    }
}

void Shapes::drawCircleFlower(bool isPiece) {
    for (int i = 0; i < 5; i++) {
        int degree = i * (360/5);
        glPushMatrix();
        glRotatef(degree,0,0,1);
        glTranslatef(-25, 0, 0);
        Util::drawCircle(22, isPiece);
        glPopMatrix();
    }
    
    if(isPiece) {
        drawCenterPeg();
    }
}

void Shapes::drawT(bool isPiece) {
    glBegin(GL_POLYGON);
        if(isPiece) {
            glColor3ub(230, 221, 42);
        } else {
            glColor3ub(64, 101, 147);
        }
        glVertex2i(50, -15);
        glVertex2i(-50, -15);
        glVertex2i(-50, -50);
        glVertex2i(50, -50);
    glEnd();
        glBegin(GL_POLYGON);
        if(isPiece) {
            glColor3ub(230, 221, 42);
        } else {
            glColor3ub(64, 101, 147);
        }
        glVertex2i(20, -15);
        glVertex2i(-20, -15);
        glVertex2i(-20, 50);
        glVertex2i(20, 50);
    glEnd();
    if(isPiece) {
        glBegin(GL_LINE_LOOP);
            glColor3ub(0, 0, 0);
            glVertex2i(50, -15);
            glVertex2i(-50, -15);
            glVertex2i(-50, -50);
            glVertex2i(50, -50);
        glEnd();
        glBegin(GL_LINE_LOOP);
            glColor3ub(0, 0, 0);
            glVertex2i(20, -15);
            glVertex2i(-20, -15);
            glVertex2i(-20, 50);
            glVertex2i(20, 50);
        glEnd();
        drawCenterPeg();
    }
}
