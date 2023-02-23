#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
// Include any necessary libraries here.

using namespace std;

int main()
{
    ifstream inFS;
    string fileName;
    string line;

    cin >> fileName;

    inFS.open(fileName);
    if (inFS.is_open())
    {

        getline(inFS, line);
        while (!inFS.eof())
        {
            int replaceIndex = line.find("_photo.jpg");
            // string outputString = (inFS.eof()) ? "" : ;
            cout << line.replace(replaceIndex, 10, "_info.txt") << endl;
            getline(inFS, line);
        }
        inFS.close();
    }

    /* Type your code here. */

    return 0;
}
