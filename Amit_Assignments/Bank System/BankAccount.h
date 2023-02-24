#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include "BankAccount.h"
#include <string>

using namespace std;

class BankAccount
{

protected:
    long BSB;
    long AccountNumber;
    string BankName;
    double Balance;
    string OpeningDate;
    
public:
    BankAccount(long BSB, long AccountNumber, string BankName, double Balance, string OpeningDate);

    // Accessor functions
    long getBSB() const;
    long getAccountNumber() const;
    string getBankName() const;
    double getBalance() const;
    string getOpeningDate() const;

    // Mutator functions
    void setBalance(double newBalance);
    void setOpeningDate(string newOpeningDate);
};

#endif