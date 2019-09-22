#include "Triangle2D.h"
#include <cmath>

Triangle2D::Triangle2D()
  : v0(Vector2()), v1(Vector2()), v2(Vector2()), c0(Clear), c1(Clear), c2(Clear){ // can I use the initializer list for vector too?
}

Triangle2D::Triangle2D(Vector2 pV0, Vector2 pV1, Vector2 pV2, Color pC0, Color pC1, Color pC2)
  : v0(pV0), v1(pV1), v2(pV2), c0(pC0), c1(pC1), c2(pC2){
}

void Triangle2D::CalculateBarycentricCoordinates(Vector2 P, float &lambda0, float &lambda1, float &lambda2){
    // float areaAll = abs(Determinant(this->v1 - this->v0, this->v2 - this->v0))/2;
    // float area0 = abs(Determinant(this->v1 - this->v2, P - this->v2))/2;
    // float area1 = abs(Determinant(this->v0 - this->v2, P - this->v2))/2;

    lambda0 = Determinant(this->v1 - this->v2, P - this->v2)/Determinant(this->v1 - this->v2, this->v0 - this->v2);
    lambda1 = Determinant(P - this->v2, this->v0 - this->v2)/Determinant(this->v1 - this->v2, this->v0 - this->v2);
    lambda2 = 1.0 - lambda0 - lambda1;
}