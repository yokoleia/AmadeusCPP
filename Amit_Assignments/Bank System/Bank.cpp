#include <iostream>
#include <iomanip>
#include <cmath>

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

    Customers.emplace(myCustomer->getCustomerID(), myCustomer);

    /* test code
    cout << "test map" << endl;
    long testCID = myCustomer->getCustomerID();
    cout << Customers.count(testCID);*/
}
void Bank::OpenBankAccount() {
    /*Account Number : long
    BSB Code : long
    Bank Name : String
    Balance : double
    Opening Date : String DD/MM/YYYY 
    */
    long AccountNumber;
    double Balance;
    string OpeningDate;

    ui.InputOpenBankAccount(AccountNumber, Balance, OpeningDate);
    
    if (Customers.count(AccountNumber) < 1) {
        throw runtime_error("No Account Matching Account Number! Please create a user account first. ");
    } else if (Customers.count(AccountNumber) > 1) {
        throw runtime_error("You already have a Bank Account. You cannot have more than one!");
    }

    BankAccount *userBankAccount = new BankAccount(this->BSBCode, AccountNumber, this->BankName, Balance, OpeningDate);

    Customers.at(AccountNumber)->setBankAccount(userBankAccount);

    /*if (Customers.count(AccountNumber) > 0) {
        BankAccounts.emplace(AccountNumber, userBankAccount);
    }
    if (BankAccounts.count(AccountNumber) == 1)
    {
        cout << "Account Matching AccountNumber: " << AccountNumber << endl;
    }*/
}