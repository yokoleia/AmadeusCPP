#include <iostream>
#include <deque>
#include <string>

using namespace std;



int main()
{
    string line;
    bool result;
    deque<char> charStore;

    getline(cin, line);
    
    for (auto ch : line)
    {
        if (isalpha(ch))
        {
            if (isupper(ch))
            {
                // XOR CH to conver to upper
                ch = ch ^ 0x20;
            }
            charStore.push_back(ch);
        }
    }

    while (charStore.size() > 1) {
        
        char back = charStore.back();
        charStore.pop_back();

        char front = charStore.front();
        charStore.pop_front();

        if (back != front) {
            result = false;
            break;
        }
    }
    if (charStore.size() == 1)
    {
        result = true;
    }
    /* Type your code here. */
    

    if (result) {
        cout << "Yes, \"" << line << "\" is a palindrome." << endl;
    } else {
        cout << "No, \"" << line << "\" is not a palindrome." << endl;
    }

    return 0;
}
