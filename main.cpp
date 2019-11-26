#include <iostream>
#include "Color.h"
#include "Raster.h"
#include "Vector.h"
#include "Triangle.h"
#include "Matrix.h"

#define WIDTH 100
#define HEIGHT 100

using namespace std;

int main() {

    Raster myRaster(WIDTH, HEIGHT, White);

    Model teapot;
    teapot.ReadFromOBJFile("./teapot.obj", Red);

    Matrix4 modelMatrixTeapot = Translate3D(50, 50, -40) * RotateZ3D(45.0) * Scale3D(0.5, 0.5, 0.5);

    Matrix4 viewMatrix = LookAt(Vector4(50, 50, 30, 1), Vector4(50, 50, -40, 1), Vector4(0, 1, 0, 0));
    // teapot.Transform(viewMatrix * modelMatrixTeapot);
    cout << "viewMatrix" << endl;
    viewMatrix.print();
    Matrix4 perspectiveMatrix = Perspective(90.0, myRaster.GetWidth() / myRaster.GetHeight(), 0.01, 1000.0);
    
    Matrix4 viewportMatrix = Viewport(0, 0, myRaster.GetWidth(), myRaster.GetHeight());

    teapot.Transform(perspectiveMatrix * viewMatrix * modelMatrixTeapot);

    teapot.Homogenize();
    teapot.Transform(viewportMatrix);
    myRaster.DrawModel(teapot);
    myRaster.WriteToPPM();
    return 0;
}   