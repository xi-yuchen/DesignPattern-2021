#include "../Commodity/Commodity.h"

#include<iostream>
#include<list>
#include <sstream>
#include<map>

using namespace std;

#ifndef SOFTWAREARC_ORDER_H
#define SOFTWAREARC_ORDER_H


class Order;

class State//设计模式: state
{
public:

    virtual int value() = 0;//状态标志位

    virtual void Handle(Order *pOrder) = 0;//打印状态函数
};

class ConcreteStateA : public State { //未支付状态
public:
    int value() { return 1; }

    void Handle(Order *pOrder) { cout << "未支付" << endl; }
};

class ConcreteStateB : public State { //已支付状态
public:
    int value() { return 2; }

    void Handle(Order *pOrder) { cout << "已支付" << endl; }
};

class Order { //订单类
private:
    string orderid;//订单识别号
    int amount; //订单条目数量
    map<CommodityInformation *, int> items;//订单内容(订单项)
    float Price = 0.0f; //订单总价格
    State *m_pState; //订单状态指针
    int Customerid; //订单用户id
public:
    Order(int customerID, map<CommodityInformation *, int> Items, float price);//构造函数

    int getAmount() const { return amount; }//获得当前订单条目数量

    const map<CommodityInformation *, int> &getItems() const { return items; }//获得当前订单内容

    string getID() const { return orderid; }//获得当前订单id

    int getcustomerid() { return Customerid; }//获得当前订单用户id

    void Request();//打印订单状态

    int getPayState() { return m_pState->value(); }

    void pay();//支付（改变订单状态）
};
#endif //SOFTWAREARC_ORDER_H