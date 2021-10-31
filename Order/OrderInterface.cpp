#include "order.h"
#include "OrderInterface.h"
#include <iomanip>
#include <iostream>

using namespace std;

void OrderInterface::Initialize() {

}


void OrderInterface::CreateOrder(int customerID, map<CommodityInformation *, int> Items, float price) {
    Order *p = new Order(customerID, Items, price);
    orderlist.push_back(order);
}

void OrderInterface::AddOrder(Order *order) {
    orderlist.push_back(order);
}

void OrderInterface::RemoveOrder(string orderno)//从订单列表中移除订单
{
    vector<Order *>::iterator it;
    for (it = orderlist.begin(); it != orderlist.end(); ++it) {
        if ((*it)->getID() == orderno) {
            orderlist.erase(it);
            return;
        }
    }
}

void OrderInterface::display(int id)//订单列表的展示
{
    cout << "订单列表包含的订单有：" << endl;
    for (auto order: this->orderlist) {
        if ((*order).getcustomerid() == id) {
            cout << (*order).getID() << " ";
            (*order).Request();
            cout << endl;
        }
    }
}

