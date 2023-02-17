#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> userInts;
    int vlen;
    int threshold;
    cin >> vlen;
    for (int i = 0; i < vlen; i++)
    {
        int temp;
        cin >> temp;
        userInts.push_back(temp);
    }
    cin >> threshold;
    for (int i = 0; i < vlen; i++)
    {
        if (userInts[i] <= threshold) {
            cout << userInts[i] << ",";
        }
    }
    cout << endl;

    return 0;
}
