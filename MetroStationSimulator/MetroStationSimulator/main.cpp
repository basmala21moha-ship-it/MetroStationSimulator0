#include <GL/glut.h>

void display() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // black background
    glClear(GL_COLOR_BUFFER_BIT);

    // ??? ???? ???? ?? ????
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
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);

    glutCreateWindow("Metro Station Simulator");

    init();

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}