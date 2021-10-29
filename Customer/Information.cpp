//
// Created by TJ_Lty on 2021/10/28.
//

#include "Information.h"

#include <utility>

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

void VirtualCustomerInformationSetter::copy(CustomerInformation *source,bool Deep) {
    this->setId(source->_id);
    this->setName(source->_name);
    this->setPhone(source->_phone);
    if(Deep)
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