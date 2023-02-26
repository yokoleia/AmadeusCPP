#include "Customer.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int Customer::ReferenceCustomerID = 100;


Customer::Customer(string CustomerName, string DateOfBirth, int Age, int Mobile, string PassportNumber)
{
    cout << "Customer Constructor" << endl;


    this->CustomerID = ReferenceCustomerID;
    this->CustomerName = CustomerName;
    this->DateOfBirth = DateOfBirth;
    this->Age = Age;
    this->Mobile = Mobile;
    this->PassportNumber = PassportNumber;
    
    Display::clearConsole();
    ReferenceCustomerID++;
    Print();
}

ostream &operator<<(ostream &outFS, const Customer &customer)
{
    outFS << customer.getCustomerName();
    outFS << "," << customer.getDateOfBirth();
    outFS << "," << customer.getAge();
    outFS << "," << customer.getMobile();
    outFS << "," << customer.getPassportNumber();

    return outFS;
}



void Customer::PrintNameAndBalance() const {
    this->Account->CalcInterest();
    cout << "CustomerID: " << this->getCustomerID() << "\t\t";
    cout << "Account Opened: " << this->getBankAccount()->getOpeningDate() << "\t\t";
    cout << "Name: " << CustomerName << "\t\t";
    cout << "Interest Earned: $" << fixed << setprecision(2) << this->Account->getInterestEarned() << "\t\t";
    cout << "Balance: $" << fixed << setprecision(2) << this->getBalance() << endl;
}

void Customer::Print() const
{
    cout << endl << "Here are your new Account Details" << endl;

    cout << "Customer ID: " << CustomerID << endl;
    cout << "Name: " << CustomerName << endl;
    cout << "Date of Birth: " << DateOfBirth << endl;
    cout << "Age: " << Age << endl;
    cout << "Mobile Number: " << Mobile << endl;
    cout << "Passport Number: " << PassportNumber << endl;
    if (Account != nullptr)
    {
        cout << "Bank Account: " << endl;
        Account->PrintDetails(); 
    } else {
        cout << "No Bank Account:" << endl;;
    }
}

// Accessors

double Customer::getBalance() const {
    if (Account == nullptr) {
        return 0;
    } else {
        return Account->getBalance();
    }
}

int Customer::getCustomerID() const
{
    return CustomerID;
}

string Customer::getCustomerName() const
{
    return CustomerName;
}

int Customer::getAge() const
{
    return Age;
}

int Customer::getMobile() const
{
    return Mobile;
}

string Customer::getPassportNumber() const
{
    return PassportNumber;
}

shared_ptr<BankAccount> Customer::getBankAccount() const {
    return Account;
}


// Mutators
void Customer::setBankAccount(shared_ptr<BankAccount> Account)
{
    //cout << "\n\n==========Print from setBankAccount Function: sharedpointer\n";
    //Account->PrintDetails();
    
    this->Account = Account;
    //cout << "\n\n==========Print from setBankAccount Function: Object Account\n";
    //this->Account->PrintDetails();

}

void Customer::setCustomerID(int id)
{
    CustomerID = id;
}

void Customer::setCustomerName(string name)
{
    CustomerName = name;
}

void Customer::setAge(int age)
{
    Age = age;
}

void Customer::setMobile(int mobile)
{
    Mobile = mobile;
}

void Customer::setPassportNumber(string passportNumber)
{
    PassportNumber = passportNumber;
}
