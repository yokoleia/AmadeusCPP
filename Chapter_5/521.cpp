#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    vector<double> userVals;
    int vlen;
    double max;
    cin >> vlen;
    for (int i = 0; i < vlen; i++)
    {
        double temp;
        cin >> temp;
        if (i == 0) {
            max = temp;
        } else {
            max = (temp> max) ? temp : max;
        }
        userVals.push_back(temp);
    }

    cout << fixed << setprecision(2);
    for (int i = 0; i < vlen; i++)
    {
        cout << userVals[i] / max << " ";

    }
    cout << endl;

    return 0;
}
