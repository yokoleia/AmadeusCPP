#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

    /* Type your code here. */

    double counter = 0;
    int input = 0;
    int max = 0;
    int sum = 0;
    while (true)
    {
        cin >> input;
        if (input < 0)
        {
            break;
        }
        counter = counter + 1;
        sum += input;
        max = (input > max) ? input : max;
    }
    double average = sum / counter;
    cout << max << " " << fixed << setprecision(2) << average << endl;

    return 0;
}
