#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int sum = 1;
    for (int i=1; i<n; i++) {
        sum += sum * i;
        cout << i+1 << " " << sum << endl;
    }
    cout << n << "! = " <<  sum;
}  