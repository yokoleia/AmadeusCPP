#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int VALUE_DOLLAR = 100;
    const int VALUE_QUARTER = 25;
    const int VALUE_DIME = 10;
    const int VALUE_NICKEL = 5;
    const int VALUE_PENNIES = 1;

    int change;
    int dollars = 0;
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;

    cin >> change;
    if (change < 1) {
        cout << "No change" << endl;
    } else {
        if (change > 0) {
            dollars = change / VALUE_DOLLAR;
            change -= dollars*VALUE_DOLLAR;
            string cointitle = (dollars > 1) ? " Dollars" : " Dollar";
            if (dollars > 0) {
                cout << dollars << cointitle << endl;
            }
        }
        if (change > 0) {
            quarters = change / VALUE_QUARTER;
            change -= quarters*VALUE_QUARTER;
            string cointitle = (quarters > 1) ? " Quarters" : " Quarter";
            if (quarters > 0) {
                cout << quarters << cointitle << endl;
            }
        }
        if (change > 0)
        {
            dimes = change / VALUE_DIME;
            change -= dimes * VALUE_DIME;

            string cointitle = (dimes > 1) ? " Dimes" : " Dime";
            if (dimes > 0)
            {
                cout << dimes << cointitle << endl;
            }
        }
        if (change > 0)
        {
            nickels = change / VALUE_NICKEL;
            change -= nickels * VALUE_NICKEL;

            string cointitle = (nickels > 1) ? " Nickels" : " Nickel";
            if (nickels > 0)
            {
                cout << nickels << cointitle << endl;
            }
        }
        if (change > 0)
        {
            pennies = change / VALUE_PENNIES;
            change -= pennies * VALUE_PENNIES;

            string cointitle = (pennies > 1) ? " Pennies" : " Penny";
            if (pennies > 0)
            {
                cout << pennies << cointitle << endl;
            }
        }
    }

    
    return 0;
}