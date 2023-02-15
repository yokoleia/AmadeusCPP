#include <iostream>
using namespace std;

int main()
{
    const int ROCK = 0;
    const int PAPER = 1;
    const int SCISSORS = 2;

    int seed;
    cin >> seed;
    srand(seed);

    /* Type your code here. */

    string player1, player2;
    int numRounds;
    cin >> player1 >> player2;
    do
    {
        cin >> numRounds;
        if (numRounds < 1)
        {
            cout << "Rounds must be > 0" << endl;
        }
    } while (numRounds < 1);

    cout << player1 << " vs " << player2 << " for " << numRounds << " rounds" << endl;
    int p1;
    int p2;
    int p1wins = 0;
    int p2wins = 0;

    for (int i = 0; i < numRounds; i++)
    {
        do
        {
            p1 = rand() % 3;
            p2 = rand() % 3;

            if (p1 == p2)
            {
                cout << "Tie" << endl;
            }
        } while (p1 == p2);

        if (p1 == ROCK)
        {
            if (p2 == PAPER)
            {
                cout << player2 << " wins with paper" << endl;
                p2wins++;
            }
            else
            {
                cout << player1 << " wins with rock" << endl;
                p1wins++;
            }
        }
        else if (p1 == PAPER)
        {
            if (p2 == SCISSORS)
            {
                cout << player2 << " wins with scissors" << endl;
                p2wins++;
            }
            else
            {
                cout << player1 << " wins with paper" << endl;
                p1wins++;
            }
        }
        else
        {
            if (p2 == ROCK)
            {
                cout << player2 << " wins with rock" << endl;
                p2wins++;
            }
            else
            {
                cout << player1 << " wins with scissors" << endl;
                p1wins++;
            }
        }
    }
    cout << player1 << " wins " << p1wins << " and " << player2 << " wins " << p2wins << endl;
    return 0;
}
