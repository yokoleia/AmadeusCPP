#include <iostream>
#include <iomanip>
#include <cmath>
#include "Accounts/SavingsAccount.h"
#include "Accounts/FixedAccount.h"
#include "Bank.h"
#include "Customer.h"
#include <string>
#include <memory>
#include <algorithm>
#include "DAO/FileDAO.h"

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



void Bank::DeleteCustomer(int CustomerID) {
    int i = BinarySearch(CustomersOrdered, CustomerID); 
    if (i != -1) {
        CustomersOrdered.erase(CustomersOrdered.begin() + i);
    }
}

int Bank::BinarySearch(vector<shared_ptr<Customer>> vec, int CustomerID)
{
    int left = 0, right = vec.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (vec[mid]->getCustomerID() == CustomerID)
        {
            return mid;
        }
        else if (vec[mid]->getCustomerID() < CustomerID)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int Bank::BinarySearch(vector<shared_ptr<Customer>> vec, string CustomerName)
{
    int left = 0, right = vec.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (vec[mid]->getCustomerName() == CustomerName)
        {
            return mid;
        }
        else if (vec[mid]->getCustomerName() < CustomerName)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

void Bank::InsertCustomerBankAccount(shared_ptr<Customer> Customer_ptr) {
    Customers.emplace(Customer_ptr->getCustomerID(), Customer_ptr);
    CustomersOrdered.push_back(Customer_ptr);
}

void Bank::SortAlphabetic()
{
    sort(CustomersOrdered.begin(), CustomersOrdered.end(), [](const shared_ptr<Customer> &c1, const shared_ptr<Customer> &c2)
         { return c1->getCustomerName() < c2->getCustomerName(); });
}

void Bank::SortOrderBalance()
{
    sort(CustomersOrdered.begin(), CustomersOrdered.end(), [](const shared_ptr<Customer> &c1, const shared_ptr<Customer> &c2)
         { return c1->getBalance() < c2->getBalance(); });
}

void Bank::SetupTestData() {
    /*
    Customer *c1 = new Customer("Customer One", "22/12/1997", 20, 123412345, "XAXA");
    Customers.emplace(c1->getCustomerID(), c1);

    Customer *c2 = new Customer("Customer Two", "22/12/1997", 20, 123412345, "XAXA");
    Customers.emplace(c2->getCustomerID(), c2);

    //Customers.at(c1->getCustomerID())->setBankAccount(new SavingsAccount(123123, "Pass Test", 5000, "12/12/1200", false));
    Customers.at(c2->getCustomerID())->setBankAccount(new SavingsAccount(123123, "Fail Test", 0, "12/12/1200", false));
    */
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
    CustomerRegistration(CustomerName, LastName, DOB, Age, Mobile, PassportNumber);
    


}

void Bank::CustomerRegistration(string CustomerName, string LastName, string DOB, int Age, int Mobile, string PassportNumber) {
    shared_ptr<Customer> newCustomer = make_shared<Customer>(CustomerName, DOB, Age, Mobile, PassportNumber);
    InsertCustomerBankAccount(newCustomer);

}

void Bank::OpenBankAccount() {
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

    shared_ptr<BankAccount> userBankAccount;
    ui.InputOpenBankAccount(userBankAccount, this->BSBCode, this->BankName);

    Customers.at(CustomerID)->setBankAccount(userBankAccount);

}
void Bank::OpenSavingsAccount(int CustomerID, string BankName, long BSB, double Balance, string OpeningDate, bool isSalaryAccount) {
    shared_ptr<BankAccount> userBankAccount = make_shared<SavingsAccount>(BSB, BankName, Balance, OpeningDate, isSalaryAccount);
    Customers.at(CustomerID)->setBankAccount(userBankAccount);
}
void Bank::OpenFixedAccount(int CustomerID, string BankName, long BSB, double Balance, string OpeningDate, int Tenure)
{
    shared_ptr<BankAccount> userBankAccount = make_shared<FixedAccount>(BSB, BankName, Balance, OpeningDate, Balance, Tenure);
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

void Bank::RequestSort() {
    bool SortByAlphaBet = ui.RequestSortTypeAlphabet();
    if (SortByAlphaBet) {
        SortAlphabetic();
    } else {
        SortOrderBalance();
    }
}

void Bank::DisplayCustomers() {
    ui.OutputSorted(CustomersOrdered);
}

void Bank::SearchCustomerName() {
    string Name = ui.RequestName();
    int i = BinarySearch(CustomersOrdered, Name);
    if (i == -1) {
        cout << "No Customer Found" << endl;
    } else {
        CustomersOrdered.at(i)->PrintNameAndBalance();
    }
}