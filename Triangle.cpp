#include "Triangle.h"
#include <cmath>

Triangle2D::Triangle2D()
  : v0(Vector2()), v1(Vector2()), v2(Vector2()), c0(Clear), c1(Clear), c2(Clear){ // can I use the initializer list for vector too?
}

Triangle2D::Triangle2D(Vector2 pV0, Vector2 pV1, Vector2 pV2, Color pC0, Color pC1, Color pC2)
  : v0(pV0), v1(pV1), v2(pV2), c0(pC0), c1(pC1), c2(pC2){
}

Triangle2D::Triangle2D(Triangle3D const &triangle3D){
  v0 = Vector2(triangle3D.v0.x, triangle3D.v0.y);
  v1 = Vector2(triangle3D.v1.x, triangle3D.v1.y);
  v2 = Vector2(triangle3D.v2.x, triangle3D.v2.y);
  c0 = triangle3D.c0;
  c1 = triangle3D.c1;
  c2 = triangle3D.c2;
}

void Triangle2D::CalculateBarycentricCoordinates(Vector2 P, float &lambda0, float &lambda1, float &lambda2){
    // float areaAll = abs(Determinant(this->v1 - this->v0, this->v2 - this->v0))/2;
    // float area0 = abs(Determinant(this->v1 - this->v2, P - this->v2))/2;
    // float area1 = abs(Determinant(this->v0 - this->v2, P - this->v2))/2;

    lambda0 = Determinant(this->v1 - this->v2, P - this->v2)/Determinant(this->v1 - this->v2, this->v0 - this->v2);
    lambda1 = Determinant(P - this->v2, this->v0 - this->v2)/Determinant(this->v1 - this->v2, this->v0 - this->v2);
    lambda2 = 1.0 - lambda0 - lambda1;
}

Triangle3D::Triangle3D()
  :v0(Vector4()), v1(Vector4()), v2(Vector4()), c0(Clear), c1(Clear), c2(Clear){  
}

Triangle3D::Triangle3D(Vector4 pV0, Vector4 pV1, Vector4 pV2, Color pC0, Color pC1, Color pC2)
  :v0(pV0), v1(pV1), v2(pV2), c0(pC0), c1(pC1), c2(pC2){
}  
    
void Triangle3D::Transform(Matrix4 pM){
  this->v0 = pM * this->v0;
  this->v1 = pM * this->v1;
  this->v2 = pM * this->v2;
}