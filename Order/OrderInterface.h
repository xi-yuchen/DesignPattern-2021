#ifndef DESIGNPATTERN_2021_ORDERINTERFACE_H
#define DESIGNPATTERN_2021_ORDERINTERFACE_H

#include "order.h"
#include<vector>

#include "../Welcome/welcome.h"

class OrderInterface {//订单接口类
private:
    vector<Order *> orderlist;//订单列表
public:
    void CreateOrder(int customerID, map<CommodityInformation *, int> Items, float price);

    void AddOrder(Order *order);
    void RemoveOrder(string orderID);
    void display(int id);
    void displayUnpaid(int id);
    void pay();
    void MainInterface(Customer *customer);

    vector<Order *> &getOrderlist(){ return orderlist; }

    void setOrderlist(vector<Order *> &_orderlist) { orderlist = _orderlist; }

};


#endif //DESIGNPATTERN_2021_ORDERINTERFACE_H
