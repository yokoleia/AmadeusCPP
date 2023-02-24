#ifndef DISPLAY_H
#define DISPLAY_h
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

class Display
{
public:
    void MainMenu(){
        cout << "1.  Create New Customer Data " << endl
             << "2.  Assign a Bank Account to a Customer " << endl
             << "3.  Display balance or interest earned of a Customer " << endl
             << "4.  Sort Customer Data" << endl
             << "5.  Persist Customer Data" << endl
             << "6.  Show All Customers" << endl
             << "7.  Search Customers by Name" << endl
             << "8.  Exit" << endl;
    }






};

#endif