#ifndef __MATRIX_H
#define __MATRIX_H
#include "Vector.h"

struct Matrix4{
    float m11, m12, m13, m14;
    float m21, m22, m23, m24;
    float m31, m32, m33, m34;
    float m41, m42, m43, m44;

    Matrix4();
    Matrix4(float p11, float p12, float p13, float p14, float p21, float p22, float p23, float p24, float p31, float p32, float p33, float p34, float p41, float p42, float p43, float p44);

    Vector4 operator*(Vector4 other);
    Matrix4 operator*(Matrix4 other);
    Matrix4 Translate3D(float tX, float tY, float tZ);
    Matrix4 Scale3D(float sX, float sY, float sZ);
    Matrix4 RotateX3D(float degrees);
    Matrix4 RotateY3D(float degrees);
    Matrix4 RotateZ3D(float degrees);
    Matrix4 Rotate3D(float degreesX, float degreesY, float degreesZ);
    Matrix4 Rotate3D(float degreesX, Vector4 vec);
    void print();
};

float convertToRadians(float degrees);

#endif