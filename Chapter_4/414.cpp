#include <iostream>
using namespace std;

int main()
{

    /* Type your code here. */
    int x;
    cin >> x;
    string output = "";
    while (x > 0)
    {
        cout << x % 2;
        x = x / 2;
    }
    cout << endl;
    return 0;
}
