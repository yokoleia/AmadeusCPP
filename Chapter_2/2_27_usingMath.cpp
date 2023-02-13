#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, y, z;
    cin >> x >> y >> z;
    cout << pow(x, z) << " " << pow(x, pow(y, z)) << " " << fabs(y) << " " << sqrt(pow(x * y, z)) << endl;
}