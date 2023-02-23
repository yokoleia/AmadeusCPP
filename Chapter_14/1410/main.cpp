#include "ListItem.h"
#include <string>
#include <list>
#include <iostream>

using namespace std;

int main()
{
    // TODO: Declare a list called shoppingList of type ListItem
    list<ListItem> shoppingList;

    string item;
    getline(cin, item);

    while (item != "-1") {
        shoppingList.push_back(ListItem(item));

    // TODO: Read inputs (items) and add them to the shoppingList list
    //       Read inputs until a -1 is input
    

    
    getline(cin,item);
    }
    for (ListItem grocery: shoppingList) {
        grocery.PrintNodeData();
    }

    return 0;
}