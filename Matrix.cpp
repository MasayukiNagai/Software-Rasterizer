#include "Matrix.h"
#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

Matrix4::Matrix4()
  :m11(1), m12(0), m13(0), m14(0), m21(0), m22(1), m23(0), m24(0), m31(0), m32(0), m33(1), m34(0), m41(0), m42(0), m43(0), m44(1){
}

Matrix4::Matrix4(float p11, float p21, float p31, float p41, float p12, float p22, float p32, float p42, float p13, float p23, float p33, float p43, float p14, float p24, float p34, float p44)
  :m11(p11), m12(p12), m13(p13), m14(p14), m21(p21), m22(p22), m23(p23), m24(p24), m31(p31), m32(p32), m33(p33), m34(p34), m41(p41), m42(p42), m43(p43), m44(p44){
}

Vector4 Matrix4::operator*(Vector4 other){
    Vector4 new_vector;
    new_vector.x = m11 * other.x + m21 * other.y + m31 * other.z + m41 * other.w;
    new_vector.y = m12 * other.x + m22 * other.y + m32 * other.z + m42 * other.w;
    new_vector.z = m13 * other.x + m23 * other.y + m33 * other.z + m43 * other.w;
    new_vector.w = m14 * other.x + m24 * other.y + m34 * other.z + m44 * other.w;

    return new_vector;
}

Matrix4 Matrix4::operator*(Matrix4 other){
    Matrix4 new_matrix;
    new_matrix.m11 = this->m11 * other.m11 + this->m21 * other.m12 + this->m31 * other.m13 + this->m41 * other.m14;
    new_matrix.m12 = this->m12 * other.m11 + this->m22 * other.m12 + this->m32 * other.m13 + this->m42 * other.m14;
    new_matrix.m13 = this->m13 * other.m11 + this->m23 * other.m12 + this->m33 * other.m13 + this->m43 * other.m14;
    new_matrix.m14 = this->m14 * other.m11 + this->m24 * other.m12 + this->m34 * other.m13 + this->m44 * other.m14;
    new_matrix.m21 = this->m11 * other.m21 + this->m21 * other.m22 + this->m31 * other.m23 + this->m41 * other.m24;
    new_matrix.m22 = this->m12 * other.m21 + this->m22 * other.m22 + this->m32 * other.m23 + this->m42 * other.m24;
    new_matrix.m23 = this->m13 * other.m21 + this->m23 * other.m22 + this->m33 * other.m23 + this->m43 * other.m24;
    new_matrix.m24 = this->m14 * other.m21 + this->m24 * other.m22 + this->m34 * other.m23 + this->m44 * other.m24;
    new_matrix.m31 = this->m11 * other.m31 + this->m21 * other.m32 + this->m31 * other.m33 + this->m41 * other.m34;
    new_matrix.m32 = this->m12 * other.m31 + this->m22 * other.m32 + this->m32 * other.m33 + this->m42 * other.m34;
    new_matrix.m33 = this->m13 * other.m31 + this->m23 * other.m32 + this->m33 * other.m33 + this->m43 * other.m34;
    new_matrix.m34 = this->m14 * other.m31 + this->m24 * other.m32 + this->m34 * other.m33 + this->m44 * other.m34;
    new_matrix.m41 = this->m11 * other.m41 + this->m21 * other.m42 + this->m31 * other.m43 + this->m41 * other.m44;
    new_matrix.m42 = this->m12 * other.m41 + this->m22 * other.m42 + this->m32 * other.m43 + this->m42 * other.m44;
    new_matrix.m43 = this->m13 * other.m41 + this->m23 * other.m42 + this->m33 * other.m43 + this->m43 * other.m44;
    new_matrix.m44 = this->m14 * other.m41 + this->m24 * other.m42 + this->m34 * other.m43 + this->m44 * other.m44;

    return new_matrix;
}

void Matrix4::print(){
    cout << this->m11 << ", " << this->m21 << ", " << this->m31 << ", " << this->m41 << endl;
    cout << this->m12 << ", " << this->m22 << ", " << this->m32 << ", " << this->m42 << endl;
    cout << this->m13 << ", " << this->m23 << ", " << this->m33 << ", " << this->m43 << endl;
    cout << this->m14 << ", " << this->m24 << ", " << this->m34 << ", " << this->m44 << endl;
}

Matrix4 Translate3D(float tX, float tY, float tZ){
    Matrix4 translate(1, 0, 0, tX,
                      0, 1, 0, tY,
                      0, 0, 1, tZ,
                      0, 0, 0, 1);
    return translate;
}

Matrix4 Scale3D(float sX, float sY, float sZ){
    Matrix4 scale(sX, 0, 0, 0,
                  0, sY, 0, 0,
                  0, 0, sZ, 0,
                  0, 0, 0, 1);
    return scale;
}

Matrix4 RotateX3D(float degrees){
    float a = convertToRadians(degrees);
    Matrix4 rotateX(1, 0, 0, 0,
                    0, cos(a), sin(a), 0,
                    0, -sin(a), cos(a), 0,
                    0, 0, 0, 1);
    return rotateX;
}

Matrix4 RotateY3D(float degrees){
    float a = convertToRadians(degrees);
    Matrix4 rotateY(cos(a), 0, -sin(a), 0,
                    0, 1, 0, 0,
                    sin(a), 0, cos(a), 0,
                    0, 0, 0, 1);
    return  rotateY;
}

Matrix4 RotateZ3D(float degrees){
    float a = convertToRadians(degrees);
    Matrix4 rotateZ(cos(a), sin(a), 0, 0,
                    -sin(a), cos(a), 0, 0, 
                    0,  0, 1, 0,
                    0, 0, 0, 1);
    return rotateZ;
}

Matrix4 Rotate3D(float degreesX, float degreesY, float degreesZ){
    Matrix4 new_matrix = RotateX3D(degreesX) * RotateY3D(degreesY) * RotateZ3D(degreesZ);
    return new_matrix;
}

Matrix4 Rotate3D(float degrees, Vector4 vec){
    float a = atanf(vec.x / vec.z);
    float b = acosf(vec.y / vec.Magnitude());
    Matrix4 new_matrix = RotateY3D(-a) * RotateX3D(-b) * RotateY3D(degrees) * RotateX3D(b) * RotateY3D(a);
    return new_matrix;
}

float convertToRadians(float degrees){
    float radians = degrees * M_PI / 180.0;
    return radians;
}




