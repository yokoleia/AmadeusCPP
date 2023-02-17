#include <iostream>
#include <cstdlib>
using namespace std;

string CoinFlip()
{
    int x = rand() % 2;
    string userString;
    userString = (x == 0) ? "Tails" : "Heads";
    return userString;
}

int main()
{
    int countCoinFlips;
    cin >> countCoinFlips;

    srand(2); 

    
    for (int i = 0; i < countCoinFlips; i++)
    {
        cout << CoinFlip() << endl;
    }
    return 0;
}
