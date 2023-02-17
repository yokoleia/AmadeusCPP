#include <iostream>

#include "VendingMachine.h"
using namespace std;

int main()
{
    /* TODO:
     * Purchases input number of drinks
     * Restocks input number of bottles
     * Reports inventory
     * */

    VendingMachine vendingMachine;

    int purchaseDrinkAmount;
    int restockDrinkAmount;
    cin >> purchaseDrinkAmount >> restockDrinkAmount;

    vendingMachine.Purchase(purchaseDrinkAmount);
    vendingMachine.Restock(restockDrinkAmount);

    vendingMachine.Report();
}