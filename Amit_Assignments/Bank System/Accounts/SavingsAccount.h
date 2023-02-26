#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "BankAccount.h"
using namespace std;

class SavingsAccount : public BankAccount
{
protected:
    bool SalaryAccount;
    double MinimumBalance;

public:
    SavingsAccount(long BSB, string BankName, double Balance, string OpeningDate, bool SalaryAccount);
    ~SavingsAccount() {};

    friend ostream &operator<<(ostream &os, const SavingsAccount &SavingsAccount);

    void PrintDetails() const override;
    void CalcInterest() override;
    
    bool getIsSalaryAccount() { return this->SalaryAccount; }
    double getMinimumBalance() { return this->MinimumBalance; }

};

#endif