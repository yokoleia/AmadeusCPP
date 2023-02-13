#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;

    long long product = n1 * n2 * n3 * n4;
    int average = (n1 + n2 + n3 + n4) / 4;

    cout << product << " " << average << endl;

    double fpProduct = static_cast<double>(n1) * n2 * n3 * n4;
    double fpAverage = (n1 + n2 + n3 + n4) / 4.0;

    cout << fixed << setprecision(3) << fpProduct << " " << fpAverage << endl;
}
