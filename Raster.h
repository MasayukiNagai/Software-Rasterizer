#ifndef __RASTER_H
#define __RASTER_H

#include "Color.h"
#include <iostream>
#include <string>
#include <vector>

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
        void Clear(Color pFillColor);
        void WriteToPPM();
    
    private:
        int height;
        int width;
        Color* pixels;

};

#endif