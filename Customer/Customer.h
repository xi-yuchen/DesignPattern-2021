//
// Created by TJ_Lty on 2021/10/28.
//

#ifndef DESIGNPATTERN_2021_CUSTOMER_H
#define DESIGNPATTERN_2021_CUSTOMER_H
#include "Information.h"
#include "../Commodity/Commodity.h"
using namespace std;

class Customer {
protected:
    CustomerInformation* _info;
    VirtualCustomerInformationReader *_customer_reader{};
    VirtualCustomerInformationSetter *_customer_setter{};
    CommodityInformationReader *_commodity_reader{};
    CustomerInformationCareTaker* _careTaker;
public:
    explicit Customer(){
        _info=new CustomerInformation;
        _careTaker=new CustomerInformationCareTaker;
    }
    CustomerInformation* getInfo(){
        return this->_info;
    }
    VirtualCustomerInformationReader *getCustomerReader(){
        return this->_customer_reader;
    }
    VirtualCustomerInformationSetter *getCustomerSetter(){
        return this->_customer_setter;
    }
    CommodityInformationReader* getCommodityReader(){
        return this->_commodity_reader;
    }
    CustomerInformationCareTaker* getCareTaker(){
        return this->_careTaker;
    }

    void setCustomerInformationReader(VirtualCustomerInformationReader* customer_reader){
        _customer_reader=customer_reader;
    }

    void setCustomerInformationSetter(VirtualCustomerInformationSetter* customer_setter){
        _customer_setter=customer_setter;
    }

    void setCommodityInformationReader(CommodityInformationReader* commodity_reader){
        _commodity_reader=commodity_reader;
    }

    void inputInformation();
    void updateInformation();
    void backup();
    void rollback();
    void sendMessage(const string& message);
};

class AbstractCustomerBuilder{
public:
    virtual void setCustomerReader()=0;
    virtual void setCustomerSetter()=0;
    virtual void setCommodityReader()=0;
    virtual Customer* getCustomer()=0;
};

class NormalCustomerBuilder:public AbstractCustomerBuilder{
private:
    Customer *_customer;
public:
    NormalCustomerBuilder(){
        _customer=new Customer();
    };
    void setCustomerReader() override;
    void setCustomerSetter() override;
    void setCommodityReader() override;
    Customer* getCustomer() override;
};

class VipCustomerBuilder:public AbstractCustomerBuilder{
private:
    Customer *_customer;
public:
    VipCustomerBuilder(){
        _customer=new Customer();
    };
    void setCustomerReader() override;
    void setCustomerSetter() override;
    void setCommodityReader() override;
    Customer* getCustomer() override;
};

class CustomerDirector{
public:
    static void makeCustomer(AbstractCustomerBuilder* builder){
        builder->setCommodityReader();
        builder->setCustomerReader();
        builder->setCustomerSetter();
    }
};


class ChatRoom {
public:
    static void showMessage(Customer* customer,const string& message);
};
#endif //DESIGNPATTERN_2021_CUSTOMER_H
