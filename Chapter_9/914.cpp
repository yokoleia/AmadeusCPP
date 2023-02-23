#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    string filename;
    char c;
    string line;
    cin >> filename;
    cin >> c;
    bool found = false;
    ifstream file(filename + ".txt");
    if (!file.is_open())
    {
        return 1;
    }

    getline(file, line);
    while (!file.eof())
    {
        if (line.at(0) == c ) {
            found = true;
            //cout << line;
            while (line.find(" ") != string::npos) {
                int i = line.find(" ");
                cout << line.substr(0, i) << endl;
                line.erase(0, i+1); 
            }
            cout << line << endl;
        }
        
        getline(file, line);
    }
    if (!found) {
        cout << "No synonyms for " << filename << " begin with " << c << "." << endl;
    }

    file.close();
    return 0;
}
