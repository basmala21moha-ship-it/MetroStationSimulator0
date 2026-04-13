#include <GL/glut.h>
#include "animation.h"
#include "Camera.h"

// ================= Camera Variables =================
Camera myCam;
bool keys[256] = { false };
int lastMX = -1, lastMY = -1;
bool mouseDown = false;

// ================= Display =================
void display() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // black background
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // الكاميرا بدل gluLookAt
    myCam.apply();

    glPushMatrix();
    glTranslatef(trainPosition, 0, 0);  // الحركة هنا
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

    glutSwapBuffers();
}

// ================= Timer =================
void timer(int v) {
    myCam.update(keys);   // تحديث حركة الكاميرا
    update(v);            // الأنيميشن الأصلي
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

// ================= Mouse =================
void mouseButton(int btn, int state, int x, int y) {
    if (btn == GLUT_LEFT_BUTTON) {
        mouseDown = (state == GLUT_DOWN);
        lastMX = x;
        lastMY = y;
    }

    if (state == GLUT_DOWN) {
        if (btn == 3) myCam.zoom(1);   // scroll up
        if (btn == 4) myCam.zoom(-1);  // scroll down
    }
}

void mouseMotion(int x, int y) {
    if (mouseDown) {
        myCam.handleMouse(x, y, lastMX, lastMY);
        lastMX = x;
        lastMY = y;
    }
}

// ================= Keyboard =================
void kbdDown(unsigned char k, int x, int y) {
    keys[k] = true;
}

void kbdUp(unsigned char k, int x, int y) {
    keys[k] = false;
}

// ================= Init =================
void init() {
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 800.0 / 600.0, 0.1, 100);

    glMatrixMode(GL_MODELVIEW);
}

// ================= Main =================
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);

    glutCreateWindow("Metro Station Simulator");

    init();

    glutDisplayFunc(display);

    glutKeyboardFunc(kbdDown);
    glutKeyboardUpFunc(kbdUp);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMotion);

    glutTimerFunc(16, timer, 0);

    glutMainLoop();
    return 0;
}
