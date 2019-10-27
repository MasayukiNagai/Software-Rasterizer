#ifndef __TRIANGLE_H
#define __TRIANGLE_H

#include <iostream>
#include "Vector.h"
#include "Color.h"
#include "Matrix.h"

struct Triangle2D{
    
    Vector2 v0;
    Vector2 v1;
    Vector2 v2;
    Color c0;
    Color c1;
    Color c2;

    Triangle2D();
    Triangle2D(Vector2 pV0, Vector2 pV1, Vector2 pV2, Color pC0, Color pC1, Color pC2);
    void CalculateBarycentricCoordinates(Vector2 P, float &lambda1, float &lambda2, float &lambda3);
};

struct Triangle3D{
    Vector4 v0, v1, v2;
    Color c0, c1, c2;

    Triangle3D();
    Triangle3D(Vector4 pV0, Vector4 pV1, Vector4 pV2, Color pC0, Color pC1, Color pC2);
    Triangle3D Transform(Matrix4 pM);
};

#endif