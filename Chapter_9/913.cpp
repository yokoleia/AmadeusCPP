#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    string filename;

    cin >> filename;

    ifstream file(filename);
    if (!file.is_open())
    {
        return 1;
    }

    string line;
    getline(file, line);
    while (!file.eof())
    {
        istringstream iss(line);
        string temp;
        vector<string> tempVector;

        string category;
        string type;
        string name;
        string available;
        getline(iss, category, '\t');
        getline(iss, type, '\t');
        getline(iss, name, '\t');
        getline(iss, available, '\t');
        if (available == "Available")
        {
            cout << type << " (" << category << ") -- " << name << endl;
            // Ham sandwich (Sandwiches) -- Classic ham sandwich
        }

        getline(file, line);
    }

    file.close();
    return 0;
}
