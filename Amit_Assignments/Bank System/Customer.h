#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "customer.h"
#include "BankAccount.h"
#include <string>
#include <memory>

using namespace std;

class Customer
{

    private:
        string DateOfBirth;
        int CustomerID;
        string CustomerName;
        int Age;
        int Mobile;
        string PassportNumber;
        shared_ptr<BankAccount> Account = nullptr;

    public:
        static int ReferenceCustomerID;

        // Customer(string CustomerName = "Invalid", int Age = -1, int Mobile = -1, string PassportNumber = "Invalid");
        Customer(string CustomerName, string DOB, int Age, int Mobile, string PassportNumber);
        
        // Print
        void Print() const;

        // Accessors
        int getCustomerID() const;
        string getCustomerName() const;
        int getAge() const;
        int getMobile() const;
        string getPassportNumber() const;
        shared_ptr<BankAccount> getBankAccount() const;


        // Mutators
        void setBankAccount(shared_ptr<BankAccount> Account);
        void setCustomerID(int id);
        void setCustomerName(string name);
        void setAge(int age);
        void setMobile(int mobile);
        void setPassportNumber(string passportNumber);
        
};


#endif