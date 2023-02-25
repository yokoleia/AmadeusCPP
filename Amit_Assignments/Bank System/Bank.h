#ifndef BANK_H
#define BANK_H
#include <vector>
#include <map>
#include <memory>
#include "Accounts/BankAccount.h"
#include "Bank.h"
#include "Customer.h"
#include "DAO/FileDAO.h"
#include "Helpers/UserInput.h"
class Bank {

private:
    static long BSBCode;
    static string BankName;

    vector<shared_ptr<Customer>>CustomersOrdered;
    map<int, shared_ptr<Customer>> Customers;

    //Interfacing Functions
    UserInput ui;

public:
    
    Bank();
    ~Bank() {
        Customers.clear();
    }
    void SetupTestData();

    int BinarySearch(vector<shared_ptr<Customer>>, int CustomerID);
    int BinarySearch(vector<shared_ptr<Customer>> vec, string CustomerName);
    void SearchCustomerName();

    void InsertCustomerBankAccount(shared_ptr<Customer> Customer_ptr);
    void DeleteCustomer(int CustomerID);

    long getBranchBSB() { return BSBCode; }

    bool CustomerHasAccount(int &customerID);
    bool CustomerHasBankAccount(int &CustomerID);
    void CustomerBalanceEnquiry();

    // Customer registration functions
    void CustomerRegistration();
    void CustomerRegistration(string CustomerName,string LastName,string DOB,int Age,int Mobile,string PassportNumber);

    // open bank account functions
    void OpenBankAccount();
    void OpenSavingsAccount(int CustomerID, string BankName, long BSB, double Balance, string OpeningDate, bool isSalaryAccount);
    void OpenFixedAccount(int CustomerID, string BankName, long BSB, double Balance, string OpeningDate, int Tenure);

    // sorters
    void RequestSort();
    void SortAlphabetic();
    void SortOrderBalance();

    void DisplayCustomers();

    // Persistence
    void DataPersistence();
};

#endif