#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const double VALUE_QUARTER = 0.25;
    const double VALUE_DIME = 0.1;
    const double VALUE_NICKEL = 0.05;
    const double VALUE_PENNIES = 0.01;

    int numQuarters, numDimes, numNickels, numPennies;
    cin >> numQuarters >> numDimes >> numNickels >> numPennies;

    double total = numQuarters * VALUE_QUARTER;
    total += numDimes * VALUE_DIME;
    total += numNickels * VALUE_NICKEL;
    total += numPennies * VALUE_PENNIES;
    cout << "Amount: $" << fixed << setprecision(2) << total << endl;

    return 0;
}