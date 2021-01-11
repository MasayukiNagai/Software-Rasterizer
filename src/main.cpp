#include <iostream>
#include "Color.h"
#include "Raster.h"
#include "Vector.h"
#include "Triangle.h"
#include "Matrix.h"

#define WIDTH 100
#define HEIGHT 100

using namespace std;

void pipeline_test(){
    Raster myRaster(WIDTH, HEIGHT, White);
    
    Model teapot;
    teapot.ReadFromOBJFile("./teapot.obj", Red);
    Matrix4 modelMatrixTeapot = Translate3D(50, 50, -40) * RotateZ3D(45.0) * Scale3D(0.5, 0.5, 0.5);
    Matrix4 viewMatrix = LookAt(Vector4(50, 50, 30, 1), Vector4(50, 50, -40, 1), Vector4(0, 1, 0, 0));
    Matrix4 perspectiveMatrix = Perspective(90.0, myRaster.GetWidth() / myRaster.GetHeight(), 0.01, 1000.0);
    Matrix4 viewportMatrix = Viewport(0, 0, myRaster.GetWidth(), myRaster.GetHeight());
    // Matrix4 viewportMatrix = Viewport(40, 20, 50, 50);
    teapot.Transform(perspectiveMatrix * viewMatrix * modelMatrixTeapot);
    teapot.Homogenize();
    teapot.Transform(viewportMatrix);
    // Matrix4 orthographicMatrix = Orthographic(-100, 100, -100, 100, -100, 100);
    // teapot.transform(viewportMatrix * orthographicMatrix * viewMatrix * modelMatrixTeapot);
    myRaster.DrawModel(teapot);
    myRaster.WriteToPPM();
}

void depth_buffer_test(){
    Raster myRaster(WIDTH, HEIGHT, White);
    
    Model teapot, bunny;
    teapot.ReadFromOBJFile("./teapot.obj", Red);
    bunny.ReadFromOBJFile("./bunny.obj", Blue);
    Matrix4 modelMatrixTeapot = Translate3D(50, 50, -60) * RotateZ3D(45.0) * Scale3D(0.5, 0.5, 0.5);
    Matrix4 modelMatrixBunny = Translate3D(70, 30, -60) * RotateZ3D(-20.0) * Scale3D(500, 500, 500);

    Matrix4 viewMatrix = LookAt(Vector4(50, 50, 30, 1), Vector4(50, 50, -40, 1), Vector4(0, 1, 0, 0));
    Matrix4 perspectiveMatrix = Perspective(90.0, myRaster.GetWidth() / myRaster.GetHeight(), 0.01, 1000.0);
    Matrix4 viewportMatrix = Viewport(0, 0, myRaster.GetWidth(), myRaster.GetHeight());

    teapot.Transform(perspectiveMatrix * viewMatrix * modelMatrixTeapot);
    bunny.Transform(perspectiveMatrix * viewMatrix * modelMatrixBunny);

    teapot.Homogenize();
    bunny.Homogenize();
    
    teapot.Transform(viewportMatrix);
    bunny.Transform(viewportMatrix);
    
    myRaster.DrawModel(teapot);
    myRaster.DrawModel(bunny);
    myRaster.WriteToPPM();
}

void backface_culling_test(){
    Raster myRaster(WIDTH, HEIGHT, White);

    Model teapot, bunny;
    teapot.ReadFromOBJFile("./teapot.obj", Red);
    Matrix4 modelMatrixTeapot = Translate3D(50, 50, -30) * RotateZ3D(45.0) * Scale3D(0.5, 0.5, 0.5);

    Vector4 eye(50, 50, 30, 1);
    Vector4 spot(50, 50, -30, 1);
    teapot.PerformBackfaceCulling(eye, spot);

    //Matrix4 viewMatrix = LookAt(Vector4(-50, 50, -30, 1), spot, Vector4(0, 1, 0, 0));
    Matrix4 viewMatrix = LookAt(eye, spot, Vector4(0, 1, 0, 0));
    Matrix4 perspectiveMatrix = Perspective(70.0, myRaster.GetWidth() / myRaster.GetHeight(), 0.01, 88.5);
    Matrix4 viewportMatrix = Viewport(0, 0, myRaster.GetWidth(), myRaster.GetHeight());

    teapot.Transform(perspectiveMatrix * viewMatrix * modelMatrixTeapot);
    teapot.Homogenize();
    teapot.Transform(viewportMatrix);

    myRaster.DrawModel(teapot);
    myRaster.WriteToPPM();
}

int main() {

    // pipeline_test();
    // depth_buffer_test();
    backface_culling_test();
}   