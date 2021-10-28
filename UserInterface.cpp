//
// Created by TJ_Lty on 2021/10/23.
//

#include "UserInterface.h"

#include <utility>
#include <iomanip>
void VirtualCustomerInformationSetter::setId(int id) {
    this->_source->_id=id;
}

void VirtualCustomerInformationSetter::setName(string name) {
    this->_source->_name=std::move(name);
}

void VirtualCustomerInformationSetter::setPhone(string phone) {
    this->_source->_phone=std::move(phone);
}

void VirtualCustomerInformationSetter::setEmail(string email) {
    this->_source->_email=std::move(email);
}

void VirtualCustomerInformationSetter::setPoints(int points) {
    this->_source->_points=points;
}

void VirtualCustomerInformationSetter::copy(CustomerInformation *source) {
    this->setId(source->_id);
    this->setName(source->_name);
    this->setPhone(source->_phone);
    this->setPoints(source->_points);
    this->setEmail(source->_email);
}

int VirtualCustomerInformationReader::getID() {
    return this->_source->_id;
}

string VirtualCustomerInformationReader::getName() {
    return this->_source->_name;
}

string VirtualCustomerInformationReader::getPhone() {
    return this->_source->_phone;
}

string VirtualCustomerInformationReader::getEmail() {
    return this->_source->_email;
}

int VirtualCustomerInformationReader::getPoints() {
    return this->_source->_points;
}

int VirtualCustomerInformationReader::getLevel() {
    int points= this->getPoints();
    if(points<100){
        return 1;
    }else if(points<500){
        return 2;
    }else if(points<1000){
        return 3;
    }else if(points<5000){
        return 4;
    }else if(points<10000){
        return 5;
    }else
        return 6;
}

void CustomerInterface::setUserInformation() {
    VirtualCustomerInformationSetter setter(this->customer->getInfo());
    string name;
    string phone;
    string email;
    cout<<"现在开始设置用户信息"<<endl;
    cout<<"请输入用户姓名:";
    cin>>name;
    setter.setName(name);
    cout<<"请输入用户手机号";
    cin>>phone;
    setter.setPhone(phone);
    cout<<"请输入用户邮箱";
    cin>>email;
    setter.setEmail(email);
    setter.setId((int)rand());
    setter.setPoints(0);
    auto* oldInfo=new CustomerInformation(*(this->customer->getInfo()));
    CustomerInformationOriginator originator{};
    originator.setState(oldInfo);
    customer->getCareTaker()->add(originator.saveStateToMemento());
}

void CustomerInterface::showUserInformation() {
    VirtualCustomerInformationReader reader(this->customer->getInfo());
    cout<<"现在开始显示用户信息"<<endl;
    cout<<setw(5)<<"ID"<<":"<<reader.getID()<<endl;
    cout<<setw(5)<<"姓名"<<":"<<reader.getName()<<endl;
    cout<<setw(5)<<"电话"<<":"<<reader.getPhone()<<endl;
    cout<<setw(5)<<"邮箱"<<":"<<reader.getEmail()<<endl;
    cout<<setw(5)<<"积分"<<":"<<reader.getPoints()<<endl;
    cout<<setw(5)<<"等级"<<":"<<reader.getLevel()<<endl;
}

void CustomerInterface::changeUserInformation() {
    VirtualCustomerInformationSetter setter(this->customer->getInfo());
    string name;
    string phone;
    string email;
    auto* oldInfo=new CustomerInformation(*(this->customer->getInfo()));
    VirtualCustomerInformationSetter oldSetter(CustomerInformation);
    cout<<"现在开始更改用户信息,如有关项目无需更改请输入/"<<endl;
    cout<<"请输入用户姓名:";
    cin>>name;
    if(name!="/")
        setter.setName(name);
    cout<<"请输入用户手机号";
    cin>>phone;
    if(phone!="/")
        setter.setPhone(phone);
    cout<<"请输入用户邮箱";
    if(email!="/")
        cin>>email;
    setter.setEmail(email);
    cout<<"修改完成"<<endl;
    if(name=="/"&&phone=="/"&&email=="/"){
        delete oldInfo;
        return;
    }
    CustomerInformationOriginator originator{};
    originator.setState(oldInfo);
    customer->getCareTaker()->add(originator.saveStateToMemento());
}

void CustomerInterface::rollback() {
    cout<<"请确认回滚：y/n";
    char check;
    cin>>check;
    if(check=='n')
        return;
    auto* originator=new CustomerInformationOriginator();
    originator->getStateFromMemento(this->customer->getCareTaker()->pop());
    VirtualCustomerInformationSetter setter(this->customer->getInfo());
    setter.copy(originator->getstate());
    cout<<"回滚完成"<<endl;
}

void CustomerInterface::mainInterface() {
    this->setUserInformation();
    cout<<endl;
    this->showUserInformation();
    cout<<endl;
    this->changeUserInformation();
    cout<<endl;
    this->showUserInformation();
    cout<<endl;
    this->rollback();
    cout<<endl;
    this->showUserInformation();
}
