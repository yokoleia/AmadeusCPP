#ifndef BANK_H
#define BANK_H
#include <vector>
#include <map>
#include "Customer.h"
#include "BankAccount.h"
#include "Bank.h"
#include "UserInput.h"
class Bank {

private:
    static long BSBCode;
    static string BankName;
    map<long, Customer *> Customers;
    



public:
    UserInput ui;
    Bank();
    //Accessors
    long getBranchBSB() { return BSBCode; }

    //Mutators
    void CustomerRegistration();
    void OpenBankAccount();

};



#endif