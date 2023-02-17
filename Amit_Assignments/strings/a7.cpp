#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string userText;
    getline(cin, userText);
    
    for (int i=0; i<userText.size(); i++) {
        char temp = (isalpha(userText.at(i))) ? userText.at(i)+1 : ' ';
        cout << temp;
    }
}