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

    // Checkpoint 1
    // Raster test(WIDTH, HEIGHT, White);
    // test.DrawLine_DDA_Interpolated(20.0, 20.0, 20.0, 80.0, Red, Blue);
    // test.DrawLine_DDA_Interpolated(20.0, 20.0, 80.0, 20.0, Red, Green);
    // test.DrawLine_DDA_Interpolated(30.0, 80.0, 80.0, 50.0, Blue, Green);
    // test.DrawLine_DDA_Interpolated(30.0, 20.0, 80.0, 50.0, Red, Green);
    // test.DrawLine_DDA_Interpolated(30.0, 80.0, 50.0, 20.0, Blue, Green);
    // test.DrawLine_DDA_Interpolated(30.0, 20.0, 50.0, 80.0, Red, Blue);
    // test.WriteToPPM();


    // Checkpoint 2
    // Raster test(WIDTH, HEIGHT, White);
    // Triangle2D myTriangle(Vector2(-15,15), Vector2(45,80), Vector2(72,10), Red, Green, Blue);
    // test.DrawTriangle2D_DotProduct(myTriangle);
    // test.DrawTriangle2D_Barycentric(myTriangle);
    // test.WriteToPPM();


    // Checkpoint 3
    // Matrix4 A(1, 2, 3, 4,
    //           5, 6, 7, 8,
    //           9, 10, 11, 12,
    //           13, 14, 15, 16); 
    // Matrix4 B(17, 18, 19, 20,
    //           21, 22, 23, 24,
    //           25, 26, 27, 28,
    //           29, 30, 31, 32);
    // Matrix4 C = A * B;
    // A.print();
    // B.print();
    // C.print();
    
    // Vector4 v0(1, 1, 1, 1);
    // v0 = RotateZ3D(-45) * v0;
    // v0.print();

    Raster myRaster(100, 100, White);
    // Triangle3D t(Vector4(0, 0, 0, 1), Vector4(40, 0, 0, 1), Vector4(40, 40, 0, 1), Red, Blue, Green);
    // Matrix4 pMatrix;
    // pMatrix = Translate3D(10, 20, 10);
    // pMatrix = Scale3D(1.5, 2.0, 1.3);
    // pMatrix = RotateZ3D(-45); 
    // t.Transform(pMatrix);
    // myRaster.DrawTriangle3D_Barycentric(t);
    // myRaster.WriteToPPM();

    Model teapot = Model();
    teapot.ReadFromOBJFile("./teapot.obj", Red);
    Matrix4 m = Translate3D(50, 50, 0) * RotateZ3D(-45.0) * Scale3D(0.5, 0.5, 0.5);
    teapot.Transform(m);
    myRaster.DrawModel(teapot);
    myRaster.WriteToPPM();
    return 0;

}   