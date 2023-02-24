#include "BankAccount.h"
#include "SavingsAccount.h"
#include "Display.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

SavingsAccount::SavingsAccount(long BSB,string BankName, double Balance, string OpeningDate, bool SalaryAccount) 
{
    
    if (!SalaryAccount) {
        if (Balance<5000) {
            throw runtime_error("Insufficient balance for Account creation, Minimum balance is 5000.");
        } else {
            this->MinimumBalance = 5000;
        }
    } else {
        MinimumBalance = 0;
    }

    this->BSB = BSB;
    this->AccountNumber = ReferenceAccountNumber;
    this->BankName = BankName;
    this->Balance = Balance;
    this->OpeningDate = OpeningDate;
    this->SalaryAccount = SalaryAccount;

    ReferenceAccountNumber++;
    
    PrintDetails();
}

void SavingsAccount::PrintDetails() const {
    Display::clearConsole();
    cout << "Savings Account Details: " << endl;
    cout << "Bank: " << BankName << endl;
    cout << "BSB: " << BSB << endl;
    cout << "Account Number: " << AccountNumber << endl;
    cout << "Account Opened: " << OpeningDate << endl;
    cout << "Account Type: Savings" << endl;
    if (SalaryAccount) {
        cout << "\tSalary Account" << endl;
    }
    cout << "Minimum Balance: " << MinimumBalance << endl;



}
