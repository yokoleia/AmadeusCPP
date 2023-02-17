#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string inputString; 
    string holdString = "";
    cin >> inputString;
    for (int i = 0; i<inputString.size(); i++) {
        if (inputString.at(i) != 'x') {
            cout << inputString.at(i);
        }
        else {
            holdString += "x";
        }
    }
    cout << holdString;

    
}