#ifndef DESIGNPATTERN_2021_ORDERINTERFACE_H
#define DESIGNPATTERN_2021_ORDERINTERFACE_H

#include "order.h"
#include<vector>

#include "../Basic/welcome.h"

class OrderInterface {
private:
    vector<Order *> orderlist;
public:
    void CreateOrder(int customerID, map<CommodityInformation *, int> Items, float price);

    void AddOrder(Order *order);//在订单中增加一个订单项
    void RemoveOrder(string orderID);//在订单中删除一个订单项
    void display(int id);
    void displayUnpaid(int id);
    void pay();
    void MainInterface(Customer *customer);

    vector<Order *> &getOrderlist(){ return orderlist; }

    void setOrderlist(vector<Order *> &_orderlist) { orderlist = _orderlist; }

};


#endif //DESIGNPATTERN_2021_ORDERINTERFACE_H
