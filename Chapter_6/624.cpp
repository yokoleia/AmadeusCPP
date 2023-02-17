#include <iostream>
#include <vector>
using namespace std;

void SortVector(vector<int> &myVec)
{
    int n = myVec.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (myVec[j] < myVec[j + 1])
            {
                int temp = myVec[j];
                myVec[j] = myVec[j + 1];
                myVec[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int countNums;
    cin >> countNums;

    vector<int> myVec(countNums);

    for (int i = 0; i < countNums; i++)
    {
        cin >> myVec[i];
    }

    SortVector(myVec);

    for (int i = 0; i < countNums; i++)
    {
        cout << myVec[i] << ",";
    }
    cout << endl;
    return 0;
}