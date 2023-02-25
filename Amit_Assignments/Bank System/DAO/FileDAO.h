#ifndef FILEDAO_H
#define FILEDAO_H
#include "Idao.h"

class FileDAO : public Idao
{
public:
    virtual void saveAllCustomers(const map<int, shared_ptr<Customer>> &Customers) override;
    virtual void retrieveAllCustomers(map<int, shared_ptr<Customer>> &Customers) override;
};

#endif