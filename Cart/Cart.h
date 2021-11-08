//
// Created by Frederick Mo on 2021/10/21.
//

#ifndef SOFTWARE_DESIGN_PATTERNS_TASK_CART_H
#define SOFTWARE_DESIGN_PATTERNS_TASK_CART_H

#include "../Commodity/Commodity.h"
#include "../AC_ADSystem/Facade.h"
#include "../Order/OrderInterface.h"
#include "../Customer/Customer.h"
#include "../Customer/Customers.h"
#include "../Shop/shopInterface.h"

#include <list>
#include <sstream>
//#include <unordered_map>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

/**
 * Cart/购物车：主要包含Cart类/CartCommand类/CartInterface类
 * Cart类 => 声明购物车内部的基本逻辑/供外界调用的接口
 * CartCommand类 => 为用户调用声明的命令类，用户通过构造命令类的实例间接对购物车进行操作
 * CartInterface类 => 在本项目中所有用户对于购物车的相关操作集成的界面类
 */

class Cart {
private:
    // 从shopInterface类实例获取的整个商场的商品信息
    map<CommodityInformation *, int> commodityList;
    // 与订单功能的界面类进行交互
    OrderInterface orderInterface;
    // 调用商品类的接口
    Facade *activities;
    // 存储使用购物车的用户
    Customer *customer;
    // 该用户的读取商品信息的操作
    CommodityInformationReader *infoReader;
    // 调用商店类的接口
    shopInterface interface;
public:
    Cart() {
        activities = new Facade();
    }
    // 链接订单相关的界面类
    OrderInterface &getOrderInterface(){return orderInterface;}
    void setOrderInterface(OrderInterface &_orderInterface) {orderInterface = _orderInterface;}
    // 链接活动类
    void connectActivities(Facade *activities);
    // 链接商店界面类
    void setShopInterface(shopInterface interface);
    // 获取当前用户
    void setCustomer(Customer *customer);
    // 调用活动类的接口：计算最优惠价格
    float calculateOptionalPrice(map<CommodityInformation *, int> commodities);
    // 按数量增加某ID的商品
    void add(int id, int amount);
    // 移除购物车内某ID的所有商品
    void remove(int id);
    // 按数量移除购物车内某ID的商品
    void remove(int id, int amount);
    // 展示购物车内的所有商品信息
    void display();
    // 获取所有商品的map => 提供给calculateOptionalPrice()方法调用
    const map<CommodityInformation *, int> &getCommodityList() const;
    // 获取某ID的商品的map => 提供给calculateOptionalPrice()方法调用
    const map<CommodityInformation *, int> &getCommodityList(int ID) const;
    // 获取按数量获取某ID的商品的map => 提供给calculateOptionalPrice()成员方法调用
    const map<CommodityInformation *, int> &getCommodityList(int ID, int amount) const;
    // 结算购物车内所有商品
    void pay();
    // 结算购物车内某ID的商品
    void pay(int id);
    // 按数量结算购物车内某ID的商品
    void pay(int id, int amount);
    // 展示某商品的所有信息 => 提供给display()成员方法调用
    static void displayCommodityInfo(CommodityInformation *commodityInfo);
};

#endif //SOFTWARE_DESIGN_PATTERNS_TASK_CART_H
