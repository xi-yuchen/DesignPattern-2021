#ifndef DESIGNPATTERN_2021_ORDERINTERFACE_H
#define DESIGNPATTERN_2021_ORDERINTERFACE_H

#include "order.h"
#include<vector>
//#include "../Basic/welcome.h"
class OrderInterface {
private:
    vector<Order*>orderlist;
    Order* order;
public:
    void Initialize();
    void CreateOrder(map<CommodityInformation *,int>Items,float price,int customerid);
    void addorder(Order &order);//在订单中增加一个订单项
    void removeorder(string orderno);//在订单中删除一个订单项
    void display(int id);
    //Order* getOrder();

};


#endif //DESIGNPATTERN_2021_ORDERINTERFACE_H
