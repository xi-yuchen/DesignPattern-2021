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
//    Store* store;
//    Cart* cart;
public:
    SelectedCommodity(int id, string name, string type, int price, int amount);
//    SelectedCommodity(SelectedCommodity &commodity);
    int getID() const { return id; }
    string getName() const { return name; }
    string getType() const { return type; }
    int getPrice() const { return price; }
    int getAmount() const { return amount; }

    void setAmount(int amount);

    void add(int amount);
    bool remove(int amount);

//    void setCart(Cart* cart);

    void display();
};

#endif //SOFTWARE_DESIGN_PATTERNS_TASK_SELECTEDCOMMODITY_H
