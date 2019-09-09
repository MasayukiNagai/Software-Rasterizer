#ifndef __COLOR_H
#define __COLOR_H

#include <iostream>

struct Color {

    float red;
    float green;
    float blue;
    float alpha;

    Color();
    Color(float pRed, float pGreen, float pBlue, float pAlpha);
    void Clamp();

    Color operator+(const Color & other);
    Color operator-(const Color & other);
    Color operator*(float p);
};

#endif