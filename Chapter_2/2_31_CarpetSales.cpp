#include <iostream>
#include <iomanip>
using namespace std;

double calcOrder(double carpetPrice, int roomWidth, int roomLength)
{
    int roomArea = roomLength * roomWidth;
    double carpetCost = carpetPrice * roomArea * 1.2;
    double laborCost = roomArea * 0.75;
    double tax = (0.07 * carpetCost) + (0.07 * laborCost);
    double totalCost = carpetCost + laborCost + tax;

    cout << "Room: " << roomArea << " sq ft" << endl;
    cout << "Carpet: $" << carpetCost << endl;
    cout << "Labor: $" << laborCost << endl;
    cout << "Tax: $" << tax << endl;
    cout << "Cost: $" << totalCost << endl;
    cout << endl;
    return totalCost;
}

int main()
{
    cout << fixed << setprecision(2);
    double totalCost = 0;
    for (int i = 1; i <= 3; i++)
    {
        double carpetPrice;
        int roomWidth;
        int roomLength;

        cin >> carpetPrice >> roomWidth >> roomLength;
        cout << "Order #" << i << endl;
        totalCost += calcOrder(carpetPrice, roomWidth, roomLength);
    }

    cout << "Total Sales: $" << totalCost << endl;

    return 0;
}
