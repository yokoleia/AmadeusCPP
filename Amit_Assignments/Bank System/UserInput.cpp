#include "UserInput.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <string>
#include <set>

void UserInput::InputCustomerRegistration(string &CustomerName, string& DOB, int &Age, int &Mobile, string &PassportNumber)
{
    string tempFirstName;
    string tempLastName;
    int tempAge;
    int tempMobile;
    string tempPassportNumber;
    string tempDOB;

    cout << "Thank you for creating an Account with us. " << endl;
    cout << "Enter the following Details: " << endl;
    cout << "First Name: ";
    cin >> tempFirstName;
    cout << "Last Name: ";
    cin >> tempLastName;
    if (!StringIsAlpha(tempFirstName) || !StringIsAlpha(tempLastName))
    {
        throw runtime_error("There seems to be a spelling error. Try Again");
    }
    cout << "Thank you: " << tempFirstName << " " << tempLastName << endl;


    cout << "Date of Birth (DD/MM/YYYY): ";
    tempDOB = RequestDate();
    tempAge = 2022 - stoi(tempDOB.substr(tempDOB.size() - 4, 4));
    cout << "age" << tempAge << endl;
    if (tempAge < 10)
    {
        throw runtime_error("Need to be 10 to open a Bank Account.");
    }
    cout << "Mobile (9 Digits, No Leading 0): ";
    //
    Mobile = RequestNum<int>(99999999);

    cout << "Passport Number: ";
    cin >> PassportNumber;

    CustomerName = tempFirstName + " " + tempLastName;
    Age = tempAge;
    Mobile = tempMobile;
    PassportNumber = tempPassportNumber;
    DOB = tempDOB;
}

void UserInput::InputOpenBankAccount(long &AccountNumber, double &Balance, string &OpeningDate)
{
    long tempAccountNumber;
    double tempBalance;
    string tempOpeningDate;
    // FIXME: Use this later to check account by name instead of cid
    // cout << "Input User Full Name etc. -> Firstname Lastname: ";
    cout << "What is your Account Number" << endl;
    tempAccountNumber = RequestNum<long>(100);
    cout << "Input Opening Balance:"; // << endl;2
    cin >> tempBalance;
    if (tempBalance < 0)
    {
        throw runtime_error("Can't open a bank account with a negative Balance.");
    }

    cout << "Enter Date (DD/MM/YYYY): "; // << endl;
    tempOpeningDate = RequestDate();
    

    AccountNumber = tempAccountNumber;
    Balance = tempBalance;
    OpeningDate = tempOpeningDate;
}


/* ----------------------------------------------------------
                        Helper Functions
-------------------------------------------------------------*/

bool UserInput::StringIsDate(string date)
{
    int day, month, year;

    if (date.size() != 10) {
        return false;
    } else if ((date.at(2) != '/') || (date.at(5) != '/'))  {
        return false;
    } else {
        date.replace(2, 1, " ");
        date.replace(5, 1, " ");
        
        istringstream iss(date);
        iss >> day >> month >> year;
        //cout << "day" << day << "month" << month << "year" << year << endl;
        if ((month <= 12) && (month > 0) && (year > 0)) {
            if ((day > 0) && (day <= 32)) {
                set<int> thirtymonths = {9,4, 6, 11};
                if ((month == 2) && (day <= 28)) {
                    return true;
                } else if (thirtymonths.count(month) && (day <= 30))
                {
                    return true;
                } else if (day <= 31) {
                    return true;
                }
                
            }
            // 30 days in september, april, june, november

            
        }
        
        return false;
    }
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