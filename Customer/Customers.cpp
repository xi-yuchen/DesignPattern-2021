//
// Created by TJ_Lty on 2021/10/29.
//

#include "Customers.h"
#include<vector>
#include <algorithm>

using namespace std;

void WelcomeMessage::addCustomer(Customer *customer) {
    broadcast();
    _customers.push_back(customer);
}

void WelcomeMessage::deleteCustomer(Customer *customer) {
    _customers.remove(customer);
}

void WelcomeMessage::broadcast() {
    for (auto customer:_customers) {
        if (customer != nullptr)
            customer->sendMessage("有新账号上线，请注意设备安全\n");
        else
            _customers.remove(customer);
    }
}

void CustomerSet::addCustomer(Customer *customer) {
    _customers.push_back(customer);
    _index = (int) _customers.size() - 1;
}

void CustomerSet::deleteCustomer() {
    remove(_customers.begin(), _customers.end(), this->_customers[_index]);
    if(_customers.empty())
        init();
    _index=0;
}

bool CustomerSet::switchCustomer(int index) {
    if (index >= 0 && index < _customers.size()) {
        _index = index;
    } else
        return false;
    return true;
}

Customer *CustomerSet::getCustomer() {
    cout<<_index;
    return _customers[_index];
}

vector<Customer *> CustomerSet::getCustomers() {
    return _customers;
}


CustomerSet *CustomerSet::_instance = nullptr;

void CustomerSet::init() {
    cout<<1;
    if(_customers.empty()) {
          AbstractCustomerBuilder *builder = new NullCustomerBuilder;
          CustomerDirector::makeCustomer(builder);
          addCustomer(builder->getCustomer());
    }
}


