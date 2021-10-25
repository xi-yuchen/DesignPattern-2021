//
// Created by Frederick Mo on 2021/10/21.
//

#ifndef SOFTWARE_DESIGN_PATTERNS_TASK_CART_H
#define SOFTWARE_DESIGN_PATTERNS_TASK_CART_H

#include "SelectedCommodity.h"

#include <list>
#include <sstream>
#include <unordered_map>
#include <iostream>

using namespace std;

//class Store;


/**
 * 感觉订单类和订单列表类按照Order和OrderList来写更符合业务逻辑，所以我就这样写了
 * 接口和那边是能对上的
 *
 * 然后对于广告类，那边对于促销活动的分类太多了，接口好多好复杂，不知道该用什么形式呈现在购物车里，所以暂时就没有对接
 * （意思就是Observer模式在这里就暂时没有写）
 */

class SelectedCommodity;

class Order {
    list<SelectedCommodity> commodityList;
//    int ID = 1123;
public:
    Order(list<SelectedCommodity> commodityList) { this->commodityList = commodityList; }
//    int getID() const { return this->ID; }
};
class OrderList {
    list<Order> orderList;
public:
    virtual void addOrder(Order &order);
//    void addOrder(Order &order) {
//        this->orderList.push_back(order);
//    }
//    void display() {
//        cout << "This is the list of you orders:" << endl;
//        for (auto &order : this->orderList)
//            cout << order.getID() << endl;
//    }
};

class Cart {
private:
    list<SelectedCommodity> commodityList;
    OrderList* orderList;
public:
    void connectOrderList(OrderList *orderList);

    void add(SelectedCommodity &commodity);
    void remove(int id);
    void remove(int id, int amount);
    // 为简化业务逻辑所以太具体的功能就暂时不实现了，只实现最基本的功能
//    void removeByName(string name);
//    void removeByType(string type);
    void display();
    void pay();
    void pay(int id);
    void pay(int id, int amount);

    // 给广告类提供的接口（虽然格式不太对），暂时不懂业务逻辑也不知道在购物车类里要怎么实现广告这个模块，就先这样搁着了
    list<SelectedCommodity> getAllCommodity() { return this->commodityList; }
//    void payByName(string name);
//    void payByType(string type);
};

#endif //SOFTWARE_DESIGN_PATTERNS_TASK_CART_H
