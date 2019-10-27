#include <iostream>
#include "Color.h"
#include "Raster.h"
#include "Vector.h"
#include "Triangle2D.h"
#include "Matrix.h"

#define WIDTH 100
#define HEIGHT 100

using namespace std;

int main() {
    Color c1(1.0, 0.25, 0.25, 0.50);
    Color c2(0.0, 0.5, 1.0, 0.60);

    // cout << "----------  Overload the addition ----------" << endl;
    // Color c3 = c1 + c2;
    // cout << "Color c1: Red " << c1.red << ", Green" << c1.green << ", Blue" << c1.blue << ", Alpha" << c1.alpha << endl;
    // cout << "Color c2: Red " << c2.red << ", Green" << c2.green << ", Blue" << c2.blue << ", Alpha" << c2.alpha << endl;
    // cout << "Color c3 = c1 + c2" << endl;
    // cout << "Color c3: Red " << c3.red << ", Green" << c3.green << ", Blue" << c3.blue << ", Alpha" << c3.alpha << endl;

    // cout << "----------  Overload the subtraction ----------" << endl;
    // Color c4 = c2 - c1;
    // cout << "Color c4 = c2 - c1" << endl;
    // cout << "Color c4: Red " << c4.red << ", Green" << c4.green << ", Blue" << c4.blue << ", Alpha" << c4.alpha << endl;

    // cout << "----------  Overload the multiplication ----------" << endl;
    // Color c5 = c1 * 1.5;
    // cout << "Color c5 = c1 * 1.5" << endl;
    // cout << "Color c5: Red " << c5.red << ", Green" << c5.green << ", Blue" << c5.blue << ", Alpha" << c5.alpha << endl;

    // cout << "----------  Preprocessor Directives ----------" << endl;
    // Color c6 = Red;
    // cout << "Color c6: Red " << c6.red << ", Green" << c6.green << ", Blue" << c6.blue << ", Alpha" << c6.alpha << endl;

    // Raster test(WIDTH, HEIGHT, Green);
    // test.SetColorPixel(50,0, White);
    // test.DrawLine_DDA(20.0, 20.0, 20.0, 80.0, Blue);
    // test.DrawLine_DDA(20.0, 20.0, 45.0, 80.0, Clear);
    // test.DrawLine_DDA(3.0, 20.0, 80.0, 40.0, Red);
    // test.DrawLine_DDA(10.0, 70.0, 10.0, 3.0, Black);
    // test.DrawLine_DDA(10.0, 10.0, 80.0, 10.0, White);
    // test.WriteToPPM();

    // Vector2 v1(2.1, 3.4);
    // Vector2 v2(-5.6, 2.5);

    // cout << "----------  Overload the multiplication ----------" << endl;
    // Vector2 v3 = v1 * 2;
    // cout << v3 << endl;

    // cout << "----------  Overload the addition ----------" << endl;
    // Vector2 v4 = v1 + v2;
    // cout << v4 << endl;

    // cout << "----------  Overload the subtraction ----------" << endl;
    // Vector2 v5 = v1 - v2;
    // cout << v5 << endl; 

    // cout << "----------  Magnitude ----------" << endl;
    // cout << v1.Magnitude() << endl;

    // cout << "----------  Dot ----------" << endl;
    // cout << v1.Dot(v2) << endl;

    // cout << "----------  Normalize ----------" << endl;
    // cout << v1.Normalize() << endl;

    // cout << "----------  Perpendicular ----------" << endl;
    // cout << v1.Perpendicular() << endl;

    // cout << "----------  Determinant ----------" << endl;
    // cout << Determinant(v1, v2) << endl;

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
    // test.DrawTriangle_Barycentric(myTriangle);
    // test.WriteToPPM();


    // Checkpoint 3
    Matrix4 I;
    I.print();
    Matrix4 A(1, 2, 3, 4,
              5, 6, 7, 8,
              9, 10, 11, 12,
              13, 14, 15, 16); 
    Matrix4 B(17, 18, 19, 20,
              21, 22, 23, 24,
              25, 26, 27, 28,
              29, 30, 31, 32);
    Matrix4 C = A * B;
    A.print();
    B.print();
    C.print();
}   