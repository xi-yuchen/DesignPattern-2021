//
// Created by Frederick Mo on 2021/10/22.
//

#include "Cart.h"

void Cart::connectOrderList(OrderList *orderList) {
    this->orderList = orderList;
}

void Cart::connectActivities(Facade *activities) {
    this->activities = activities;
}

void Cart::add(CommodityInformationReader *commodityInfoReader, int amount) {
    commodityList[commodityInfoReader] += amount;
//    cout << "After we add " << commodityInfoReader->getName() << endl;
//    this->display();
}

void Cart::remove(int id) {
    bool hasID = false;
    for (auto it = commodityList.begin(); it != commodityList.end(); ++it)
        if (it->first->getID() == id) {
            hasID = true;
            it = commodityList.erase(it);
            return;
        }
    if (!hasID)
        cout << "There is not any commodity of ID " << id << " in your shopping cart." << endl;
}

void Cart::remove(int id, int amount) {
    bool hasID = false;
    for (auto it = commodityList.begin(); it != commodityList.end(); ++it)
        if (it->first->getID() == id) {
            hasID = true;
            if (it->second < amount) {
                cout << "The " << it->first->getName() << " in your cart is not enough." << endl;
                return;
            }
            it->second -= amount;
            // 存疑：unordered_map里value数量为0的时候会自动删除吗？
            if (it->second == 0)
                it = commodityList.erase(it);
            return;
        }
    if (!hasID)
        cout << "There is not any commodity of ID " << id << " in your shopping cart." << endl;
}

void Cart::displayCommodityInfo(CommodityInformationReader *infoReader) {
    cout << infoReader->getID() << "\t" << infoReader->getName() << "\t" << infoReader->getType() << "\t" << infoReader->getPrice();
}

void Cart::display() {
    cout << "The commodities in your shopping cart:" << endl;
    cout << "ID\tName\tType\tPrice\tAmount" << endl;
    if (commodityList.empty()) {
        cout << "Your shopping cart is empty." << endl;
        return;
    }
    for (auto commodity : commodityList) {
        this->displayCommodityInfo(commodity.first);
        cout << "\t" << commodity.second << endl;
    }
}

void Cart::pay() {
    Order *order = new Order(this->commodityList, this->calculateOptionalPrice(this->commodityList));
    this->orderList->addOrder(order);
    commodityList.clear();
}

float Cart::calculateOptionalPrice(map<CommodityInformationReader*, int> commodities) {
    return activities->CalOptionalDecision(commodities);
}

void Cart::pay(int id) {
    map<CommodityInformationReader*, int> commodities;
    for (auto it = commodityList.begin(); it != commodityList.end(); ++it)
        if (it->first->getID() == id) {
            commodities[it->first] = it->second;
            it = commodityList.erase(it);
            break;
        }
    Order *order = new Order(commodities, this->calculateOptionalPrice(commodities));
    this->orderList->addOrder(order);
}

void Cart::pay(int id, int amount) {
    map<CommodityInformationReader*, int> commodities;
    for (map<CommodityInformationReader*, int>::iterator it = commodityList.begin(); it != commodityList.end(); ++it) {
        if (it->first->getID() == id) {
//           SelectedCommodity *commodity = new SelectedCommodity((*it)->getID(), (*it)->getName(), (*it)->getType(), (*it)->getPrice(), (*it)->getAmount());
//            SelectedCommodity *commodity = new SelectedCommodity((*it)->getThis());
//            this->remove((*it)->getID(), amount);
//            commodity->setAmount(amount);
//            commodities.push_back(commodity);
            if (it->second < amount) {
                cout << "I'm sorry, you do not have enough " << it->first->getName() << " in your shopping cart." << endl;
                return;
            }
            it->second -= amount;
            commodities[it->first] = amount;
            Order *order = new Order(commodities, this->calculateOptionalPrice(commodities));
            this->orderList->addOrder(order);
            break;
        }
    }

}