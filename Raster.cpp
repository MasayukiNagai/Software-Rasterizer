#include "Raster.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

Raster::Raster()
  : width(0), height(0), pixels(NULL){  
}

Raster::Raster(int pWidth, int pHeight, Color pFillColor)
  : width(pWidth), height(pHeight){
  int size = width * height;
  pixels = new (nothrow) Color[size];
  if (pixels == nullptr){
      cout << "Error: the allocation of this block memory failed" << endl;
  }
  else {
    for (int i = 0; i < size; i++){
        pixels[i] = pFillColor;
    }
  }

}

Raster::~Raster(){
    delete [] pixels;
    pixels = NULL;
}

int Raster::GetWidth(){
    return width;
}

int Raster::GetHeight(){
    return height;
}

Color Raster::GetColorPixel(int x, int y){
    return pixels[width * (height-y-1) + x];
}

void Raster::SetColorPixel(int x, int y, Color pFillColor){
    pixels[width * (height-y-1) + x] = pFillColor;
}

void Raster::clear(Color pFillColor){
    for (int i = 0; i < width * height; i++){
        pixels[i] = pFillColor;
    }
}

void Raster::WriteToPPM(){
    ofstream img;
    img.open("FRAME_BUFFER.ppm");
    img << "P3" << endl;
    img << width << " " << height << endl;
    img << "255" << endl;
    for (int i = 0; i < width * height; i++){
        int r = pixels[i].red * 255;
        int g = pixels[i].green * 255;
        int b = pixels[i].blue * 255;
        img << r << " " << g << " " << b << endl;
    }
    img.close();
}

void Raster::DrawLine_DDA(float x1, float y1, float x2, float y2, Color fillColor){
    if (x1 == x2){ //vertical
        if(y1 > y2){
            swap(x1, y1, x2, y2);
        }
        x1 = round(x1);
        y1 = round(y1);
        y2 = round(y2);
        for (int y = y1; y <= y2; y++){
            SetColorPixel(x1, round(y), fillColor);
        }
    }
    else { //not vertical
        if(x1 > x2){
            swap(x1, y1, x2, y2);
        }
        float m = ((y2 - y1)/(x2 - x1)); //slope
        if (abs(m) <= 1){ //the absolute value of slope is less than 1
            float y = y1;
            x1 = round(x1);
            x2 = round(x2);
            for (int x = x1; x <= x2; x++){
                SetColorPixel(x, round(y), fillColor);
                y += m;
            }
        }
        else { //the absolute value of slope is more than 1
            m = 1/m;
            if(y1 > y2){
                swap(y1, x1, y2, x2);
            }
            y1 = round(y1);
            y2 = round(y2);
            float x = x1;
            for (int y = y1; y <= y2; y++){
                SetColorPixel(round(x), y, fillColor);
                x += m;
            }
        }
    }
}

void Raster::swap(float& x1, float& y1, float& x2, float& y2){
    float temp = x1;
    x1 = x2;
    x2 = temp;
    temp = y1;
    y1 = y2;
    y2 = temp;
}