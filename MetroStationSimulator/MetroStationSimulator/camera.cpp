#include "Camera.h"

Camera::Camera(float startX, float startY, float startZ) {
    x = startX; y = startY; z = startZ;
    yaw = 0.0f; pitch = 0.0f;
    fov = 60.0f;
}

void Camera::update(bool keys[256], float speed) {
    float radYaw = yaw * 3.14159f / 180.0f;
    float radPitch = pitch * 3.14159f / 180.0f;

    // حساب اتجاه النظر (Forward)
    float fx = -sinf(radYaw) * cosf(radPitch);
    float fy = sinf(radPitch);
    float fz = -cosf(radYaw) * cosf(radPitch);

    // حساب الاتجاه الجانبي (Right)
    float rx = cosf(radYaw);
    float rz = -sinf(radYaw);

    if (keys['w'] || keys['W']) { x += fx * speed; y += fy * speed; z += fz * speed; }
    if (keys['s'] || keys['S']) { x -= fx * speed; y -= fy * speed; z -= fz * speed; }
    if (keys['a'] || keys['A']) { x -= rx * speed; z -= rz * speed; }
    if (keys['d'] || keys['D']) { x += rx * speed; z += rz * speed; }
}

void Camera::apply() {
    // إعدادات الـ Projection (الزووم)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    gluPerspective(fov, (float)w / (float)h, 0.1, 1000.0);

    // إعدادات الكاميرا (الدوران والمكان)
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(-pitch, 1, 0, 0);
    glRotatef(-yaw, 0, 1, 0);
    glTranslatef(-x, -y, -z);
}

void Camera::handleMouse(int x, int y, int lastX, int lastY) {
    float sensitivity = 0.2f;
    yaw -= (x - lastX) * sensitivity;
    pitch -= (y - lastY) * sensitivity;

    if (pitch > 89.0f) pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;
}

void Camera::zoom(int direction) {
    if (direction > 0 && fov > 5.0f) fov -= 2.0f; // Zoom In
    if (direction < 0 && fov < 120.0f) fov += 2.0f; // Zoom Out
}
