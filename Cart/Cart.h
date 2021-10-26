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

/**
 * 2021.10.26 12：40修改
 * 调整了Cart中的SelectedCommodity的存储方式 => 从直接存储实例改成了存储指针
 * 因为之前列表元素存指针的时候不知道迭代器怎么调用成员函数（现在知道怎么写了）
 * 然后给广告类的接口就可以实现了，但暂时没写
 */

class SelectedCommodity;

/**
 * 构造函数不允许声明为虚函数，所以只能在Order(订单类)内部先声明一个list
 */

class Order {
    list<SelectedCommodity*> commodityList;
//    int id = 1123;
public:
    Order(list<SelectedCommodity*> commodityList) { this->commodityList = commodityList; }
//    int getID() const { return id; }
};

/**
 * OrderList(订单列表类)是一个纯抽象类(接口)
 */
class OrderList {
//    list<Order*> orderList;
public:
    virtual void addOrder(Order &order); // 这里是接口
//    void addOrder(Order *order) {
//        orderList.push_back(order);
//    }
//    void display() {
//        cout << "This is the list of you orders:" << endl;
//        for (auto order : orderList)
//            cout << (*order).getID() << endl;
//    }
};

class Cart {
private:
    list<SelectedCommodity*> commodityList;
    OrderList* orderList;
public:
    void connectOrderList(OrderList *orderList);

    void add(SelectedCommodity *commodity);
    void remove(int id);
    void remove(int id, int amount);
    void display();
    void pay();
    void pay(int id);
    void pay(int id, int amount);

    // 给广告类提供的接口（虽然格式不太对），暂时不懂业务逻辑也不知道在购物车类里要怎么实现广告这个模块，就先这样搁着了
    list<SelectedCommodity*> getAllCommodity() { return commodityList; }
};

#endif //SOFTWARE_DESIGN_PATTERNS_TASK_CART_H
