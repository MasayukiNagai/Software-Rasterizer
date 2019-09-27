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

void Raster::DrawLine_DDA_Interpolated(float x1, float y1, float x2, float y2, Color color1, Color color2){
    if (x1 == x2){ //vertical
        if(y1 > y2){
            swapColor(x1, y1, x2, y2, color1, color2);
        }
        float x = round(x1);
        y1 = round(y1);
        y2 = round(y2);
        Vector2 v1(x1, y1);
        Vector2 v2(x2, y2);
        float magnitude = (v2 - v1).Magnitude();
        float ratio;
        Color fillColor;
        for (int y = y1; y <= y2; y++){
            Vector2 p(x, y);
            ratio = (p - v1).Magnitude()/magnitude;
            fillColor = color1 * (1 - ratio) + color2 * ratio;
            SetColorPixel(x, round(y), fillColor);
        }
    }
    else { //not vertical
        if(x1 > x2){
            swapColor(x1, y1, x2, y2, color1, color2);
        }
        float m = ((y2 - y1)/(x2 - x1)); //slope
        if (abs(m) <= 1){ //the absolute value of slope is less than 1
            x1 = round(x1);
            x2 = round(x2);
            Vector2 v1(x1, y1);
            Vector2 v2(x2, y2);
            float magnitude = (v2 - v1).Magnitude();
            float ratio;
            Color fillColor;
            float y = y1;
            for (int x = x1; x <= x2; x++){
                Vector2 p(x, y);
                ratio = (p - v1).Magnitude()/magnitude;
                fillColor = color1 * (1 - ratio) + color2 * ratio;
                SetColorPixel(x, round(y), fillColor);
                y += m;
            }
        }
        else { //the absolute value of slope is more than 1
            m = 1/m;
            if(y1 > y2){
                swapColor(x1, y1, x2, y2, color1, color2);
            }
            y1 = round(y1);
            y2 = round(y2);
            Vector2 v1(x1, y1);
            Vector2 v2(x2, y2);
            float magnitude = (v2 - v1).Magnitude();
            float ratio;
            Color fillColor;
            float x = x1;
            for (int y = y1; y <= y2; y++){
                Vector2 p(x, y);
                ratio = (p - v1).Magnitude()/magnitude;
                fillColor = color1 * (1 - ratio) + color2 * ratio;
                SetColorPixel(round(x), y, fillColor);
                x += m;
            }
        }
    }
}

void Raster::swapColor(float &x1, float &y1, float &x2, float &y2, Color &color1, Color &color2){
    float temp = x1;
    x1 = x2;
    x2 = temp;
    temp = y1;
    y1 = y2;
    y2 = temp;
    Color tempColor = color1;
    color1 = color2;
    color2 = tempColor;
}

void Raster::DrawTriangle2D_DotProduct(Triangle2D triangle){
    swapVector2(triangle.v0, triangle.v1, triangle.v2);
    float xmin = min(triangle.v0.x, min(triangle.v1.x, triangle.v2.x));
    float xmax = max(triangle.v0.x, max(triangle.v1.x, triangle.v2.x));
    float ymin = min(triangle.v0.y, min(triangle.v1.y, triangle.v2.y));
    float ymax = max(triangle.v0.y, max(triangle.v1.y, triangle.v2.y));

    int boundary = 0;
    if (xmin < boundary) xmin = boundary;
    if (xmax > width) xmax = width;
    if (ymin < boundary) ymin = boundary;
    if (ymax > height) ymax = height;
    
    for(int x = xmin; x < xmax; x++){
        for(int y = ymin; y < ymax; y++){
            Vector2 p(x, y);

            Vector2 edge0 = triangle.v1 - triangle.v0;
            Vector2 edgeP0 = edge0.Perpendicular();
            Vector2 g0 = p - triangle.v0;
            float result0 = edgeP0.Dot(g0);

            Vector2 edge1 = triangle.v2 - triangle.v1;
            Vector2 edgeP1 = edge1.Perpendicular();
            Vector2 g1 = p - triangle.v1;
            float result1 = edgeP1.Dot(g1);

            Vector2 edge2 = triangle.v0 - triangle.v2;
            Vector2 edgeP2 = edge2.Perpendicular();
            Vector2 g2 = p - triangle.v2;
            float result2 = edgeP2.Dot(g2);

            if(result0 >= 0 && result1 >= 0 && result2 >= 0){
                SetColorPixel(x, y, Red);
            }            
        }
    }
}

void Raster::swapVector2(Vector2 &v0, Vector2 &v1, Vector2 &v2){
    float centerX = (v0.x + v1.x + v2.x);
    float centerY = (v0.y + v1.y + v2.y);
    Vector2 center(centerX, centerY);
    float det = Determinant(v0 - center, v1 - center);
    if(det < 0){
        Vector2 temp = v1;
        v1 = v0;
        v0 = temp;
    }
}

void Raster::DrawTriangle_Barycentric(Triangle2D triangle){
    int xmin = round(min(triangle.v0.x, min(triangle.v1.x, triangle.v2.x)));
    int xmax = round(max(triangle.v0.x, max(triangle.v1.x, triangle.v2.x)));
    int ymin = round(min(triangle.v0.y, min(triangle.v1.y, triangle.v2.y)));
    int ymax = round(max(triangle.v0.y, max(triangle.v1.y, triangle.v2.y)));
    
    int boundary = 0;
    if (xmin < boundary) xmin = boundary;
    if (xmax > width) xmax = width;
    if (ymin < boundary) ymin = boundary;
    if (ymax > height) ymax = height;
    
    float lambda0;
    float lambda1;
    float lambda2;
    Color fillColor;
    for(int x = xmin; x < xmax; x++){
        for(int y = ymin; y < ymax; y++){
            Vector2 p(x, y);
            triangle.CalculateBarycentricCoordinates(p, lambda0, lambda1, lambda2);
            if(lambda0 >= 0 && lambda1 >= 0 && lambda2 >= 0){
                fillColor = triangle.c0 * lambda0 + triangle.c1 * lambda1 + triangle.c2 * lambda2;
                SetColorPixel(x, y, fillColor);
            }
        }
    }
}

