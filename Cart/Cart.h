//
// Created by Frederick Mo on 2021/10/21.
//

#ifndef SOFTWARE_DESIGN_PATTERNS_TASK_CART_H
#define SOFTWARE_DESIGN_PATTERNS_TASK_CART_H

/*******************************************************************************************************************
 * *****************************************************************************************************************
 * **************************** 以下是需要include的别的header，最后merge的时候需要取消注释 ********************************
 * *****************************************************************************************************************
 * *****************************************************************************************************************
 */

//#include "Commodity.h"
//#include "Facade.h"
//#include "Order.h"

/*******************************************************************************************************************
 * *****************************************************************************************************************
 * ************************************************* 引用到此结束 ****************************************************
 * *****************************************************************************************************************
 * *****************************************************************************************************************
 */

#include <list>
#include <sstream>
#include <unordered_map>
#include <map>
#include <iostream>
using namespace std;

/*******************************************************************************************************************
 * *****************************************************************************************************************
 * ********************************** 以下到116行结束是接口，merge的时候请注释掉 *****************************************
 * *****************************************************************************************************************
 * *****************************************************************************************************************
 */

class CommodityInformation {
protected:
    string name, type; // 商品名
    int ID, price; // 价格
    // Shop* shop; // 商品拥有者(店铺)
    friend class CommodityInformationReader;
public:
    CommodityInformation(int ID, string name, string type, int price) : ID(ID), name(name), type(type), price(price) {}
};

class CommodityInformationReader {
private:
    CommodityInformation* source;
public:
    CommodityInformationReader() = default;
    CommodityInformationReader(CommodityInformation* info) : source(info) { }
    void setCommodityInformation(CommodityInformation* info){
        source = info;
    }
    string getName() { return  source->name; }
    int getID() { return  source->ID; }
    string getType() { return  source->type; }
    int getPrice() { return source->price; }
//    Shop* getShop() { return source->shop; }
};


class Facade {
public:
//    virtual float CalOptionalDecision(map<CommodityInformationReader*, int> &commodityList);
    virtual void RecommendActivity(map<CommodityInformationReader*, int> &commodityList);
    float CalOptionalDecision(map<CommodityInformationReader*, int> &commodityList) {
        float price = 0;
        for (auto commodity : commodityList) {
//            cout << "The price of this commodity: " << commodity.first->getPrice() << endl;
            price += commodity.first->getPrice() * commodity.second * 0.9;
//            cout << "Current price: " << price << endl;
        }
        return price;
    }
//    void RecommendActivity(map<CommodityInformationReader*, int> &commodityList);
};

class Order {
//    list<SelectedCommodity*> commodityList;
    int id = 1123;
    float totalPrice;

    map<CommodityInformationReader*, int> commodityList;

public:
    Order(map<CommodityInformationReader*, int> commodityList, double totalPrice) : totalPrice(totalPrice) { this->commodityList = commodityList; }
    int getID() const { return id; }
    void display() {
        cout << "Order ID: " << id << endl;
        cout << "Commodities in the order:" << endl;
        for (auto commodity : commodityList) {
            cout << commodity.first->getID() << "\t" << commodity.second << endl;
        }
        cout << "Total price: " << totalPrice << endl;
    }
};

class OrderList {
    list<Order*> orderList;
//    unordered_map<CommodityInformationReader*, int> orderList;
public:
//    virtual void addOrder(Order &order); // 这里是接口
    void addOrder(Order *order) {
        orderList.push_back(order);
    }
    void display() {
        cout << "This is the list of you orders:" << endl;
        for (auto order : orderList)
            order->display();
    }
};

/*******************************************************************************************************************
 * *****************************************************************************************************************
 * ************************************************* 接口到此结束 ****************************************************
 * *****************************************************************************************************************
 * *****************************************************************************************************************
 */

class Cart {
private:
    map<CommodityInformationReader*, int> commodityList;

    OrderList* orderList;
    Facade* activities;
public:
    void connectOrderList(OrderList *orderList);
    void connectActivities(Facade *activities);

    float calculateOptionalPrice(map<CommodityInformationReader*, int> commodities);

    void add(CommodityInformationReader *commodityInfoReader, int amount);
    void remove(int id);
    void remove(int id, int amount);
    void display();
    void pay();
    void pay(int id);
    void pay(int id, int amount);

    static void displayCommodityInfo(CommodityInformationReader *commodityInfoReader);

    //map<CommodityInformationReader*, int> getAllCommodity() { return commodityList; }
};

#endif //SOFTWARE_DESIGN_PATTERNS_TASK_CART_H
