#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string userText;
    getline(cin, userText);
    vector<string> words;
    while (userText.find(' ') != string::npos)
    {
        int spaceIndex = userText.find(' ');
        words.push_back(userText.substr(0, spaceIndex));
        userText = userText.substr(spaceIndex + 1, userText.size() - spaceIndex - 1);
    }
    words.push_back(userText);

    for (int i = 0; i < words.size(); i++)
    {
        char letter = words[i][i];
        letter = toupper(letter);
        cout << letter;
        
    }
}