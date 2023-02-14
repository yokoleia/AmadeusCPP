#include <iostream>
#include <string>
using namespace std;

int main()
{
    string fName, mName, lName;
    string line;
    getline(cin, line);
    int firstSpaceIndex = line.find(' ');
    fName = line.substr(0, firstSpaceIndex);
    line = line.substr(firstSpaceIndex + 1, line.size());
    int secondSpaceIndex = line.find(' ');

    if (secondSpaceIndex == string::npos)
    {
        lName = line;
    }
    else
    {
        mName = line.substr(0, secondSpaceIndex);
        lName = line.substr(secondSpaceIndex + 1, line.size());
    }

    string fInitial = fName.substr(0, 1) + ".";
    string mInitial = (mName.size() > 0) ? mName.substr(0, 1) + "." : "";

    cout << lName << ", " << fInitial << mInitial << endl;

    return 0;
}