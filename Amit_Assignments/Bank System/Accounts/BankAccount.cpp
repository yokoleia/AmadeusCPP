#include "BankAccount.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
/*
BankAccount::BankAccount(long BSB, long AccountNumber, string BankName, double Balance, string OpeningDate)
{
    cout << "BankAccount Constructor" << endl;
    this->BSB = BSB;
    this->AccountNumber = AccountNumber;
    this->BankName = BankName;
    this->Balance = Balance;
    this->OpeningDate = OpeningDate;
}*/

long BankAccount::ReferenceAccountNumber = 100000;

// Accessors functions
long BankAccount::getBSB() const {
    return BSB;
}

long BankAccount::getAccountNumber() const {
    return AccountNumber;
}

std::string BankAccount::getBankName() const {
    return BankName;
}

double BankAccount::getBalance() const {
    
    return Balance + interestEarned;
}

string BankAccount::getOpeningDate() const {
    return OpeningDate;
}

// Mutator functions
void BankAccount::setBalance(double newBalance) {
    Balance = newBalance;
}

