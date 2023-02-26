#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <memory>

#include "FileDAO.h"
#include "../Helpers/MyTime.h"
#include "../Accounts/SavingsAccount.h"
#include "../Accounts/FixedAccount.h"

using namespace std;

void createFile(string filename) {
    ofstream outFS;
    outFS.open(filename);
    outFS.close();
}
void FileDAO::saveAllCustomers(const vector<shared_ptr<Customer>> &CustomersOrdered)
{
    ofstream outFS;
    string fileName = "BankDataExport.csv";
    createFile(fileName);

    outFS.open(fileName);
    
    for (const auto customer: CustomersOrdered) {
        Display::clearConsole();
        cout << "Writing to File: " << fileName << endl;
        
        //for (const auto customer : CustomersOrdered) {
        outFS << *customer;
        // outFS << ComString(customer->);
        

        // exporting bankaccount details
        if (customer->getBankAccount()->getIsSavings()) {
            shared_ptr<SavingsAccount> BankAccount_ptr = dynamic_pointer_cast<SavingsAccount>(customer->getBankAccount());
            if (BankAccount_ptr)
            {
                outFS << ", " << *BankAccount_ptr;
            }
        } else {
            shared_ptr<FixedAccount> BankAccount_ptr = dynamic_pointer_cast<FixedAccount>(customer->getBankAccount());
            if (BankAccount_ptr)
            {
                outFS << ", " << *BankAccount_ptr;
            }
        }
        
                             
        outFS << endl;
    }
    cout << "Write Complete. " << endl;

    
    outFS.close();


}

void FileDAO::retrieveAllCustomers(map<int, shared_ptr<Customer>> &Customers, vector<shared_ptr<Customer>> &CustomersOrdered)
{
    ifstream infs;
    string fileName = "BankDataExport.csv";
    infs.open(fileName);

    if(infs.is_open()) {
        cout << "file open" << endl;
        string line;
        getline(infs, line);

        while (!infs.eof())
        {
            cout << line << endl;
            if (line.find(",") != string::npos)
            {
                string temp;
                string CustomerName;
                string DOB;
                int Age;
                int Mobile;
                string PassportNumber;
                istringstream iss(line);
                // create customer
                // add to vector
                // add to map
                // add bank account

                getline(iss, CustomerName, ',');
                getline(iss, DOB, ',');
                getline(iss, temp, ',');
                Age = stoi(temp);
                getline(iss, temp, ',');
                Mobile = stoi(temp);
                getline(iss, PassportNumber, ',');
                //shared_ptr<Customer> newCustomer;// = make_shared<Customer>(CustomerName, DOB, Age, Mobile, PassportNumber);
                shared_ptr<Customer> newCustomer = make_shared<Customer>(CustomerName, DOB, Age, Mobile, PassportNumber);
                CustomersOrdered.push_back(newCustomer);
                Customers.emplace(newCustomer->getCustomerID(), newCustomer);
                bool customerHasBankAccount;
                
                getline(iss, temp, ',');
                for (auto ch : temp)
                {
                    cout << "checking temp: " << ch;
                    if (!isdigit(ch))
                    {

                        continue;
                    }
                }
                cout << endl;
                bool isSavings = stoi(temp);

                getline(iss, temp, ',');
                
                long BSB = stol(temp);

                getline(iss, temp, ',');
                long AccountNumber = stol(temp);

                string BankName;
                getline(iss, BankName, ',');

                getline(iss, temp, ',');
                double Balance = stod(temp);

                string OpeningDate;
                getline(iss, OpeningDate, ',');

                if (isSavings) {
                    getline(iss, temp, ',');
                    bool SalaryAccount = stoi(temp);

                    getline(iss, temp, ',');
                    double MinimumBalance = stod(temp);

                    newCustomer->setBankAccount(make_shared<SavingsAccount>(BSB, BankName, Balance, OpeningDate, SalaryAccount));
                } else {

                    getline(iss, temp, ',');
                    double DepositAmount = stod(temp);

                    getline(iss, temp, ',');
                    int Tenure = stoi(temp);

                    //getline(iss, temp, ',');
                    //double InterestEarned = stod(temp);

                    newCustomer->setBankAccount(make_shared<FixedAccount>(BSB, BankName, Balance, OpeningDate, Balance, Tenure));
                }
            }
            getline(infs, line);
        }

    }   
    else
    {
        throw runtime_error("Data Import Failed. Backup File does not exist. ");
    }
    infs.close();
    Display::clearConsole();
    cout << "Operation Complete" << endl;
}