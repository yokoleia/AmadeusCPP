#include "Customer.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include "Display.h"
using namespace std;

int Customer::ReferenceCustomerID = 100;

//Customer::Customer(string CustomerName = "Invalid", int Age = Print-1, int Mobile = -1, string PassportNumber = "Invalid")
Customer::Customer(string CustomerName, string DateOfBirth, int Age, int Mobile, string PassportNumber)
{
    cout << "Customer Constructor" << endl;
    /*// increment RCID
    if ((CustomerName == "Invalid") || (PassportNumber == "Invalid") || (Age == -1) || (Mobile == -1)) {
        throw runtime_error("CustomerID not created. Insufficient information provided");
    }*/

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
        Account->PrintDetails(); // assume BankAccount has its own print() function
    } else {
        cout << "No Bank Account:" << endl;;
    }
}

// Accessors
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

BankAccount* Customer::getBankAccount() const {
    return Account;
}


// Mutators
void Customer::setBankAccount(BankAccount *Account)
{
    this->Account = Account;
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
