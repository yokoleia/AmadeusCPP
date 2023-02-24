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
    //SetupTestData();
    
}
void Bank::SetupTestData() {
    
    Customer *c1 = new Customer("Customer One", "22/12/1997", 20, 123412345, "XAXA");
    Customers.emplace(c1->getCustomerID(), c1);

    Customer *c2 = new Customer("Customer Two", "22/12/1997", 20, 123412345, "XAXA");
    Customers.emplace(c2->getCustomerID(), c2);

    //Customers.at(c1->getCustomerID())->setBankAccount(new SavingsAccount(123123, "Pass Test", 5000, "12/12/1200", false));
    Customers.at(c2->getCustomerID())->setBankAccount(new SavingsAccount(123123, "Fail Test", 0, "12/12/1200", false));
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
    int CustomerID = ui.InputRequestCustomerNumber();

    if (!CustomerHasAccount(CustomerID))
    {
        cout << "CustomerID: " << CustomerID << endl;

        throw runtime_error("No Account Matching Account Number! Please create a user account first. ");
    }
    if (CustomerHasBankAccount(CustomerID))
    {
        cout << "CustomerID: " << CustomerID << endl;
        throw runtime_error("You already have a Bank Account. You cannot have more than one!");
    }

    BankAccount *userBankAccount;
    ui.InputOpenBankAccount(userBankAccount, this->BSBCode, this->BankName);

    Customers.at(CustomerID)->setBankAccount(userBankAccount);

}


bool Bank::CustomerHasAccount(int& CustomerID) {
    
    return (Customers.count(CustomerID) == 1);
    
}

bool Bank::CustomerHasBankAccount(int& CustomerID) {
    if (CustomerHasAccount(CustomerID)) {
        return (Customers.at(CustomerID)->getBankAccount() != nullptr);
    }
    return false;
}



void Bank::CustomerBalanceEnquiry()
{
    int CustomerID = ui.InputRequestCustomerNumber();
    if (CustomerHasBankAccount(CustomerID)) {
        double balance = Customers.at(CustomerID)->getBankAccount()->getBalance();
        double interest = Customers.at(CustomerID)->getBankAccount()->getInterestEarned();

        ui.OutputRequestBalance(balance, interest);
    }
    else if (CustomerHasAccount(CustomerID)) {
        throw runtime_error("Customer Record created but No Bank Account Created Yet!\nPlease create a user account first. ");
    } else {
        throw runtime_error("No Account Matching Customer ID! Please create a Customer Record first. ");
    }
    //ui.OutputRequestBalance(double balance, double interest);
}