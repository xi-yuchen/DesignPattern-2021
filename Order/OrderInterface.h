#ifndef DESIGNPATTERN_2021_ORDERINTERFACE_H
#define DESIGNPATTERN_2021_ORDERINTERFACE_H

#include "order.h"
#include<vector>
//#include "../Basic/welcome.h"
class OrderInterface {
private:
    vector<Order*> orderlist;
    Order* order;
public:
    void Initialize();
    void CreateOrder(int customerID,map<CommodityInformation *,int>Items,float price);
    void AddOrder(Order *order);//在订单中增加一个订单项
    void RemoveOrder(string orderID);//在订单中删除一个订单项
    void display(int id);

    const vector<Order *> &getOrderlist() const {return orderlist;}

    void setOrderlist(const vector<Order *> &orderlist) {OrderInterface::orderlist = orderlist;}
    //Order* getOrder();

};


#endif //DESIGNPATTERN_2021_ORDERINTERFACE_H
