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
    static long ReferenceAccountNumber;
    virtual void PrintDetails() const = 0;
    //virtual void PrintBalance() const = 0;
    // Accessor functions
    double getBalance() const;

    long getBSB() const;
    long getAccountNumber() const;
    string getBankName() const;
    string getOpeningDate() const;

    // Mutator functions
    void setBalance(double newBalance);
    void setOpeningDate(string newOpeningDate);

    /*


    public:
        BankAccount(long BSB, long AccountNumber, string BankName, double Balance, string OpeningDate);


    */
};

#endif