#ifndef USERINPUT_H
#define USERINPUT_H
#include <string>


using namespace std;
class UserInput {
    public:
        void InputCustomerRegistration(string &CustomerName, string &DOB, int &Age, int &Mobile, string &PassportNumber);
        void InputOpenBankAccount(long &AccountNumber, double &Balance, string &OpeningDate);
        string RequestAlphaString();

        bool StringIsDate(string date);
        bool StringIsAlpha(string line);
        bool StringIsNum(string line);


        string RequestDate();

        template <typename T>
        T RequestNum();

        template <typename T>
        T RequestNum(int lowerLimit);
};
#endif