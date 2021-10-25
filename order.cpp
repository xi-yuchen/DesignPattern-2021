#include <iostream>
#include <unordered_map>
#include "order.h"
#include<vector>
using namespace std;

Commodity* Orderltem::getProductptr()
{
    return productPtr;
}
void Orderltem::display()
{
    cout<< productPtr->GetName();
    cout << "*";
    cout << quantity<<endl;
}

void Order::display()
{
    cout << "订单的内容为："<<endl;
    for(auto item:this->items)
    {
        item.display();
    }
}


void Order::additem(Orderltem& orderltem) {
    items.push_back(orderltem);
}

void Order::removeitem(int itemid) {
    vector<Orderltem>::iterator it;
    for (it = items.begin(); it != items.end(); ++it) {
        if (it->getID() == itemid) {
            it = items.erase(it);
            return;
        }
    }
}




double Order::getTotalPrice() {
    double totalPrice = 0;
    for (vector<Orderltem>::iterator it = items.begin(); it != items.end(); ++it)
        totalPrice += it->getPrice();
    return totalPrice;
}




void Order::payall() {
    state = "All payments succeeded";
}

void Order::pay(int orderid) {
    state = "Partial payment succeeded";
    
}

void Order::pay(vector<int> orderid) {
    state = "Partial payment succeeded";
}

void OrderList::addorder(Order& order)
{
    orders.push_back(order);
}

void OrderList::removeorder(int orderno)
{
    vector<Order>::iterator it;
    for (it = orders.begin(); it != orders.end(); ++it) {
        if (it->getID() == orderno) {
            it = orders.erase(it);
            return;
        }
    }
}

void OrderList::display()
{
    cout << "订单列表包含的订单有：" << endl;
    for (auto order: this->orders)
    {
        cout << order.getID() << " " << order.state << endl;
    }
}


