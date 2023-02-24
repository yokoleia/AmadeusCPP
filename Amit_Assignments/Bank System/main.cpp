#include <iostream>
#include <vector>
#include "Customer.h"
#include "Bank.h"
#include "Display.h"

using namespace std;

// function to setup bank data
void SetupBank(Bank& myBank)
{
    cout << "My bank BSB:" << myBank.getBranchBSB() << endl;
    myBank.CustomerRegistration();

}

int main() {
    Display display;
    cin.exceptions(ios::failbit); // Allow cin to throw exceptions
    
    // Main Variables
    Bank myBank;

    int option;

   

    while (true) {
        
        try {

            display.MainMenu();
            cin >> option;
            switch(option) {
                
                // Create new customer Data
                case 1:
                    
                    SetupBank(myBank);
                    break;

                // Assign a bank account to a customer            
                case 2:
                    myBank.OpenBankAccount();
                    break;

                // Display balance or interest earned of a customer
                case 3:
                    break;
                
                // sort customer data
                case 4:
                    break;
                
                // Persist customer data
                case 5:
                    break;
                
                // Show all customers
                case 6:
                    break;
                
                // Search Customers by Name
                case 7:
                    break;
                
                // exit
                case 8: 
                    cout << "Thank you for using this bank system." << endl;
                    cout << "Exiting..." << endl;
                    return 0;
                default:
                    throw runtime_error("Invalid option");
                    break;
            }
        } catch (ios_base::failure &e) {
            cin.clear();
            cin.ignore(80, '\n');
            cout<< "Error: Invalid Option" << endl;
            
        } catch(runtime_error& e) {

            cin.ignore(80, '\n');
            cout << "Error: " << e.what() << endl;
            cin.clear();
        }

        string temphold;
        cout << "Press Enter key to continue..." << endl;
        getline(cin, temphold);
    }



}