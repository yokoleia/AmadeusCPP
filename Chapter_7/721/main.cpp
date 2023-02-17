#include <iostream>
#include "Triangle.h"
using namespace std;

int main()
{
    Triangle triangle1;
    Triangle triangle2;
    double temp;
    // TODO: Read and set base and height for triangle1 (use SetBase() and SetHeight())
    cin >> temp;
    triangle1.SetBase(temp);
    cin >> temp;
    triangle1.SetHeight(temp);

    // TODO: Read and set base and height for triangle2 (use SetBase() and SetHeight())
    cin >> temp;
    triangle2.SetBase(temp);
    cin >> temp;
    triangle2.SetHeight(temp);

    cout << "Triangle with smaller area:" << endl;

    // TODO: Determine smaller triangle (use GetArea())
    //       and output smaller triangle's info (use PrintInfo())
    if (triangle1.GetArea() < triangle2.GetArea())
    {
        triangle1.PrintInfo();
    }
    else
    {
        triangle2.PrintInfo();
    }
    return 0;
}