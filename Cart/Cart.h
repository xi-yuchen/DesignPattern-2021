//
// Created by Frederick Mo on 2021/10/21.
//

#ifndef SOFTWARE_DESIGN_PATTERNS_TASK_CART_H
#define SOFTWARE_DESIGN_PATTERNS_TASK_CART_H


#include "Commodity.h"
#include "Facade.h"
#include "Order.h"

#include "Customer.h"
#include "shopInterface.h"

#include <list>
#include <sstream>
#include <unordered_map>
#include <map>
#include <iostream>
using namespace std;


class Cart {
private:
    map<CommodityInformation*, int> commodityList;

    OrderList* orderList;
    Facade* activities;

    Customer *customer;
    CommodityInformationReader *infoReader;
    shopInterface *interface;
public:
    Cart() {
        customer = CustomerSet::getInstance()->getCustomer();
        infoReader = customer->getCommodityReader();
    }

//    void setCustomer(Customer *customer) { this->customer = customer; }

    void connectOrderList(OrderList *orderList);
    void connectActivities(Facade *activities);
    void setShopInterface(shopInterface *interface) {
        this->interface = interface;
    }

    float calculateOptionalPrice(map<CommodityInformation*, int> commodities);

    void add(int id, int amount);
    void remove(int id);
    void remove(int id, int amount);
    void display();
    void pay();
    void pay(int id);
    void pay(int id, int amount);

    static void displayCommodityInfo(CommodityInformation *commodityInfo);

    //map<CommodityInformationReader*, int> getAllCommodity() { return commodityList; }
};

#endif //SOFTWARE_DESIGN_PATTERNS_TASK_CART_H
