#include "Color.h"
#include <iostream>
#include <string>
using namespace std;

#define Red Color::Color(1.0, 0.0, 0.0, 1.0)
#define Green Color::Color(0.0, 1.0, 0.0, 1.0)
#define Blue Color::Color(0.0, 0.0, 1.0, 1.0)
#define Black Color::Color(1.0, 1.0, 1.0, 1.0)
#define White Color::Color(0.0, 0.0, 0.0, 1.0)
#define Clear Color::Color(1.0, 1.0, 1.0, 0.0)



Color::Color(){
    red = 1.0;
    green = 1.0;
    blue = 1.0;
    alpha = 1.0;
}

Color::Color(float pRed, float pGreen, float pBlue, float pAlpha){
    red = pRed;
    green = pGreen;
    blue = pBlue;
    alpha = pAlpha;
    Clamp();
}

void Color::Clamp(){
    if (red > 1.0) {
        red = 1.0;
    } else if (red < 0.0){
        red = 0.0;
    }

    if (green > 1.0) {
        green = 1.0;
    } else if (green < 0.0){
        green = 0.0;
    }

    if (blue > 1.0) {
        blue = 1.0;
    } else if (blue < 0.0){
        blue = 0.0;
    }

    if (alpha > 1.0) {
        alpha = 1.0;
    } else if (alpha < 0.0){
        alpha = 0.0;
    }

}

Color Color::operator+(const Color & other){
    Color new_color;
    new_color.red = this->red + other.red;
    new_color.green = this->green + other.blue;
    new_color.blue = this->blue + other.blue;
    new_color.alpha = this->alpha + other.alpha;

    new_color.Clamp();
    return new_color;
}

Color Color::operator-(const Color & other){
    Color new_color;
    new_color.red = this->red - other.red;
    new_color.green = this->green - other.blue;
    new_color.blue = this->blue - other.blue;
    new_color.alpha = this->alpha - other.alpha;

    new_color.Clamp();
    return new_color;
}

Color Color::operator*(float p){
    Color new_color;
    new_color.red = p * this->red ;
    new_color.green = p * this->green;
    new_color.blue = p * this->blue;
    new_color.alpha = p * this->alpha;

    new_color.Clamp();
    return new_color;
}

int main(){

    cout << "----------  Overload the addition ----------" << endl;
    Color c1(1,0, 0.25, 0.25, 0.50);
    Color c2(0.0, 0.5, 1.0, 0.60);
    Color c3 = c1 + c2;
    cout << "Color c1: Red " << c1.red << ", Green" << c1.green << ", Blue" << c1.blue << ", Alpha" << c1.alpha << endl;
    cout << "Color c2: Red " << c2.red << ", Green" << c2.green << ", Blue" << c2.blue << ", Alpha" << c2.alpha << endl;
    cout << "Color c3 = c1 + c2" << endl;
    cout << "Color c3: Red " << c3.red << ", Green" << c3.green << ", Blue" << c3.blue << ", Alpha" << c3.alpha << endl;

    cout << "----------  Overload the addition ----------" << endl;
    Color c4 = c2 - c1;
    cout << "Color c4 = c2 - c1" << endl;
    cout << "Color c4: Red " << c4.red << ", Green" << c4.green << ", Blue" << c4.blue << ", Alpha" << c4.alpha << endl;

    cout << "----------  Overload the multiplication ----------" << endl;
    Color c5 = c1 * 1.5
    cout << "Color c5 = c1 * 1.5" << endl;
    cout << "Color c5: Red " << c5.red << ", Green" << c5.green << ", Blue" << c5.blue << ", Alpha" << c5.alpha << endl;

} 