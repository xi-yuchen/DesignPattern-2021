//
// Created by TJ_Lty on 2021/10/28.
//

#ifndef DESIGNPATTERN_2021_INFORMATION_H
#define DESIGNPATTERN_2021_INFORMATION_H


#include <iostream>
#include <list>
#include <vector>
#include <stack>
using namespace std;
class CustomerInformation {
private:
    int _id;
    string _name;
    string _phone;
    string _email;
    int _points;
    friend class VirtualCustomerInformationSetter;
    friend class VirtualCustomerInformationReader;
public:
    CustomerInformation* clone(){
        auto* result=new CustomerInformation(*this);
        return result;
    }
};

class VirtualCustomerInformationSetter{
private:
    CustomerInformation* _source;
public:
    explicit VirtualCustomerInformationSetter(CustomerInformation* source):_source(source){}
    virtual void setId(int id);
    virtual void setName(string name);
    virtual void setPhone(string phone);
    virtual void setEmail(string email);
    virtual void setPoints(int points);
    //拷贝，Template Pattern
    void copy(CustomerInformation*,bool Deep=false);
};

class VirtualCustomerInformationReader{
private:
    CustomerInformation* _source;
public:
    explicit VirtualCustomerInformationReader(CustomerInformation* source):_source(source){}
    virtual int getID();
    virtual string getName();
    virtual string getPhone();
    virtual string getEmail();
    virtual int getPoints();
    virtual int getLevel();
};


//用户信息回退, Memento Pattern
class CustomerInformationMemento{
private:
    CustomerInformation* state;
public:
    explicit CustomerInformationMemento(CustomerInformation* state){
        this->state=state;
    }
    CustomerInformation* getState(){
        return state;
    }
};
class CustomerInformationOriginator{
private:
    CustomerInformation* _state;
public:
    void setState(CustomerInformation* state){
        this->_state=state;
    }
    CustomerInformation* getstate(){
        return _state;
    }
    CustomerInformationMemento* saveStateToMemento(){
        return new CustomerInformationMemento(_state);
    }
    void getStateFromMemento(CustomerInformationMemento* Memento){
        _state=Memento->getState();
    }
};
class CustomerInformationCareTaker{
private:
    stack<CustomerInformationMemento*> mementoList;
public:
    void add(CustomerInformationMemento* state){
        mementoList.push(state);
    }
    ~CustomerInformationCareTaker(){
        while(!mementoList.empty()){
            delete mementoList.top();
            mementoList.pop();
        }
    }
    CustomerInformationMemento* pop(){
        if(mementoList.size()>1){
            delete mementoList.top();
            mementoList.pop();
        }
        return mementoList.top();
    }
};




#endif //DESIGNPATTERN_2021_INFORMATION_H
