//
// Created by TJ_Lty on 2021/10/29.
//

#include<iostream>
#include<iomanip>
#include"Customer.h"
#include"Customers.h"

using namespace std;

class CustomerInterface {
private:
    CustomerSet *_customers;
public:
    void setCustomerSet(CustomerSet *customers) {
        this->_customers = customers;
    }
    void ShowInformation();

    void ShowCustomerList();

    void ShowOperation();

    void DeleteCustomer();

    void AddCustomer();

    void ChangeInfo();

    void InitCustomers();

    void CustomerMain();
};

//    CustomerSet* customers = CustomerSet::getInstance();
//    auto* customer=customers->getCustomer();
//
//    AbstractCustomerBuilder* builder=new NormalCustomerBuilder;
//    CustomerDirector::makeCustomer(builder);
//    builder->getCustomer()->inputInformation();
//
//
//    welcome->addCustomer(builder->getCustomer());
//    customers->addCustomer(builder->getCustomer());
//
//    builder=new VipCustomerBuilder;
//    CustomerDirector::makeCustomer(builder);
//    builder->getCustomer()->inputInformation();
//
//    welcome->addCustomer(builder->getCustomer());
//    customers->addCustomer(builder->getCustomer());
//
//    Customer* customer= customers->getCustomer();
//    CommodityInformationReader* reader=customer->getCommodityReader();
//    reader->setCommodityInformation()
//    cout<<"helloworld"<<endl;

//
//int main(){
//    CustomerMain();
//}