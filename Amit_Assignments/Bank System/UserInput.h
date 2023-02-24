#ifndef USERINPUT_H
#define USERINPUT_H
#include "BankAccount.h"
#include <string>


using namespace std;
class UserInput {
    public:
        void InputCustomerRegistration(string &CustomerName, string &DOB, int &Age, int &Mobile, string &PassportNumber);
        void InputRequestCustomerNumber(int &CustomerID);
        void InputOpenBankAccount(BankAccount *BankAccount, long &BSB, string &BankName);
        BankAccount *InputOpenSavingsAccount(string& BankName, long& BSB, double &Balance, string &OpeningDate);
        BankAccount *InputOpenFixedAccount(string &BankName, long &BSB, double &Balance, string &OpeningDate);
        // Helper Functions
        // Requesters

        string
        RequestAlphaString();
        string RequestAlphaNumericString();
        string RequestDate();


        bool StringIsAlphaNumeric(string line);
        bool StringIsDate(string date);
        bool StringIsAlpha(string line);
        bool StringIsNum(string line);


        template <typename T>
        T RequestNum();
        template <typename T>
        T RequestNum(int lowerLimit);
        template <typename T>
        T RequestNum(int lowerLimit, int upperLimit);
};
#endif