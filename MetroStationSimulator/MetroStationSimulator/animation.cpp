#include <GL/glut.h>
#include "animation.h"

// بداية القطر بره الشاشة
float trainPosition = -10.0f;

// ================= Animation Loop =================
void update(int value) {

    // حركة القطر (يمين)
    trainPosition += 0.05f;

    // إعادة رسم الشاشة
    glutPostRedisplay();

    // تكرار كل 16ms ≈ 60 FPS
    glutTimerFunc(16, update, 0);
} 
