#include "Commodity.h"

#include<iostream>
#include<list>
#include <sstream>
#include<vector>

using namespace std;

#ifndef SOFTWAREARC_ORDER_H
#define SOFTWAREARC_ORDER_H


class Orderltem {//订单条目类
private:
    int id;
    Commodity* productPtr;//ָ指向被定购产品的指针
    int quantity;//定购数量
    double price= quantity* (productPtr->GetPrice());
public:
    void setID(int id) { this->id = id; }
    int getID() const { return id; }
    Orderltem(Commodity* ,int);
    Commodity* getProductptr(); //获取指向被定购产品的指针
    int getquantity() const { return quantity; }

    virtual void setPrice(double price) = 0;
    double getPrice() const { return price; }

    void display();
};


class Order {
private:
    int orderid;//订单识别号
    int amount; //订单条目数量
    vector<Orderltem>items;//订单内容(订单项)        
    double Price = 0;
public:
    string state = "no";
    Order(int orderid);
    int getOrderedAmount()  { return amount; }
    void additem(Orderltem& orderltem);//在订单中增加一个订单项
    void removeitem(int itemid);
    double getTotalPrice();
    void payall();
    void pay(int orderid);
    void pay(vector <int> orderid);
    int getID() const { return orderid; }

    void display();

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
class OrderList {
private:
    vector<Order>orders;
public:
    void addorder(Order &order);//在订单中增加一个订单项
    void removeorder(int orderno);//在订单中删除一个订单项

    void display();


};



class Command {
public:
    virtual void generatingCommand() = 0;
};
class PaySingleOrder : public Command {
private:
    Order *order;
    int orderid;
public:
    PaySingleOrder(Order* order, int orderid) : order(order), orderid(orderid) {}
    void generatingCommand() {
        order->pay(orderid);
    }
};

class PayAnyOrder : public Command {
private:
    Order* order;
    vector<int> orderid;
public:
    PayAnyOrder(Order* order, vector<int> orderid) : order(order), orderid(orderid) {}
    void generatingCommand() {
        order->pay(orderid);
    }
};


class AddOneToOrder : public Command {
private:
    Order* order;
    Orderltem* orderltem;
    int num;
public:
    AddOneToOrder(Order* order, Orderltem* orderltem) : order(order), orderltem(orderltem) {}
    void generatingCommand() {
        order->additem(*orderltem);
    }
};
class removeOneFromOrder : public Command {
private:
    Order* order;
    int id;
public:
    removeOneFromOrder(Order* order, int id) : order(order), id(id) {}
    void generatingCommand() {
        order->removeitem(id);
    }
};

class AddorderTolist : public Command {
private:
    OrderList* list;
    Order* order;
public:
    AddorderTolist(OrderList* list, Order* order) : list(list), order(order) {}
    void generatingCommand() {
        list->addorder(*order);
    }
};

class removeorderTolist : public Command {
private:
    OrderList* list;
    int orderno;
public:
    removeorderTolist(OrderList* list, int orderno) : list(list), orderno(orderno) {}
    void generatingCommand() {
        list->removeorder(orderno);
    }
};

class GetTotalPriceOfOrder : public Command {
private:
    Order* order;
public:
    GetTotalPriceOfOrder(Order* order) : order(order) {}
    void generatingCommand() {
        std::cout << "The total price of commodities in your shopping cart is " << order->getTotalPrice() << "." << std::endl;
    }
};



class CommandGenerator {
private:
    std::list<Command*> commandList;
    Command* command;
public:
    void addCommand(Command* command) {
        commandList.push_back(command);
    }
    void removeCommand(Command* command) {
        commandList.remove(command);
    }
    void executeCommand() {
        for (auto command : commandList)
            command->generatingCommand();
    }
};
#endif //SOFTWAREARC_ORDER_H