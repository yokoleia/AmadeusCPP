#include <iostream>
using namespace std;

void SwapValues(int &userVal1, int &userVal2, int &userVal3, int &userVal4)
{
    int temp = userVal1;
    userVal1 = userVal2;
    userVal2 = temp;
    temp = userVal3;
    userVal3 = userVal4;
    userVal4 = temp;
}

int main()
{
    int u1, u2, u3, u4;
    cin >> u1 >> u2 >> u3 >> u4;

    SwapValues(u1, u2, u3, u4);
    cout << u1 << " " << u2 << " " << u3 << " " << u4 << endl;
    return 0;
}