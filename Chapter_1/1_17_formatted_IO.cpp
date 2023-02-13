#include <iostream>
using namespace std;

int main() {
    int currentPrice;
    int lastMonthPrice;
    cin >> currentPrice >> lastMonthPrice;

    int priceDifference = currentPrice - lastMonthPrice;
    float estimatedMortgage = currentPrice * 0.051 / 12;

    cout <<  "This house is $" << currentPrice << ". The change is $" << priceDifference << " since last month." << endl;
    cout << "The estimated monthly mortgage is $" << estimatedMortgage << "." << endl;
    return 0;
}