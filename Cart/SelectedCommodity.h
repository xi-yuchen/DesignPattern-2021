//
// Created by Frederick Mo on 2021/10/22.
//

#ifndef SOFTWARE_DESIGN_PATTERNS_TASK_SELECTEDCOMMODITY_H
#define SOFTWARE_DESIGN_PATTERNS_TASK_SELECTEDCOMMODITY_H

#include "Cart.h"

#include <sstream>
#include <iostream>

using namespace std;

class Store;
class Order;
class OrderList;

class Cart;

class SelectedCommodity {
private:
    string name, type;
    int id, price, amount;
public:
    SelectedCommodity(int id, string name, string type, int price, int amount);
//    SelectedCommodity(const SelectedCommodity &commodity);
    int getID() const;
    string getName() const;
    string getType() const;
    int getPrice() const;
    int getAmount() const;
//    SelectedCommodity getThis() const { return this; }

    void setAmount(int amount);

    void add(int amount);
    bool remove(int amount);

    void display();
};

#endif //SOFTWARE_DESIGN_PATTERNS_TASK_SELECTEDCOMMODITY_H
