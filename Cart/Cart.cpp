//
// Created by Frederick Mo on 2021/10/22.
//

#include "Cart.h"

void Cart::connectActivities(Facade *activities) {
    this->activities = activities;
}

void Cart::setShopInterface(shopInterface interface) {
    this->interface = interface;
}

void Cart::setCustomer(Customer *_customer) {
    customer = _customer;
    infoReader = customer->getCommodityReader();
}

void Cart::add(int id, int amount) {
    CommodityInformation *info = interface.addCart(id);
    if (info != nullptr) {
        // 调用该CommodityInformation(商品信息)的商品库存类的销售Command类的execute()方法，返回值为库存是否充足
        CommoditySale *sale = new CommoditySale(info);
        if (sale->execute(amount)) {
            this->commodityList[info] += amount;
        } else {
            cout << "该商品库存不足！" << endl;
        }
    } else {
        cout << "没有找到该商品！" << endl;
    }
}

void Cart::remove(int id) {
    bool hasID = false;
    for (auto it = commodityList.begin(); it != commodityList.end(); ++it) {
        // 按用户的CommodityInformationReader(读取商品信息类)读取 => 对于普通用户和VIP用户的价格不同
        CommodityInformationReader *reader = new CommodityInformationReader(*(this->infoReader));
        reader->setCommodityInformation(it->first);
        if (reader->getID() == id) {
            hasID = true;
            it = commodityList.erase(it);
            return;
        }
    }
    if (!hasID)
        cout << "您购物车中没有ID为 " << id << " 的商品！" << endl;
}

void Cart::remove(int id, int amount) {
    bool hasID = false;
    for (auto it = commodityList.begin(); it != commodityList.end(); ++it) {
        CommodityInformationReader *reader = new CommodityInformationReader(*(this->infoReader));
        reader->setCommodityInformation(it->first);
        if (reader->getID() == id) {
            hasID = true;
            if (it->second < amount) {
                cout << "您购物车中的 " << reader->getName() << " 数量不足！" << endl;
                return;
            }
            it->second -= amount;
            if (it->second == 0)
                it = commodityList.erase(it);
            return;
        }
    }

    if (!hasID)
        cout << "您购物车中没有ID为 " << id << " 的商品！" << endl;
}

void Cart::displayCommodityInfo(CommodityInformation *info) {
    CommodityInformationReader *reader = new CommodityInformationReader(info);
    cout << reader->getID() << "\t" << reader->getName() << "\t" << reader->getPrice();
}

void Cart::display() {
    cout << "您购物车中的商品：" << endl;
    cout << "ID\t名称\t价格\t数量" << endl;
    if (commodityList.empty()) {
        cout << "购物车为空！" << endl;
        return;
    }
    for (auto commodity : commodityList) {
        this->displayCommodityInfo(commodity.first);
        cout << "\t" << commodity.second << endl;
    }
}

void Cart::pay() {
    Order *order = new Order(this->customer->getCustomerReader()->getID(), this->commodityList,
                             this->calculateOptionalPrice(this->commodityList));
    OrderInterface tempOrderInterface = getOrderInterface();
    // 获取链接的订单界面的订单列表，将新订单加入其中
    vector<Order *> tempOrderList = tempOrderInterface.getOrderlist();
    tempOrderList.push_back(order);
    tempOrderInterface.setOrderlist(tempOrderList);
    setOrderInterface(tempOrderInterface);
    commodityList.clear();
}

float Cart::calculateOptionalPrice(map<CommodityInformation *, int> commodities) {
    // 调用活动子系统提供的接口
    return activities->CalOptimalDecision(commodities);
}

void Cart::pay(int id) {
    map<CommodityInformation *, int> commodities;
    for (auto it = commodityList.begin(); it != commodityList.end(); ++it) {
        CommodityInformationReader *reader = new CommodityInformationReader(*(this->infoReader));
        reader->setCommodityInformation(it->first);
        if (reader->getID() == id) {
            commodities[it->first] = it->second;
            it = commodityList.erase(it);
            break;
        }
    }
    Order *order = new Order(this->customer->getCustomerReader()->getID(), commodities,
                             this->calculateOptionalPrice(commodities));
    OrderInterface tempOrderInterface = getOrderInterface();
    vector<Order *> tempOrderList = tempOrderInterface.getOrderlist();
    tempOrderList.push_back(order);
    tempOrderInterface.setOrderlist(tempOrderList);
    setOrderInterface(tempOrderInterface);
}

void Cart::pay(int id, int amount) {
    map<CommodityInformation *, int> commodities;
    for (auto it = commodityList.begin(); it != commodityList.end(); ++it) {
        CommodityInformationReader *reader = new CommodityInformationReader(*(this->infoReader));
        reader->setCommodityInformation(it->first);
        if (reader->getID() == id) {
            if (it->second < amount) {
                cout << "您的购物车中的 " << reader->getName() << " 数量不足！" << endl;
                return;
            }
            it->second -= amount;
            commodities[it->first] = amount;
            Order *order = new Order(this->customer->getCustomerReader()->getID(), commodities,
                                     this->calculateOptionalPrice(commodities));
            OrderInterface tempOrderInterface = getOrderInterface();
            vector<Order *> tempOrderList = tempOrderInterface.getOrderlist();
            tempOrderList.push_back(order);
            tempOrderInterface.setOrderlist(tempOrderList);
            setOrderInterface(tempOrderInterface);
            break;
        }
    }

}

const map<CommodityInformation *, int> &Cart::getCommodityList() const {
    return commodityList;
}

const map<CommodityInformation *, int> &Cart::getCommodityList(int ID) const {
    map<CommodityInformation *, int> commodities;
    for (auto it = commodityList.begin(); it != commodityList.end(); ++it) {
        CommodityInformationReader *reader = new CommodityInformationReader(*(this->infoReader));
        reader->setCommodityInformation(it->first);
        if (reader->getID() == ID) {
            commodities[it->first] = it->second;
            break;
        }
    }
    if (commodities.empty())
        cout << "在您的购物车中没有找到该商品！" << endl;
    return commodities;
}

const map<CommodityInformation *, int> &Cart::getCommodityList(int ID, int amount) const {
    map<CommodityInformation *, int> commodities;
    for (auto it = commodityList.begin(); it != commodityList.end(); ++it) {
        CommodityInformationReader *reader = new CommodityInformationReader(*(this->infoReader));
        reader->setCommodityInformation(it->first);
        if (reader->getID() == ID) {
            commodities[it->first] = amount;
            break;
        }
    }
    if (commodities.empty())
        cout << "在您的购物车中没有找到该商品！" << endl;
    return commodities;
}
