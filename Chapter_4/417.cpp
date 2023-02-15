#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    /* Type your code here. */
    for (int i = 0; i < str.size(); i++)
    {
        if (isalpha(str.at(i)))
        {
            cout << str.at(i);
        }
    }
    cout << endl;
    return 0;
}