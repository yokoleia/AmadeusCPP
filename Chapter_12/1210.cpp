#include <iostream>
using namespace std;

int maximum(int n1, int n2)
{
    return (n1 > n2) ? n1 : n2;
}

int main()
{
    cin.exceptions(ios::failbit); // Allow cin to throw exceptions
    int val1;
    int val2;
    int val3;
    int max;
    int counter = 0;

    val1 = 0;
    val2 = 0;
    val3 = 0;

    /* Type your code here. */
    try
    {
        cin >> val1;
        counter++;
        max = val1;
        cin >> val2;
        counter++;
        max = maximum(max, val2);
        cin >> val3;
        counter++;
        max = maximum(max, val3);

        cout << max << endl;
    }
    
    catch (ios_base::failure &e)
    {
        cout << counter << " input(s) read:" << endl;
        if (counter == 0)
        {
            cout << "No max" << endl;
        }
        else
        {
            cout << "Max is " << max << endl;
        }
        // cout << e.what() << endl;
    }
    catch (runtime_error &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
