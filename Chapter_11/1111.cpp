#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

// Recursive function to create and output all permutations of the list of names.
void PrintAllPermutations(const vector<string> &permList, const vector<string> &nameList)
{
    if (permList.size() == nameList.size())
    {
        // Base case: all names have been added to the permutation list
        for (int i = 0; i < permList.size(); i++)
        {
            cout << permList[i];
            if (i < permList.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << endl;
    }
    else
    {
        vector<string> newPerm = permList;
        for (string name : nameList)
        {
            // if name is not in copyPerm.
            if ((find(newPerm.begin(), newPerm.end(), name)) == newPerm.end())
            {
                {
                    newPerm.push_back(name);
                    PrintAllPermutations(newPerm, nameList);
                    newPerm.pop_back();
                }
            }
        }
    }
}

int main()
{
    vector<string> nameList;
    vector<string> permList;
    string name;
    while (cin >> name && name != "-1")
    {
        nameList.push_back(name);
    }

    PrintAllPermutations(permList, nameList);
    return 0;
}
