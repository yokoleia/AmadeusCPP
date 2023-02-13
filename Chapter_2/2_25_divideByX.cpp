#include <iostream>
using namespace std;

int main() {
    int userNum;
    int x;

    cin >> userNum >> x;

    userNum /= x;
    cout << userNum << " ";

    userNum /= x;
    cout << userNum << " ";

    userNum /= x;
    cout << userNum << endl;

    return 0;
}