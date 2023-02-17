#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int GetWordFrequency(vector<string> wordsList, string currWord)
{
    int count = 0;
    transform(currWord.begin(), currWord.end(), currWord.begin(), ::tolower);
    for (string word : wordsList)
    {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (word == currWord)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int countWords;
    cin >> countWords;

    vector<string> wordsList(countWords);

    for (int i = 0; i < countWords; i++)
    {
        cin >> wordsList[i];
    }

    for (string word : wordsList)
    {
        int freq = GetWordFrequency(wordsList, word);
        cout << word << " " << freq << endl;
    }

    return 0;
}
