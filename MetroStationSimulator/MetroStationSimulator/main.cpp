#include <GL/glut.h>
#include "animation.h"
void display() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // black background
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glLoadIdentity();
     gluLookAt(0, 3, 10, 0, 0, 0, 0, 1, 0);
    glPushMatrix();
    glTranslatef(trainPosition, 0, 0);  //  الحركة هنا
    glColor3f(1.0, 0.0, 0.0); // أحمر
    glutSolidCube(2); // dummy train
    glPopMatrix();
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0); // red
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();

    glutSwapBuffers(); // ??? ?? GLUT_DOUBLE
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 800.0 / 600.0, 0.1, 100);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);

    glutCreateWindow("Metro Station Simulator");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}
