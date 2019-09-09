#include <iostream>
#include "Color.h"
#include "Raster.h"

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

    Raster test(WIDTH, HEIGHT, Green);
    test.SetColorPixel(50,0, White);
    test.DrawLine_DDA(3.0, 1.0, 20.0, 80.0, Blue);
    test.DrawLine_DDA(3.0, 20.0, 80.0, 40.0, Red);
    test.DrawLine_DDA(10.0, 70.0, 10.0, 3.0, Black);
    // test.clear(Green);
    
    test.WriteToPPM();
}