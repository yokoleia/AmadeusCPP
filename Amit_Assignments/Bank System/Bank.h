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

    vector<shared_ptr<Customer>>CustomersOrderedAlphabet;
    vector<shared_ptr<Customer>>CustomersOrderedBalance;

    //map<long, Customer *> Customers;
    map<int, shared_ptr<Customer>> Customers;

public:
    UserInput ui;
    Bank();
    ~Bank() {
        Customers.clear();
    }
    void InsertCustomerBankAccount(shared_ptr<Customer> Customer_ptr);
    void DeleteCustomer(int CustomerID);
    int BinarySearch(vector<shared_ptr<Customer>>, int CustomerID);
    void SetupTestData();

    void RequestDisplaySorted();
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