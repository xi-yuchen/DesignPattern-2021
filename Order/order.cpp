#include <iostream>
#include <ctime>
#include <unordered_map>
#include "order.h"
#include<vector>

using namespace std;

Order::Order(int customerID, map<CommodityInformation *, int> Items, float price) : Customerid(customerID),
                                                                                    items(Items), Price(price) {
    time_t t = time(nullptr);
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
        cout << "支付成功!" << endl;
        //delete pStateB;
    } else {
        cout << "已经支付，无法重复支付。";
    }
}

