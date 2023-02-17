#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> words;
    int vlen;
    char ch;
    cin >> vlen;
    for (int i = 0; i < vlen; i++)
    {
        string temp;
        cin >> temp;
        words.push_back(temp);
    }

    cin >> ch;

    for (int i = 0; i < vlen; i++)
    {
        // if contains ch
        if (words[i].find(ch)!=string::npos)
        {
            // cout whole word
            cout << words[i] << ",";
        }
    }
    cout << endl;

    return 0;
}
