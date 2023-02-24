#include "BankAccount.h"
#include "FixedAccount.h"
#include "Display.h"
#include "Time.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

FixedAccount::FixedAccount(long BSB, string BankName, double Balance, string OpeningDate, double DepositAmount, int Tenure)
{
    if (DepositAmount <1000) {
        throw runtime_error("Deposit Amount is less than $1000. ");
    } else if((Tenure < 1) || Tenure > 7) {
        throw runtime_error("Tenure amount invalid. Must be in range: 1-7");
    }

    this->BSB = BSB;
    this->AccountNumber = ReferenceAccountNumber;
    this->BankName = BankName;
    this->Balance = Balance;
    this->OpeningDate = OpeningDate;
    this->DepositAmount = DepositAmount;
    this->Tenure = Tenure;
    CalcInterest();
    PrintDetails();
    ReferenceAccountNumber++;
}
void FixedAccount::CalcInterest() {
    int years = Time::get_current_year() - stoi(OpeningDate.substr(6, 4));
    interestEarned = DepositAmount * years * 0.08;
}

void FixedAccount::PrintDetails() const
{
    Display::clearConsole();
    cout << "Fixed Account Details: " << endl;
    cout << "Bank: " << BankName << endl;
    cout << "BSB: " << BSB << endl;
    cout << "Account Number: " << AccountNumber << endl;
    cout << "Account Opened: " << OpeningDate << endl;
    cout << "Account Type: Fixed" << endl;
    cout << "Deposit Amount" << DepositAmount << endl;
    cout << "Currentbalance" << getBalance() << endl;
    cout << "Tenure: " << Tenure<<  endl;
}

void FixedAccount::setDepositAmount(double amount)
{
    DepositAmount = amount;
}
double FixedAccount::getDepositAmount() const
{
    return DepositAmount;
}
void FixedAccount::setTenure(int tenure)
{
    Tenure = tenure;
}
int FixedAccount::getTenure() const
{
    return Tenure;
}
void FixedAccount::setInterestEarned(double interest)
{
    InterestEarned = interest;
}
double FixedAccount::getInterestEarned() const
{
    return InterestEarned;
}