#ifndef __MODEL_H
#define __MODEL_H

#include <iostream>
#include <vector>
#include <string>
#include "Triangle.h"
#include "Vector.h"
#include "Color.h"
#include "Matrix.h"

class Model{
    private:
        std::vector<Triangle3D> triangles;
        std::vector<Vector4> vertices; 
    
    public:
        Model();
        int numTriangles();
        Triangle3D operator[](int i);
        void Transform(Matrix4 pMatrix);
        void ReadFromOBJFile(std::string filepath, Color pFillColor);
        void Homogenize();
        void PerformBackfaceCulling(Vector4 eye, Vector4 spot);
};



#endif