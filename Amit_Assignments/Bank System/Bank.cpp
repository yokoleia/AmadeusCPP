#include <iostream>
#include <iomanip>
#include <cmath>
#include "SavingsAccount.h"
#include "FixedAccount.h"
#include "Bank.h"
#include "Customer.h"
#include <string>
#include "UserInput.h"

using namespace std;

// The task doesn't indicate multiple BSBs so I'm not going to implement branches
// However, if multiple branches are implemented, each bank class can be refactored into a branch class. 

long Bank::BSBCode = 123456;
string Bank::BankName = "Rab's Bank";

Bank::Bank() {
    // increment RAN
    cout << "Bank Constructor" << endl;
    
}


void Bank::CustomerRegistration()
{
    string CustomerName;
    string LastName; 
    string DOB;
    int Age;
    int Mobile;
    string PassportNumber;
    

    // TAKE INPUT
    ui.InputCustomerRegistration(CustomerName, DOB, Age, Mobile, PassportNumber);
    Customer *myCustomer = new Customer(CustomerName, DOB, Age, Mobile, PassportNumber);
    

    //cout << "Customers Size Before: " << Customers.size();
    Customers.emplace(myCustomer->getCustomerID(), myCustomer);
    // << "Customers Size After: " << Customers.size();

    //test code
    cout << "test map" << endl;
    int testCID = myCustomer->getCustomerID();
    cout << Customers.count(testCID) << " Accounts belonging to CID: " << testCID << endl;
}
void Bank::OpenBankAccount() {
    /*Account Number : long
    BSB Code : long
    Bank Name : String
    Balance : double
    Opening Date : String DD/MM/YYYY 
    */
    
    int CustomerID;
    ui.InputRequestCustomerNumber(CustomerID);
        
    if (Customers.count(CustomerID) != 1)
    {
        cout << "CustomerID: " << CustomerID << endl;
        
        throw runtime_error("No Account Matching Account Number! Please create a user account first. ");
    } else if (Customers.at(CustomerID)->getBankAccount() != nullptr)
    {
        throw runtime_error("You already have a Bank Account. You cannot have more than one!");
    }
    BankAccount *userBankAccount;
    ui.InputOpenBankAccount(userBankAccount, this->BSBCode, this->BankName);

    Customers.at(CustomerID)->setBankAccount(userBankAccount);

}