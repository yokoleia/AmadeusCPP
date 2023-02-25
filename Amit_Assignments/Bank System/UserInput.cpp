#include "UserInput.h"
#include "SavingsAccount.h"
#include "FixedAccount.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <string>
#include <set>
#include "Time.h"
#include <memory>

void UserInput::InputCustomerRegistration(string &CustomerName, string& DOB, int &Age, int &Mobile, string &PassportNumber)
{
    string tempFirstName;
    string tempLastName;

    cout << "Thank you for creating an Account with us. " << endl;
    cout << "Enter the following Details: " << endl;
    cout << "First Name: ";
    tempFirstName = RequestAlphaString();
    cout << "Last Name: ";
    tempLastName = RequestAlphaString();
    cout << "Thank you: " << tempFirstName << " " << tempLastName << endl;
    CustomerName = tempFirstName + " " + tempLastName;


    cout << "Date of Birth (DD/MM/YYYY): ";
    DOB = RequestDate();

    Age = (2022 - stoi(DOB.substr(DOB.size() - 4, 4)));
    cout << "That makes you " << Age << " years old. " << endl;
    if (Age < 10)
    {
        throw runtime_error("Need to be 10 to open a Bank Account.");
    }
    cout << "Mobile (9 Digits, No Leading 0): ";
    //
    Mobile = RequestNum<int>(99999999);

    cout << "Passport Number (No Spaces):";
    PassportNumber = RequestAlphaNumericString();
}

int UserInput::InputRequestCustomerNumber() {
    
    cout << "What is your Customer Number: ";
    int CustomerID = RequestNum<int>(100);
    cout << "Customer number: " << CustomerID << endl;
    return CustomerID;
}


void UserInput::InputOpenBankAccount(shared_ptr<BankAccount>& BankAccount, long& BSB, string& BankName) {
    bool isSavings; // 
    double Balance;
    string OpeningDate;

    

    cout << "Enter Date (DD/MM/YYYY): "; // << endl;
    OpeningDate = RequestDate();

    cout << "Account Type(0=Fixed,1=Savings): ";
    isSavings = RequestNum<bool>();

    
    if (isSavings) {
        cout << "Input Opening Balance: "; // << endl;2
        Balance = RequestNum<double>();
        if (Balance < 0)
        {
            throw runtime_error("Can't open a bank account with a negative Balance.");
        }

        //BankAccount *InputOpenSavingsAccount(string & BankName, long &BSB, long &AccountNumber, double &Balance, string &OpeningDate);
        BankAccount = InputOpenSavingsAccount(BankName, BSB, Balance, OpeningDate);
        
    } else {
        cout << "Input Deposit Amount: "; // << endl;2
        Balance = RequestNum<double>();
        if (Balance < 0)
        {
            throw runtime_error("Can't open a bank account with a negative Balance.");
        }
        BankAccount = InputOpenFixedAccount(BankName, BSB, Balance, OpeningDate);
    }
    BankAccount->PrintDetails();
}

shared_ptr<BankAccount> UserInput::InputOpenSavingsAccount(string &BankName, long &BSB, double &Balance, string &OpeningDate)
{
    bool isSalaryAccount;
    cout << "Is this a Salary Account: 0=No, 1=Yes: ";
    isSalaryAccount = RequestNum<bool>();

    return make_shared<SavingsAccount>(BSB, BankName, Balance, OpeningDate, isSalaryAccount);
}

shared_ptr<BankAccount> UserInput::InputOpenFixedAccount(string &BankName, long &BSB, double &Balance, string &OpeningDate)
{
    cout << "Tenure Duration: ";
    int Tenure = RequestNum<int>(1, 7);

    // Opening Balance And Deposit Amount are the same
    return make_shared<FixedAccount>(BSB, BankName, Balance, OpeningDate, Balance, Tenure);
}

void UserInput::OutputRequestBalance(double balance, double interest) {
    cout << "Your Account Balance: " << balance << endl;
    cout << "Interest Earned: " << interest << endl;
}
/* ----------------------------------------------------------
                        Helper Functions
-------------------------------------------------------------*/

bool UserInput::StringIsDate(string date)
{
    int day, month, year;

    if (date.size() != 10)
    {
        return false;
    }
    else if ((date.at(2) != '/') || (date.at(5) != '/'))
    {
        return false;
    }
    else
    {
        date.replace(2, 1, " ");
        date.replace(5, 1, " ");

        istringstream iss(date);
        iss >> day >> month >> year;
        // cout << "day" << day << "month" << month << "year" << year << endl;
        if ((month <= 12) && (month > 0) && (year > 0))
        {
            if ((day > 0) && (day <= 32))
            {
                set<int> thirtymonths = {9, 4, 6, 11};
                if ((month == 2) && (day <= 28))
                {
                    return true;
                }
                else if (thirtymonths.count(month) && (day <= 30))
                {
                    return true;
                }
                else if (day <= 31)
                {
                    return true;
                }
            }
            // 30 days in september, april, june, november
        }

        return false;
    }
}

bool UserInput::StringIsAlphaNumeric(string line) {
    for (auto ch : line)
    {
        if (!isalpha(ch) && !isdigit(ch))
        {
            return false;
        }
    }
    return true;
}

bool UserInput::StringIsAlpha(string line)
{
    for (auto ch : line)
    {
        if (!isalpha(ch))
        {
            return false;
        }
    }
    return true;
}

bool UserInput::StringIsNum(string line)
{
    for (auto ch : line)
    {
        if (!isdigit(ch))
        {
            return false;
        }
    }
    return true;
}
string UserInput::RequestDate() {
    string temp;
    cin >> temp;
    while (!StringIsDate(temp)) {
        cout << "Invalid Date Format: Please try again!" << endl;
        cin >> temp;
    }
    return temp;
}


string UserInput::RequestAlphaString() {
    string temp; 
    cin >> temp;
    while (!StringIsAlpha(temp)) {
        cout << "Please only enter alpha characters" << endl;
        cin >> temp;
    }    
    return temp;
}
string UserInput::RequestAlphaNumericString() {
    string temp;
    cin >> temp;
    while (!StringIsAlphaNumeric(temp)) {
        cin >> temp;
    }
    return temp;
}

template <typename T>
T UserInput::RequestNum()
{
    T temp;
    cin >> temp;
    return temp;
}

template <typename T>
T UserInput::RequestNum(int lowerLimit)
{
    T temp;
    temp = RequestNum<T>();
    while (temp < lowerLimit)
    {
        cout << temp << " is invalid. Please input a number above " << lowerLimit << endl;
        temp = RequestNum<T>();
    }
    return temp;
}

template <typename T>
T UserInput::RequestNum(int lowerLimit, int upperLimit)
{
    T temp;
    temp = RequestNum<T>();
    while ((temp <= lowerLimit) && (temp >= upperLimit))
    {
        cout << temp << " is invalid. Please input a in the range ("<< lowerLimit << "-" << upperLimit << " )" << endl;
        temp = RequestNum<T>();
    }
    return temp;
}
