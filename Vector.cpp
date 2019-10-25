#include "Vector.h"
#include <iostream>
#include <cmath>
using namespace std;

Vector2::Vector2()
  :x(0.0), y(0.0) { 
}

Vector2::Vector2(float pX, float pY)
  :x(pX), y(pY) {     
}

Vector2 Vector2::operator*(float scalar){
    Vector2 new_vector2;
    new_vector2.x = this->x * scalar;
    new_vector2.y = this->y * scalar;
    return new_vector2;
}

Vector2 Vector2::operator+(const Vector2 &other){
    Vector2 new_vector2;
    new_vector2.x = this->x + other.x;
    new_vector2.y = this->y + other.y;
    return new_vector2;
}

Vector2 Vector2::operator-(const Vector2 &other){
    Vector2 new_vector2;
    new_vector2.x = this->x - other.x;
    new_vector2.y = this->y - other.y;
    return new_vector2;
}

float Vector2::Magnitude(){
    return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

float Vector2::Dot(const Vector2 &other){
    float product = this->x * other.x + this->y * other.y;
    return product;
}

Vector2 Vector2::Normalize(){
    Vector2 new_vector;
    float magnitude = this->Magnitude();
    new_vector.x = this->x/magnitude;
    new_vector.y = this->y/magnitude;
    return new_vector;
}

Vector2 Vector2::Perpendicular(){
    Vector2 new_vector;
    new_vector.x = -(this->y);
    new_vector.y = this->x;
    return new_vector;
}

ostream &operator<<(ostream &out, const Vector2 &p){
    out << "(" << p.x << ", " << p.y << ")";
    return out; 
}

float Determinant(const Vector2 &p1, const Vector2 &p2){
    return p1.x * p2.y - p1.y * p2.x; //I think this is the proper order of the calculation
}