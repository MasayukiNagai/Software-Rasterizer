#ifndef __VECTOR_H
#define __VECTOR_H

#include <iostream>

struct Vector2{

    float x;
    float y;

    Vector2();
    Vector2(float pX, float pY);
    
    Vector2 operator*(float scalar);
    Vector2 operator+(const Vector2 &other);
    Vector2 operator-(const Vector2 &other);
    

    float Magnitude();
    float Dot(const Vector2 &other);
    Vector2 Normalize();
    Vector2 Perpendicular();

};

std::ostream &operator<<(std::ostream &out, const Vector2 &p);
float Determinant(const Vector2 &p1, const Vector2 &p2);

#endif