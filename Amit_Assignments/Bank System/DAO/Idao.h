#ifndef IDAO_H
#define IDAO_H
#include "../Customer.h"
#include <vector>
#include <map>

class Idao
{
public:
    virtual void saveAllCustomers(const vector<shared_ptr<Customer>> &CustomersOrdered) = 0;
    virtual void retrieveAllCustomers(map<int, shared_ptr<Customer>> &Customers, vector<shared_ptr<Customer>> &CustomersOrdered) = 0;
};

#endif