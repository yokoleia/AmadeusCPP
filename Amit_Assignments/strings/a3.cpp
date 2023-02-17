#include <iostream>
#include <string>
using namespace std;

int main() {
    string userText;
    getline(cin,userText);
    char temp = userText.at(0);
    userText.at(0) = userText.at(userText.size()-1);
    userText.at(userText.size() - 1) = temp;

    cout << userText;
}