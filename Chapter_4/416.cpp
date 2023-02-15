#include <iostream>
#include <string>
using namespace std;

int main()
{

    /* Type your code here. */
    char ch;
    string str;
    int counter = 0;

    cin >> ch;
    getline(cin, str);

    for (int i = 0; i < str.size(); i++)
    {
        counter = (str.at(i) == ch) ? counter + 1 : counter;
    }

    // output string
    cout << counter << " " << ch;

    if (counter != 1)
    {
        cout << "'s";
    }

    cout << endl;
    return 0;
}