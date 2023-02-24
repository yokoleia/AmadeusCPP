#ifndef FIXEDACCOUNT_H
#define FIXEDACCOUNT_H
#include "BankAccount.h"
using namespace std;

class FixedAccount : public BankAccount {
    protected:
        /*
        FixedDeposit sub-class: -
    It should have following 3 additional attributes
    1. Deposit Amount. (The minimum is 1000)
    2. Tenure (in years) (The minimum is 1year max is 7 years)
    3. InterestEarned (double) */
        double DepositAmount;
        int Tenure;
        double InterestEarned;

    public:
        FixedAccount(long BSB, string BankName, double Balance, string OpeningDate, double DepositAmount, int Tenure);
        ~FixedAccount(){};
        void PrintDetails() const override;
        
        //Access and Mutate Functions
        void setDepositAmount(double amount);
        double getDepositAmount() const;
        void setTenure(int tenure);
        int getTenure() const;
        void setInterestEarned(double interest);
        double getInterestEarned() const;
    

};

#endif