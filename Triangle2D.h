#ifndef __TRIANGLE2D_H
#define __TRIANGLE2D_H

#include <iostream>
#include "Vector.h"
#include "Color.h"

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

#endif