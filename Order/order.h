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


    // void payall();
    // void pay(int orderid);
    // void pay(vector <int> orderid);

//    void display();

    //virtual void accept(Visitor& v) = 0;

    /*Order(Orderltem& orderltem) {
         items.push_back(orderltem);
         Price = orderltem.getPrice();
     }
     Order(vector<Commodity> commodityList, double totalPrice) {
         for (vector<Commodity>::iterator it = commodityList.begin(); it != commodityList.end(); ++it)
             this->commodityList.push_back(*it);
         this->totalPrice = totalPrice;
     }*/
};
//class OrderList {
//private:
//
//    vector<Order*>orders;
//public:
//    void AddOrder(Order &order);//在订单中增加一个订单项
//    void RemoveOrder(string orderno);//在订单中删除一个订单项
//
//    void display(int id);
//
//
//};



//class Command {
//public:
//    virtual void generatingCommand() = 0;
//};
// class PaySingleOrder : public Command {
// private:
//     Order *order;
//     int orderid;
// public:
//     PaySingleOrder(Order* order, int orderid) : order(order), orderid(orderid) {}
//     void generatingCommand() {
//         order->pay(orderid);
//     }
// };

// class PayAnyOrder : public Command {
// private:
//     Order* order;
//     vector<int> orderid;
// public:
//     PayAnyOrder(Order* order, vector<int> orderid) : order(order), orderid(orderid) {}
//     void generatingCommand() {
//         order->pay(orderid);
//     }
// };


//class AddorderTolist : public Command {
//private:
//    OrderList* list;
//    Order* order;
//public:
//    AddorderTolist(OrderList* list, Order* order) : list(list), order(order) {}
//    void generatingCommand() {
//        list->AddOrder(*order);
//    }
//};
//
//class removeorderTolist : public Command {
//private:
//    OrderList* list;
//    string orderno;
//public:
//    removeorderTolist(OrderList* list, string orderno) : list(list), orderno(orderno) {}
//    void generatingCommand() {
//        list->RemoveOrder(orderno);
//    }
//};
//
//
//
//
//
//class CommandGenerator {
//private:
//    std::list<Command*> commandList;
//    Command* command;
//public:
//    void addCommand(Command* command) {
//        commandList.push_back(command);
//    }
//    void removeCommand(Command* command) {
//        commandList.remove(command);
//    }
//    void executeCommand() {
//        for (auto command : commandList)
//            command->generatingCommand();
//    }
//};
#endif //SOFTWAREARC_ORDER_H