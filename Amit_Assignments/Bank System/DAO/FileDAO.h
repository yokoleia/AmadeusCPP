#ifndef FILEDAO_H
#define FILEDAO_H
#include "Idao.h"


class FileDAO : public Idao
{
public:
    virtual void saveAllCustomers(const vector<shared_ptr<Customer>> &CustomersOrdered) override;
    virtual void retrieveAllCustomers(map<int, shared_ptr<Customer>> &Customers, vector<shared_ptr<Customer>> &CustomersOrdered) override;
};

#endif