#include <iostream>
using namespace std;

int main() {
    int a, b, c, out;
    cin >> a >> b >> c;

    if (a > b)
    {
        if (b > c)
        {
            out = c;
        }
        else
        {
            out = b;
        }
    }
    else
    {
        if (a > c)
        {
            out = c;
        }
        else
        {
            out = a;
        }
    }
    cout << out << endl;
    return 0;
}


