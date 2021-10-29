//
// Created by TJ_Lty on 2021/10/29.
//

#ifndef DESIGNPATTERN_2021_CUSTOMERS_H
#define DESIGNPATTERN_2021_CUSTOMERS_H
#include"Customers.h"
#include"Customer.h"
#include<vector>
#include<list>
using namespace std;
class AbstractCustomerEvent {
public:
    virtual ~AbstractCustomerEvent()=default;
    virtual void addCustomer(Customer* customer)=0;
    virtual void deleteCustomer(Customer* customer)=0;
    virtual void broadcast()=0;
};

class WelcomeMessage:AbstractCustomerEvent{
private:
    list<Customer*> _customers;
public:
    void addCustomer(Customer* customer) override;
    void deleteCustomer(Customer* customer) override;
    void broadcast() override;
};

class CustomerSet{
private:
    vector<Customer*> _customers;
    int _index;
    static CustomerSet* _instance;
    CustomerSet(){}
public:
    static CustomerSet* getInstance(){
        if(_instance==nullptr)
            _instance=new CustomerSet;
        return _instance;
    }
    void addCustomer(Customer* customer);
    void deleteCustomer(Customer* customer);
    bool switchCustomer(int index);
    Customer* getCustomer();
    vector<Customer*> getCustomers();
};


#endif //DESIGNPATTERN_2021_CUSTOMERS_H
