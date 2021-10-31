#include <iostream>
#include<time.h>
#include <unordered_map>
#include "order.h"
#include<vector>

using namespace std;


// void Order::payall() {
//     state = "All payments succeeded";
// }

// void Order::pay(int orderid) {
//     state = "Partial payment succeeded";

// }

// void Order::pay(vector<int> orderid) {
//     state = "Partial payment succeeded";
// }
Order::Order(int customerID, map<CommodityInformation *, int> Items, float price) : Customerid(customerID),
                                                                                    items(Items), Price(price) {
    time_t t = time(0);
    char ch[64];
    strftime(ch, sizeof(ch), "%Y%m%d%H%M%S", localtime(&t)); //年-月-日 时-分-秒
    orderid.assign(ch + 2);
    State *pStateA = new ConcreteStateA();
    m_pState = pStateA;
}

void Order::Request()//Order状态的打印
{
    if (m_pState) {
        m_pState->Handle(this);
    }
}

void Order::pay()//Order状态的改变
{
    int i = m_pState->value();
    if (i == 1) {
        State *pStateB = new ConcreteStateB();
        m_pState = pStateB;
        cout << i << endl;
        //delete pStateB;
    } else {
        cout << "已经支付，无法重复支付。";
    }
}

//void Order::display()//Order内容的展示
//{
//    cout<<"订单条目为："<<endl;
//     for(auto item = items.begin(); item != items.end(); item++) {
//        cout << item->first << " * " << item->second << endl;
//    }
//}



//void Order::setPrice(float price)//order价格改变
//{
//    this->Price=price;
//}

//void OrderList::addorder(Order& order)//向订单列表中加入订单
//{
//    orders.push_back(order);
//}
//
//void OrderList::removeorder(string orderno)//从订单列表中移除订单
//{
//    vector<Order>::iterator it;
//    for (it = orders.begin(); it != orders.end(); ++it) {
//        if (it->getID() == orderno) {
//            it = orders.erase(it);
//            return;
//        }
//    }
//}
//
//void OrderList::display(int id)//订单列表的展示
//{
//    cout << "订单列表包含的订单有：" << endl;
//    for (auto order: this->orders)
//    {
//        if(order.getcustomerid()==id)
//        {
//            cout << order.getID() << " " ;
//            order.Request();
//            cout<< endl;
//        }
//    }
//}


