#include "Triangle2D.h"

Triangle2D::Triangle2D()
  : c0(Clear), c1(Clear), c2(Clear){ // can I use the initializer list for vector too?
    Vector2 defaultVector;
    v0 = defaultVector;
    v1 = defaultVector;
    v2 = defaultVector;
}

Triangle2D::Triangle2D(Vector2 pV0, Vector2 pV1, Vector2 pV2, Color pC0, Color pC1, Color pC2)
  : v0(pV0), v1(pV1), v2(pV2), c0(pC0), c1(pC1), c2(pC2){
}

