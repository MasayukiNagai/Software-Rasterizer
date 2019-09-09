#include "Raster.h"
#include <iostream>
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

}

void Raster::DrawLine_DDA(float x1, float y1, float x2, float y2, Color fillColor){

}

void swap(float x1, float y1, float x2, float y2){

}