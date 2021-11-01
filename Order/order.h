#include "../Commodity/Commodity.h"

#include<iostream>
#include<list>
#include <sstream>
#include<map>

using namespace std;

#ifndef SOFTWAREARC_ORDER_H
#define SOFTWAREARC_ORDER_H


class Order;

class State//状态模式
{
public:
    int p = 0;

    virtual int value() = 0;

    virtual void Handle(Order *pOrder) = 0;
};

class ConcreteStateA : public State {
public:
    int value() { return 1; }

    void Handle(Order *pOrder) { cout << "未支付" << endl; }
};

class ConcreteStateB : public State {
public:
    int value() { return 2; }

    void Handle(Order *pOrder) { cout << "已支付" << endl; }
};

class Order {
private:
    string orderid;//订单识别号
    int amount; //订单条目数量
    map<CommodityInformation *, int> items;//订单内容(订单项)
    float Price = 0.0f;
    State *m_pState;
    int Customerid;
public:
    Order(int customerID, map<CommodityInformation *, int> Items, float price);

    int getAmount() const { return amount; }

    const map<CommodityInformation *, int> &getItems() const { return items; }

    string getID() const { return orderid; }

    int getcustomerid() { return Customerid; }

    void Request();

    int getPayState() { return m_pState->value(); }

    void pay();
};
#endif //SOFTWAREARC_ORDER_H