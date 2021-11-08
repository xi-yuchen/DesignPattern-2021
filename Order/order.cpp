#include <iostream>
#include <ctime>
#include <unordered_map>
#include "order.h"
#include<vector>

using namespace std;

//===================== Order 订单类 ========================

/**
 * 功能: 构造订单类
 * 参数：用户id,订单条目，价格
 */
Order::Order(int customerID, map<CommodityInformation *, int> Items, float price) : Customerid(customerID),items(Items), Price(price) {
    time_t t = time(0);
    char ch[64];
    strftime(ch, sizeof(ch), "%Y%m%d%H%M%S", localtime(&t)); //年-月-日 时-分-秒
    orderid.assign(ch + 2);
    State *pStateA = new ConcreteStateA();
    m_pState = pStateA;
}

/**
 * 功能: 打印order状态
 */
void Order::Request()
{
    if (m_pState) {
        m_pState->Handle(this);
    }
}

/**
 * 功能: 支付（改变order状态）
 * 如果order“未支付”改变状态为“已支付”，如果order“已支付”，提示无法重复支付
 */
void Order::pay()
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

