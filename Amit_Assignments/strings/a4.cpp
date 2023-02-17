#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string userText;
    getline(cin, userText);
    vector<string> words;
    while (userText.find(' ') != string::npos) {
        int spaceIndex = userText.find(' ');
        words.push_back(userText.substr(0, spaceIndex));
        
        userText = userText.substr(spaceIndex+1, userText.size()-spaceIndex-1);
    }
    words.push_back(userText);

    int maxLength = 0;
    int maxWordIndex = 0;
    for (int i=0; i<words.size(); i++) {
        if (words[i].size() > maxLength) {
            maxWordIndex = i;
            maxLength = words[i].size();
        }
    }
    
    cout << "Max Length: " << maxLength << endl;
    cout << "Max Word: " << words[maxWordIndex] << endl;
}