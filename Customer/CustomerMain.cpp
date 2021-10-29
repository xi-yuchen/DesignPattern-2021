//
// Created by TJ_Lty on 2021/10/29.
//

#include<iostream>
#include"Customer.h"
#include"Customers.h"
using namespace std;

int main(){

    CustomerSet* customers= CustomerSet::getInstance();
    auto welcome=new WelcomeMessage();
    AbstractCustomerBuilder* builder=new NormalCustomerBuilder;
    CustomerDirector::makeCustomer(builder);
    builder->getCustomer()->inputInformation();


    welcome->addCustomer(builder->getCustomer());
    customers->addCustomer(builder->getCustomer());

    builder=new VipCustomerBuilder;
    CustomerDirector::makeCustomer(builder);
    builder->getCustomer()->inputInformation();

    welcome->addCustomer(builder->getCustomer());
    customers->addCustomer(builder->getCustomer());


    cout<<"helloworld"<<endl;
}