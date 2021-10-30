//
// Created by TJ_Lty on 2021/10/23.
//

#ifndef DESIGNPATTERN_2021_USERINTERFACE_H
#define DESIGNPATTERN_2021_USERINTERFACE_H

#include "Customer.h"
#include "../Basic/welcome.h"
class CustomerInterface {
private:
    Customer* customer;
public:
    CustomerInterface(){customer=new Customer();}
    virtual void setUserInformation();
    virtual void showUserInformation();
    virtual void changeUserInformation();
    virtual void rollback();
    Customer* getCustomer();
    void mainInterface();
};


#endif //DESIGNPATTERN_2021_USERINTERFACE_H
