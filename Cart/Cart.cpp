//
// Created by Frederick Mo on 2021/10/22.
//

#include "Cart.h"

void Cart::connectOrderList(OrderList *orderList) {
    this->orderList = orderList;
}

void Cart::add(SelectedCommodity &commodity) {
    this->commodityList.push_back(commodity);
//    commodity.setCart(this);
}

void Cart::remove(int id) {
    bool hasID = false;
    for (list<SelectedCommodity>::iterator it = commodityList.begin(); it != commodityList.end(); ++it)
        if (it->getID() == id) {
            hasID = true;
            it = commodityList.erase(it);
            return;
        }
    if (!hasID)
        cout << "There is not any commodity of ID " << id << " in your shopping cart." << endl;
}

void Cart::remove(int id, int amount) {
    bool hasID = false;
    for (list<SelectedCommodity>::iterator it = commodityList.begin(); it != commodityList.end(); ++it)
        if (it->getID() == id) {
            hasID = true;
            it->remove(amount);
            if (it->getAmount() == 0)
                it = commodityList.erase(it);
            return;
        }
    if (!hasID)
        cout << "There is not any commodity of ID " << id << " in your shopping cart." << endl;
}

void Cart::display() {
    cout << "The commodities in your shopping cart:" << endl;
    cout << "ID\tName\tType\tPrice\tAmount" << endl;
    if (!commodityList.size()) {
        cout << "Your shopping cart is empty." << endl;
        return;
    }
    for (auto &commodity : commodityList)
        commodity.display();
}

void Cart::pay() {
    Order *order = new Order(this->commodityList);
    this->orderList->addOrder(*order);
    commodityList.clear();
}

void Cart::pay(int id) {
    list<SelectedCommodity> commodities;
    for (list<SelectedCommodity>::iterator it = commodityList.begin(); it != commodityList.end(); ++it)
        if (it->getID() == id) {
            commodities.push_back(*it);
            it = commodityList.erase(it);
            break;
        }
    Order *order = new Order(commodities);
    this->orderList->addOrder(*order);
}

void Cart::pay(int id, int amount) {
    list<SelectedCommodity> commodities;
    for (list<SelectedCommodity>::iterator it = commodityList.begin(); it != commodityList.end(); ++it) {
        if (it->getID() == id) {
            SelectedCommodity *commodity = new SelectedCommodity(it->getID(), it->getName(), it->getType(), it->getPrice(), it->getAmount());
            this->remove(it->getID(), amount);
            commodity->setAmount(amount);
            commodities.push_back(*commodity);
            Order *order = new Order(commodities);
            this->orderList->addOrder(*order);
            break;
        }
    }

}