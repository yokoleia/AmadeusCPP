#ifndef BANK_H
#define BANK_H
#include <vector>
#include <map>
#include "Customer.h"
#include "BankAccount.h"
#include "Bank.h"
#include "UserInput.h"
#include <memory>
class Bank {

private:
    static long BSBCode;
    static string BankName;

    vector<Customer*>CustomersOrderedAlphabet;
    vector<Customer*>CustomersOrderedBalance;
    
    //map<long, Customer *> Customers;
    map<long, shared_ptr<Customer>> Customers;

public:
    UserInput ui;
    Bank();
    ~Bank() {
        Customers.clear();
    }
    void InsertCustomerBankAccount(Customer);

    void SetupTestData();

    //Accessors
    long getBranchBSB() { return BSBCode; }
    bool CustomerHasAccount(int &customerID);
    bool CustomerHasBankAccount(int &CustomerID);
    void CustomerBalanceEnquiry();

    // Mutators
    void CustomerRegistration();
    void OpenBankAccount();

    void SortAlphabetic();
    void SortOrderBalance();

};

#endif