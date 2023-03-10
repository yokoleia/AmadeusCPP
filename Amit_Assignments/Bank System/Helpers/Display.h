#ifndef DISPLAY_H
#define DISPLAY_H
#include <string>
#include <iomanip>
#include <iostream>
#include <cstdlib> // for system() function

using namespace std;

class Display
{
public:

    static void clearConsole() 
    {
    #ifdef _WIN32
            system("cls");
    #else
            system("clear");
    #endif
    }

    

    static void MainMenu()
    {
            cout << "1.  Create New Customer Data " << endl
                 << "2.  Assign a Bank Account to a Customer " << endl
                 << "3.  Display balance or interest earned of a Customer " << endl
                 << "4.  Sort Customer Data" << endl
                 << "5.  Import/Export Customer Data" << endl
                 << "6.  Show All Customers Loaded. (Make sure to import all data!)" << endl
                 << "7.  Search Customers by Name" << endl
                 << "8.  Exit" << endl;
    }
};

#endif