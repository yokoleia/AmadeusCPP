#include <iostream>
using namespace std;

int main()
{
    string inputString; 
    cin >> inputString;

    for (int i = inputString.size()-1; i >= 0; i--) {
        cout << inputString.at(i);
        if (i > 0) {
            cout << "-";
        }
    }
    
}