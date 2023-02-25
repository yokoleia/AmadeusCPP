#ifndef IDAO_H
#define IDAO_H
#include "../Customer.h"
#include <map>

class Idao
{
public:
    virtual void saveAllCustomers(const map<int, shared_ptr<Customer>> &Customers) = 0;
    virtual void retrieveAllCustomers(map<int, shared_ptr<Customer>> &Customers) = 0;
};

#endif