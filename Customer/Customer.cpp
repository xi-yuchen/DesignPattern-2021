//
// Created by TJ_Lty on 2021/10/28.
//

#include "Customer.h"
using namespace std;

void NormalCustomerBuilder::setCustomerReader() {
    auto *source=new VirtualCustomerInformationReader(_customer->getInfo());
    _customer->setCustomerInformationReader(source);
}

void NormalCustomerBuilder::setCustomerSetter() {
    _customer->setCustomerInformationSetter(new VirtualCustomerInformationSetter(_customer->getInfo()));
}

void NormalCustomerBuilder::setCommodityReader() {
    auto *source=new CommodityInformationReader();
    _customer->setCommodityInformationReader(source);
}

Customer* NormalCustomerBuilder::getCustomer() {
    return _customer;
}

void VipCustomerBuilder::setCustomerReader() {
    auto* source=new VirtualCustomerInformationReader(_customer->getInfo());
    _customer->setCustomerInformationReader(source);
}

void VipCustomerBuilder::setCustomerSetter() {
    _customer->setCustomerInformationSetter(new VirtualCustomerInformationSetter(_customer->getInfo()));
}

void VipCustomerBuilder::setCommodityReader() {

    _customer->setCommodityInformationReader(new CommodityInformationReader());
}

Customer* VipCustomerBuilder::getCustomer() {
    return _customer;
}



void NullCustomerBuilder::setCustomerReader() {
    auto* source=new VirtualCustomerInformationReader(_customer->getInfo());
    _customer->setCustomerInformationReader(source);
}

void NullCustomerBuilder::setCustomerSetter() {
    _customer->setCustomerInformationSetter(new VirtualCustomerInformationSetter(_customer->getInfo()));
    VirtualCustomerInformationSetter* setter=_customer->getCustomerSetter();
    setter->setId(0);
    setter->setName("未登录");
    setter->setEmail("unknown");
    setter->setPhone("unknown");
    setter->setPoints(0);
}

void NullCustomerBuilder::setCommodityReader() {
    _customer->setCommodityInformationReader(new CommodityInformationReader());
}

Customer *NullCustomerBuilder::getCustomer() {
    return _customer;
}

void Customer::backup() {
    CustomerInformationOriginator originator{};
    originator.setState(_info->clone());
    this->_careTaker->add(originator.saveStateToMemento());
}

void Customer::rollback() {
    CustomerInformationOriginator originator{};
    originator.getStateFromMemento(this->_careTaker->pop());
    _customer_setter->copy(originator.getstate());
}

void ChatRoom::showMessage(Customer *customer, const string &message) {
    cout<<"["<<customer->getCustomerReader()->getName()<<"]:"<<message;
}

void Customer::sendMessage(const string &message) {
    ChatRoom::showMessage(this,message);
}

void Customer::inputInformation() {
    auto setter=this->getCustomerSetter();
    string name;
    string phone;
    string email;
    cout<<"现在开始设置用户信息"<<endl;
    cout<<"请输入用户姓名:";
    cin>>name;
    setter->setName(name);
    cout<<"请输入用户手机号";
    cin>>phone;
    setter->setPhone(phone);
    cout<<"请输入用户邮箱";
    cin>>email;
    setter->setEmail(email);
    setter->setId((int)rand());
    setter->setPoints(0);
    backup();
}

void Customer::updateInformation() {
    auto setter=this->getCustomerSetter();
    string name;
    string phone;
    string email;
    cout<<"现在开始更改用户信息,如有关项目无需更改请输入/"<<endl;
    cout<<"请输入用户姓名:";
    cin>>name;
    if(name!="/")
        setter->setName(name);
    cout<<"请输入用户手机号";
    cin>>phone;
    if(phone!="/")
        setter->setPhone(phone);
    cout<<"请输入用户邮箱";
    if(email!="/")
        cin>>email;
    setter->setEmail(email);
    cout<<"修改完成"<<endl;
    if(name=="/"&&phone=="/"&&email=="/"){
        return;
    }
    backup();
}


