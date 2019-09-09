#ifndef __RASTER_H
#define __RASTER_H

#include "Color.h"
#include <iostream>

using namespace std;
class Raster {
    public:
        Raster();
        Raster(int pWidth, int pHeight, Color pFillColor);
        ~Raster();
        
        int GetWidth();
        int GetHeight();
        Color GetColorPixel(int x, int y);
        void SetColorPixel(int x, int y, Color pFillColor);
        void clear(Color pFillColor);
        void WriteToPPM();
        void DrawLine_DDA(float x1, float y1, float x2, float y2, Color fillColor);
        void swap(float &x1, float &y1, float &x2, float &y2);
    
    private:
        int height;
        int width;
        Color* pixels;

};

#endif