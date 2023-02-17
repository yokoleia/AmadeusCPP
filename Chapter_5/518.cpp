#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> userInts;
    int vlen;
    cin >> vlen;
    for (int i = 0; i < vlen; i++)
    {
        int temp;
        cin >> temp;
        userInts.push_back(temp);
    }
    for (int i = vlen-1; i >= 0; i--)
    {
        cout << userInts[i] << ",";
    }
    cout << endl;

    return 0;
}
