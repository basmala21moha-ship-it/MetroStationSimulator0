#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glut.h>
#include <cmath>

class Camera {
public:
    // المتغيرات
    float x, y, z;
    float yaw, pitch;
    float fov;

    // المشيد (Constructor)
    Camera(float startX = 0.0f, float startY = 3.0f, float startZ = 15.0f);

    // الدوال الأساسية
    void update(bool keys[256], float speed = 0.15f); // تحديث الحركة
    void apply();                                    // تطبيق الكاميرا على المشهد
    void handleMouse(int x, int y, int lastX, int lastY); // دوران الماوس
    void zoom(int direction);                        // الزووم
};

#endif
