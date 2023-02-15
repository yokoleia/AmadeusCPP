#include <iostream>
#include <string>
using namespace std;

int main()
{

    /* Type your code here. */
    string inputstr;
    string str = "";

    while (true)
    {
        getline(cin, str);

        if ((str == "done") || (str == "Done") || (str == "d"))
        {
            break;
        }
        else
        {
            for (int i = str.size() - 1; i >= 0; i--)
            {
                cout << str.at(i);
            }
        }
        cout << endl;
    }

    return 0;
}
